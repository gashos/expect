/* ----------------------------------------------------------------------------
 * expWinCommand.c --
 *
 *	Implements Windows specific parts required by expCommand.c.
 *
 * ----------------------------------------------------------------------------
 *
 * Written by: Don Libes, libes@cme.nist.gov, NIST, 12/3/90
 * 
 * Design and implementation of this program was paid for by U.S. tax
 * dollars.  Therefore it is public domain.  However, the author and NIST
 * would appreciate credit if this program or parts of it are used.
 * 
 * Copyright (c) 1997 Mitel Corporation
 *	work by Gordon Chaffee <chaffee@bmrc.berkeley.edu> for the WinNT port.
 *
 * Copyright (c) 2001-2002 Telindustrie, LLC
 * Copyright (c) 2003 ActiveState Corporation
 *	work by David Gravereaux <davygrvy@pobox.com> for any Win32 OS.
 *
 * ----------------------------------------------------------------------------
 * URLs:    http://expect.nist.gov/
 *	    http://expect.sf.net/
 *	    http://bmrc.berkeley.edu/people/chaffee/expectnt.html
 * ----------------------------------------------------------------------------
 * RCS: @(#) $Id: expWinCommand.c,v 1.1.2.1.2.12 2003/08/25 23:17:49 davygrvy Exp $
 * ----------------------------------------------------------------------------
 */

#include "expWinInt.h"

#ifdef TCL_DEBUGGER
#include "Dbg.h"
#endif

#ifdef _DEBUG
#include "MsvcDbgControl.h"
static void *dbgtoken;
#endif

/*
 * Arbitrary, but this is the port we are going to use for communicating
 * with the slave driver.
 */
#define SLAVE_PORT	9877

static void ExpSockAcceptProc _ANSI_ARGS_((ClientData callbackData,
        Tcl_Channel chan, char *address, int port));

/*
 *----------------------------------------------------------------------
 *
 * exp_f_new_platform --
 *
 *	Platform specific initialization of exp_f structure
 *
 * Results:
 *	TRUE if successful, FALSE if unsuccessful.
 *
 * Side Effects:
 *	None
 *
 *----------------------------------------------------------------------
 */

int
exp_f_new_platform(f)
    struct exp_f *f;
{
    if (EXP_NOPID != f->pid) {
	f->tclPid = (Tcl_Pid)
	    OpenProcess(PROCESS_ALL_ACCESS, FALSE, f->pid);
	TclWinAddProcess((HANDLE) f->tclPid, f->pid);
    } else {
	f->tclPid = (Tcl_Pid) INVALID_HANDLE_VALUE;
    }

    /* WIN32 only fields */
    f->over.hEvent = NULL;
    return TRUE;
}

/*
 *----------------------------------------------------------------------
 *
 * exp_f_free_platform --
 *
 *	Frees any platform specific pieces of the exp_f structure.
 *
 * Results:
 *	None
 *
 *----------------------------------------------------------------------
 */

void
exp_f_free_platform(f)
    struct exp_f *f;
{
    if (f->tclPid != (Tcl_Pid) INVALID_HANDLE_VALUE) {
	__try {
	    CloseHandle((HANDLE) f->tclPid);
	}
	__except (1) {};
    }
    if (f->over.hEvent) {
	CloseHandle(f->over.hEvent);
	f->over.hEvent = NULL;
    }
}

void
exp_close_on_exec(fd)
    int fd;
{
    /* This is here for place keeping purposes */
}

/*
 *----------------------------------------------------------------------
 *
 * exp_getpidproc --
 *
 *	Return the process id for this process
 *
 * Results:
 *	A process id
 *
 *----------------------------------------------------------------------
 */

int
exp_getpidproc()
{
    return GetCurrentProcessId();
}

#define EXP_PIPE_BASENAME "\\\\.\\pipe\\ExpectPipe"
/*
 *----------------------------------------------------------------------
 *
 * Exp_SpawnCmd --
 *
 *	Creates a new expect process id.  It normally does this
 *	by creating a new process, but it may choose to open a
 *	Tcl file id.
 *
 * Results:
 *	A standard Tcl result
 *
 * Side Effects:
 *
 * NT Notes:
 *	This whole thing is complicated immensely by NT's lack of
 *	flexibility when dealing with console processes.  For one,
 *	a console process cannot have simultaneous access to more
 *	than once console.  There is no way to call DuplicateHandle()
 *	on a console handle so a single executable could control
 *	multiple consoles.  This leaves one option: execute slave
 *	controllers who allocate their own consoles and then control.
 *	the actual slave.  The normal expect process communicates
 *	with these slave drivers over pipes.  There is still one
 *	remaining problem: consoles pop up on the screen.  When
 *	creating the subprocesses, force them to allocate new
 *	consoles, but tell them to hide the consoles.  This should
 *	make everyone happy.  For debugging, leave the consoles
 *	visible as this shows us that something is happening.  Another
 *	alternative is this: create another desktop or
 *	possibly another windows station/desktop combination, but
 *	never make the desktop the active desktop.  However, use the
 *	desktop for running the slave driver in, and then the slave
 *	console will show up in the hidden desktop.  We can control
 *	anything this way without annoying the user with all kinds
 *	of stuff popping up.
 *----------------------------------------------------------------------
 */
/* arguments are passed verbatim to execvp() */
/*ARGSUSED*/

int
Exp_SpawnCmd(ClientData clientData,Tcl_Interp *interp,int argc, CONST char **argv)
{
    HANDLE hSlaveDrv = INVALID_HANDLE_VALUE;	/* Handle to communicate with slave driver */
    Tcl_Pid slaveDrvPid;	/* Process id of the slave */
    BOOL bRet;
    DWORD dwRet;
    DWORD count;
    int echo = TRUE;
    CONST char **a;
    CONST char *argv0 = argv[0];
    char slaveName[50];		/* Used to set 'spawn_out(slave,name)' */
    static int slaveId = 1;	/* Start at one because console0 is expect's */
    UCHAR buf[8];		/* enough space for child status info */
    WCHAR execPath[MAX_PATH];   /* needed for unicode space. */
    Tcl_DString slavePath;
    Tcl_DString slaveDrvPath;
    struct exp_f *f;
    HANDLE hEvent = NULL;
    OVERLAPPED over;
    DWORD globalPid;
    Tcl_Channel channel = NULL;
    Tcl_Channel channel2 = NULL;
    Tcl_Channel spawnChan = NULL;
    TclFile masterRFile;
    TclFile masterWFile;
    CONST char *openarg = NULL;
    int leaveopen = 0;
    CONST char *val;
    int hide;
    int debug;
    CONST char **nargv = NULL;
    int i, j;
    int usePipes = 0;
    int useSocket = 0;

    char pipeName[100];
    static int pipeNameId = 0;
    char sockPort[10];
    static int sockPortInc = 0;

    /*
     * Need to create a structure with hEvent, overlapped, etc
     * for each pipe we handle
     */

    argc--; argv++;

    for (;argc>0;argc--,argv++) {
	if (streq(*argv,"-nottyinit")) {
	    exp_error(interp, "%s -nottyinit is unsupported on NT", argv0);
	    return TCL_ERROR;
	} else if (streq(*argv,"-nottycopy")) {
	    exp_error(interp, "%s -nottycopy is unsupported on NT", argv0);
	    return TCL_ERROR;
	} else if (streq(*argv,"-noecho")) {
	    echo = FALSE;
	} else if (streq(*argv,"-console")) {
	    exp_error(interp, "%s -console is unsupported on NT", argv0);
	    return TCL_ERROR;
	} else if (streq(*argv,"-pty")) {
	    exp_error(interp, "%s -pty is unsupported on NT", argv0);
	    return TCL_ERROR;
	} else if (streq(*argv,"-open")) {
	    /*
	     * This allows us to treat an open file id as an
	     * expect process id.  We should be eventually be able
	     * to support this under NT.
	     */
	    if (argc < 2) {
		exp_error(interp,"usage: %s -open file-identifier", argv0);
		return TCL_ERROR;
	    }
	    openarg = argv[1];
	    argc--; argv++;
	} else if (streq(*argv,"-leaveopen")) {
	    /*
	     * This leaves the file id open when the process id
	     * gets closed.  We should be able to eventually support
	     * this under NT.
	     */
	    if (argc < 2) {
		exp_error(interp,"usage: %s -leaveopen file-identifier", argv0);
		return TCL_ERROR;
	    }
	    openarg = argv[1];
	    leaveopen = TRUE;
	    argc--; argv++;
	} else if (streq(*argv,"-ignore")) {
	    if (argc < 2) {
		exp_error(interp,"usage: %s -ignore signal", argv0);
		return TCL_ERROR;
	    }
	    argc--; argv++;
	    exp_error(interp, "%s -ignore is unsupported on NT", argv0);
	    return TCL_ERROR;
	} else if (streq(*argv,"-pipes")) {
	    usePipes = 1;
	} else if (streq(*argv,"-socket")) {
	    useSocket = 1;
	} else break;
    }

    if (openarg) {
	if (argc != 0) {
	    exp_error(interp,"usage: -[leave]open [fileXX]");
	    return TCL_ERROR;
	}
	if (echo) exp_log(0,"%s [open ...]\r\n",argv0);

	return ExpSpawnOpen(interp, openarg, leaveopen);
    }

    if (!openarg && (argc == 0)) {
	exp_error(interp,"usage: %s [spawn-args] program [program-args]",
		  argv0);
	return(TCL_ERROR);
    }


    Tcl_ReapDetachedProcs();

    if (echo) {
	exp_log(0,"%s ",argv0);
	for (a = argv;*a;a++) {
	    exp_log(0,"%s ",*a);
	}
	exp_nflog("\r\n",0);
    }

    /* console0 would be the parent process console */
    sprintf(slaveName, "console%d", slaveId++);
    Tcl_SetVar2(interp,EXP_SPAWN_OUT,"slave,name",slaveName,0);

    /*
     * Time to create our subprocess.  slavedrv.exe is ALWAYS in the same
     * directory alongside the extension dll.
     */

    Tcl_DStringInit(&slaveDrvPath);
    (*expWinProcs->getModuleFileNameProc)(expDllInstance,
	    (LPTSTR) execPath, MAX_PATH);
    val = Tcl_WinTCharToUtf((LPTSTR)execPath, -1, &slaveDrvPath);
    for (i = Tcl_DStringLength(&slaveDrvPath) - 1; i > 0; i--) {
	if (*(val+i) == '\\') {
	    Tcl_DStringSetLength(&slaveDrvPath, i+1);
	    Tcl_DStringAppend(&slaveDrvPath, "slavedrv.exe", 12);
	    break;
	}
    }

    Tcl_DStringInit(&slavePath);
    dwRet = ExpWinApplicationType(argv[0], &slavePath);
    if (dwRet == EXP_APPL_NONE) {
	errno = ENOENT;
	exp_error(interp, "couldn't execute \"%s\": %s",
		  argv[0],Tcl_PosixError(interp));
	return TCL_ERROR;
    }

    /*
     * The whole point of this is that named pipes don't exist on Win95,
     * so we have the sockets as a backup communications protocol.  The user
     * can specify that they get sockets at all times if they want.
     */
    if (useSocket == 0) {
	sprintf(pipeName, "%s%08x%08x", EXP_PIPE_BASENAME,
		GetCurrentProcessId(), pipeNameId++);
	hSlaveDrv = CreateNamedPipe(pipeName,
				    PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,
				    PIPE_TYPE_BYTE | PIPE_WAIT, 1, 8192, 8192,
				    20000, NULL);
    }

    /*
     * If we cannot create the named pipe (or if we have been told to use
     * sockets for communications at this level), try opening a socket.
     */
    if (hSlaveDrv == INVALID_HANDLE_VALUE) {
	channel2 = NULL;
	for (i = 0; i < 50 && channel2 == NULL; i++) {
	    channel2 = Tcl_OpenTcpServer(interp, 
					 SLAVE_PORT + sockPortInc, 
					 NULL, 
					 ExpSockAcceptProc, 
					 (ClientData) &channel);
	    sprintf(sockPort, "%d", SLAVE_PORT + sockPortInc);
	    sockPortInc++;
	}
	useSocket = 1;
    }

    if (channel2 == NULL && hSlaveDrv == INVALID_HANDLE_VALUE ) {
	exp_debuglog("CreateNamedPipe failed: error=0x%08x\r\n", GetLastError());
	exp_debuglog("socket failed: error=0x%08x\r\n", GetLastError());
	TclWinConvertError(GetLastError());
	exp_error(interp, "unable to create either named pipe or socket: %s",
		  Tcl_PosixError(interp));
	goto end;
    }

    hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (hEvent == NULL) {
	exp_debuglog("CreateEvent failed: error=0x%08x\r\n", GetLastError());
	TclWinConvertError(GetLastError());
	exp_error(interp, "unable to create event: %s",
		  Tcl_PosixError(interp));
	goto end;
    }

    val = exp_get_var(interp, "exp_nt_debug");
    if (val) {
	if (! Tcl_GetBoolean(interp, val, &debug) == TCL_OK) {
	    Tcl_ResetResult(interp);
	    debug = 1;
	}
    } else {
	debug = 0;
    }

    nargv = (char **) ckalloc(sizeof(char *) * (argc+4));
    nargv[0] = Tcl_DStringValue(&slaveDrvPath);

    if (!useSocket) {
	nargv[1] = pipeName;
    } else {
	nargv[1] = sockPort;
    }
    nargv[2] = usePipes ? "1" : "0";
    nargv[3] = debug    ? "1" : "0";
    j = 4;
    nargv[j++] = Tcl_DStringValue(&slavePath);
    for (i = 1; i < argc; i++, j++) {
	nargv[j] = argv[i];
    }
    argc = j;

#ifdef _DEBUG
    /*
     * When the Expect extension is running in a debugger,
     * print the commandline to the debugger's output window.
     * This is a feature of the OS.
     *
     * >>>>[ And don't leave this stuff in the retail build! ]<<<<
     */
    if (IsDebuggerPresent()) {
	Tcl_DString cmdLine;

	OutputDebugString("spawndrv.exe args: ");
	Tcl_DStringInit(&cmdLine);
	/* This quotes the strings properly. */
	BuildCommandLine(nargv[0], argc, nargv, &cmdLine);
	(*expWinProcs->outputDebugStringProc)((LPCTSTR)Tcl_DStringValue(&cmdLine));
	OutputDebugString("\n");

#   ifdef _MSC_VER
	/*
	 * Launch a new instance of MSVC++ with the right project file, if one
	 * does not already exist.  And tell MSVC++ to run it in the debuger.
	 */
	globalPid = MsvcDbg_Launch(
		"D:\\expect_wslive\\expect_win32_take2\\win\\slavedrv.dsp",
		&cmdLine, &dbgtoken);
#   else
#	error "Need Debugger control for this IDE"
#   endif

    } else {
#endif
	hide = !debug;
	dwRet = ExpWinCreateProcess(argc, nargv, NULL, NULL, NULL,
				 TRUE, hide, FALSE, FALSE,
				 &slaveDrvPid, &globalPid);
	if (dwRet != 0) {
	    TclWinConvertError(dwRet);
	    exp_error(interp, "couldn't execute \"%s\": %s",
		  argv[0],Tcl_PosixError(interp));
	    goto end;
	}

	/*
	 * Until we use the process handle for something, close it
	 */
	CloseHandle((HANDLE) slaveDrvPid);
#ifdef _DEBUG
    }
#endif

    /*
     * Wait for connection with the slave driver
     */
    if (!useSocket) {
	ZeroMemory(&over, sizeof(over));
	over.hEvent = hEvent;
	bRet = ConnectNamedPipe(hSlaveDrv, &over);
	if (bRet == FALSE) {
	    dwRet = GetLastError();
	    if (dwRet == ERROR_PIPE_CONNECTED) {
		;
	    } else if (dwRet == ERROR_IO_PENDING) {
		dwRet = WaitForSingleObject(hEvent, 10000 /* XXX 30000*/);
		if (dwRet != WAIT_OBJECT_0) {
		    TclWinConvertError(dwRet);
		    exp_error(interp, "\"%s\" did not connect to server pipe: %s",
			      Tcl_DStringValue(&slaveDrvPath), Tcl_PosixError(interp));
		    goto end;
		}
		bRet = GetOverlappedResult(hSlaveDrv, &over, &count, FALSE);
		if (bRet == FALSE) {
		    TclWinConvertError(GetLastError());
		    exp_error(interp, "\"%s\" did not connect to server pipe: %s",
			      Tcl_DStringValue(&slaveDrvPath), Tcl_PosixError(interp));
		    goto end;
		}
	    } else {
		exp_error(interp, "\"%s\" did not connect to server pipe: %s",
			  Tcl_DStringValue(&slaveDrvPath), Tcl_PosixError(interp));
		goto end;
	    }
	}
    } else {
	while (channel == NULL) {
	    Tcl_DoOneEvent(TCL_FILE_EVENTS);
	}
	/*
	 * At this point, 'channel' should point to a valid channel that
	 * we can use for I/O.
	 * We aren't interested in listening for more connections, so we
	 * can close that channel now.
	 */
	Tcl_Close(interp, channel2);
    }

    /*
     * wait for slave driver to initialize before allowing user to send to it
     */
    exp_debuglog("parent: waiting for sync bytes\r\n");

    if (!useSocket) {
	ResetEvent(hEvent);
	bRet = ReadFile(hSlaveDrv, buf, 8, &count, &over);
	if (bRet == FALSE) {
	    dwRet = GetLastError();
	    if (dwRet == ERROR_IO_PENDING) {
		dwRet = WaitForSingleObject(hEvent, 50000);  /* 50 seconds */
		if (dwRet != WAIT_OBJECT_0) {
		    TclWinConvertError(dwRet);
		    exp_error(interp, "\"%s\" did not synchronize with master: %s",
			      Tcl_DStringValue(&slaveDrvPath), Tcl_PosixError(interp));
		    goto end;
		}
		bRet = GetOverlappedResult(hSlaveDrv, &over, &count, FALSE);
		if (bRet == FALSE) {
		    TclWinConvertError(GetLastError());
		    exp_error(interp, "\"%s\" did not synchronize with master: %s",
			      Tcl_DStringValue(&slaveDrvPath), Tcl_PosixError(interp));
		    goto end;
		}
	    }
	}
    } else {
	/*
	 * We are reading data from the socket channel right away, so
	 * we need to set the mode to binary now.  If we are using
	 * named pipes on NT, the channel doesn't exist yet, and we
	 * would instead read directly from the pipe.
	 */
	Tcl_SetChannelOption(interp, channel, "-translation", "binary");
	count = Tcl_Read(channel, buf, 8);
	if( count != 8 )
	{
	    exp_error(interp, "Synchronized with wrong number of bytes %d",
		      count);
	    goto end;
	}
    }

    dwRet = buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
    if (dwRet != 0) {
	TclWinConvertError(dwRet);
	exp_error(interp, "couldn't execute \"%s\": %s",
		  argv[0],Tcl_PosixError(interp));
	goto end;
    }
    globalPid = buf[4] | (buf[5] << 8) | (buf[6] << 16) | (buf[7] << 24);

    if (!useSocket) {
	HANDLE dupe;

	masterRFile = tclWinMakeFileProc(hSlaveDrv);

	/*
	 *  We need to make a duplicate, because the handles are closed
	 *  seperately by the core.
	 */

	DuplicateHandle(GetCurrentProcess(), hSlaveDrv,
		GetCurrentProcess(), &dupe, 0, FALSE,
		DUPLICATE_SAME_ACCESS);
	masterWFile = tclWinMakeFileProc(dupe);

	channel = TclpCreateCommandChannel(masterRFile, masterWFile, NULL, 0, NULL);
    }

    if (channel == NULL) {
	goto end;
    }
    Tcl_SetChannelOption(interp, channel, "-blocking", "0");
    Tcl_SetChannelOption(interp, channel, "-buffering", "none");
    Tcl_SetChannelOption(interp, channel, "-translation", "binary");

    spawnChan = ExpCreateSpawnChannel(interp, channel);

    f = exp_f_new(interp, spawnChan, NULL, globalPid);
    f->over.hEvent = hEvent;
    f->channel = spawnChan;
    f->Master = channel;

    exp_debuglog("parent: now unsynchronized from child\r\n");

    /* tell user id of new process */
    Tcl_SetVar(interp, EXP_SPAWN_ID_VARNAME, Tcl_GetChannelName(spawnChan), 0);

    Tcl_RegisterChannel(interp, spawnChan);

    sprintf(interp->result,"%d",(int) globalPid);
    exp_debuglog("spawn: returns {%s}\r\n",Tcl_GetStringResult(interp));
    ckfree((char *) nargv);
    return(TCL_OK);

end:
    Tcl_DStringFree(&slavePath);
    if (hSlaveDrv != NULL) CloseHandle(hSlaveDrv);
    if (hEvent != NULL) CloseHandle(hEvent);
    if (nargv != NULL) ckfree((char *) nargv);
    return TCL_ERROR;
}

/*
 *----------------------------------------------------------------------
 *
 * Exp_KillCmd --
 *
 *	Implements the 'kill' and 'exp_kill' commands.  There were
 *	not in the Unix version of expect, but since there is no
 *	kill command on NT (well, at least not by default), this
 *	gives us a way to kill a slave.  The argument is the signal
 *	number to send to the subprocess.  On NT, this is interpreted
 *	interpret a bit differently than on Unix.  For a signal of 2,
 *	a CTRL-C is sent to the subprocess.  For a signal of 3, a
 *	CTRL-BREAK is sent to the subprocess.  All other signals cause
 *	the subprocess to be directly terminated.
 *
 * Results:
 *	A standard TCL result
 *
 * Side Effects:
 *	A process may be killed
 *
 *----------------------------------------------------------------------
 */

/*ARGSUSED*/

int
Exp_KillCmd(ClientData clientData,Tcl_Interp *interp,int argc, CONST char **argv)
{
    struct exp_f *f;
    CONST char *chanId = NULL;
    CONST char *argv0 = argv[0];
    int signal = 9;
    char buf[2];
    int msg;

    argc--; argv++;

    for (;argc>0;argc--,argv++) {
	if (streq(*argv,"-i")) {
	    argc--; argv++;
	    if (!*argv) {
		exp_error(interp,"usage: -i spawn_id");
		return TCL_ERROR;
	    }
	    chanId = *argv;
	} else break;
    }

    if (argc > 0) {
	if (Tcl_GetInt(interp, argv[0], &signal) != TCL_OK) {
	    return TCL_ERROR;
	}
    }

    if (chanId == NULL) {
	f = exp_update_master(interp,0,0);
    } else {
	f = exp_chan2f(interp, chanId, 1, 0, argv0);
    }
    if (f == NULL) {
	return(TCL_ERROR);
    }

    if (f->Master == NULL) {
	Tcl_AppendResult(interp, "cannot kill ", f->spawnId,
			 ": not a spawned process", NULL);
	return TCL_ERROR;
    }

    switch (signal) {
    case 2:
	/* Send Ctrl-C */
	msg = EXP_KILL_CTRL_C;
	break;
    case 3:
	/* Send Ctrl-Break */
	msg = EXP_KILL_CTRL_BREAK;
	break;
    default:
	/* Terminate subprocess with prejudice */
	msg = EXP_KILL_TERMINATE;
	break;
    }

    buf[0] = EXP_SLAVE_KILL;
    buf[1] = msg;

    /*
     * The Master holds the direct line of communication to
     * the slave driver.  We don't want to go through the toplevel
     * channel because that assumes that all writes are data while
     * this is really a command.
     */

    Tcl_Write(f->Master, buf, 2);

    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * ExpSockAcceptProc --
 *
 *	For doing socket communication with slave driver.  This
 *	routine is called when the slave driver connects up to us.
 *
 * Results:
 *	None
 *----------------------------------------------------------------------
 */

static void
ExpSockAcceptProc(callbackData, chan, address, port)
     ClientData callbackData;
     Tcl_Channel chan;
     char *address;
     int port;
{
    Tcl_Channel * ptr;

    /*
     * We do a couple of things here.   First we save the pointer to
     * the actual channel that we use for read/write, and secondly we set
     * the event that is used for synchronization.
     */
    ptr = (Tcl_Channel *) callbackData;
    *ptr = chan;
    return;
}
