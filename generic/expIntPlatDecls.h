/* ----------------------------------------------------------------------------
 * expPlatIntDecls.h --
 *
 *	Declarations of platform specific Expect APIs.
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
 * Copyright (c) 2001 Telindustrie, LLC
 *	work by David Gravereaux <davygrvy@pobox.com> for any Win32 OS.
 *
 * ----------------------------------------------------------------------------
 * URLs:    http://expect.nist.gov/
 *	    http://expect.sf.net/
 *	    http://bmrc.berkeley.edu/people/chaffee/expectnt.html
 * ----------------------------------------------------------------------------
 * RCS: @(#) $Id: expIntPlatDecls.h,v 1.1.2.4 2001/11/07 10:06:30 davygrvy Exp $
 * ----------------------------------------------------------------------------
 */

#ifndef _EXPPLATINTDECLS
#define _EXPPLATINTDECLS


/* !BEGIN!: Do not edit below this line. */

/*
 * Exported function declarations:
 */

#ifdef __WIN32__
/* 0 */
TCL_EXTERN(DWORD)	ExpWinApplicationType _ANSI_ARGS_((
				const char * originalName, char * fullPath));
/* 1 */
TCL_EXTERN(DWORD)	ExpWinCreateProcess _ANSI_ARGS_((int argc, 
				char ** argv, HANDLE inputHandle, 
				HANDLE outputHandle, HANDLE errorHandle, 
				int allocConsole, int hideConsole, int debug, 
				int newProcessGroup, Tcl_Pid * pidPtr, 
				PDWORD globalPidPtr));
/* 2 */
TCL_EXTERN(void)	ExpWinSyslog _ANSI_ARGS_(TCL_VARARGS(DWORD,errId));
/* 3 */
TCL_EXTERN(char *)	ExpSyslogGetSysMsg _ANSI_ARGS_((DWORD errId));
/* 4 */
TCL_EXTERN(Tcl_Pid)	Exp_WaitPid _ANSI_ARGS_((Tcl_Pid pid, int * statPtr, 
				int options));
/* 5 */
TCL_EXTERN(void)	Exp_KillProcess _ANSI_ARGS_((Tcl_Pid pid));
/* 6 */
TCL_EXTERN(void)	ExpWinInit _ANSI_ARGS_((void));
#endif /* __WIN32__ */

typedef struct ExpIntPlatStubs {
    int magic;
    struct ExpIntPlatStubHooks *hooks;

#ifdef __WIN32__
    DWORD (*expWinApplicationType) _ANSI_ARGS_((const char * originalName, char * fullPath)); /* 0 */
    DWORD (*expWinCreateProcess) _ANSI_ARGS_((int argc, char ** argv, HANDLE inputHandle, HANDLE outputHandle, HANDLE errorHandle, int allocConsole, int hideConsole, int debug, int newProcessGroup, Tcl_Pid * pidPtr, PDWORD globalPidPtr)); /* 1 */
    void (*expWinSyslog) _ANSI_ARGS_(TCL_VARARGS(DWORD,errId)); /* 2 */
    TCHAR* (*expSyslogGetSysMsg) _ANSI_ARGS_((DWORD errId)); /* 3 */
    Tcl_Pid (*exp_WaitPid) _ANSI_ARGS_((Tcl_Pid pid, int * statPtr, int options)); /* 4 */
    void (*exp_KillProcess) _ANSI_ARGS_((Tcl_Pid pid)); /* 5 */
    void (*expWinInit) _ANSI_ARGS_((void)); /* 6 */
#endif /* __WIN32__ */
} ExpIntPlatStubs;

#ifdef __cplusplus
extern "C" {
#endif
extern ExpIntPlatStubs *expIntPlatStubsPtr;
#ifdef __cplusplus
}
#endif

#if defined(USE_EXP_STUBS) && !defined(USE_EXP_STUB_PROCS)

/*
 * Inline function declarations:
 */

#ifdef __WIN32__
#ifndef ExpWinApplicationType
#define ExpWinApplicationType \
	(expIntPlatStubsPtr->expWinApplicationType) /* 0 */
#endif
#ifndef ExpWinCreateProcess
#define ExpWinCreateProcess \
	(expIntPlatStubsPtr->expWinCreateProcess) /* 1 */
#endif
#ifndef ExpWinSyslog
#define ExpWinSyslog \
	(expIntPlatStubsPtr->expWinSyslog) /* 2 */
#endif
#ifndef ExpSyslogGetSysMsg
#define ExpSyslogGetSysMsg \
	(expIntPlatStubsPtr->expSyslogGetSysMsg) /* 3 */
#endif
#ifndef Exp_WaitPid
#define Exp_WaitPid \
	(expIntPlatStubsPtr->exp_WaitPid) /* 4 */
#endif
#ifndef Exp_KillProcess
#define Exp_KillProcess \
	(expIntPlatStubsPtr->exp_KillProcess) /* 5 */
#endif
#ifndef ExpWinInit
#define ExpWinInit \
	(expIntPlatStubsPtr->expWinInit) /* 6 */
#endif
#endif /* __WIN32__ */

#endif /* defined(USE_EXP_STUBS) && !defined(USE_EXP_STUB_PROCS) */

/* !END!: Do not edit above this line. */

#endif /* _EXPPLATINTDECLS */


