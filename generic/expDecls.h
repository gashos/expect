/*
 * expDecls.h --
 *
 *	Declarations of functions in the platform independent public
 *	Expect API.
 *
 * RCS: $Id: expDecls.h,v 1.1.2.6 2001/11/07 10:06:30 davygrvy Exp $
 */

#ifndef _EXPDECLS
#define _EXPDECLS

/*
 * WARNING: This file is automatically generated by the $(TCLROOT)/tools/genStubs.tcl
 * script.  Any modifications to the function declarations below should be made
 * in the generic/exp.decls script.
 */

/* !BEGIN!: Do not edit below this line. */

/*
 * Exported function declarations:
 */

/* 0 */
TCL_EXTERN(int)		Expect_Init _ANSI_ARGS_((Tcl_Interp * interp));
/* Slot 1 is reserved */
/* Slot 2 is reserved */
/* 3 */
TCL_EXTERN(int)		Exp_ExpInternalCmd _ANSI_ARGS_((
				ClientData clientData, Tcl_Interp * interp, 
				int argc, char * argv[]));
/* Slot 4 is reserved */
/* 5 */
TCL_EXTERN(int)		Exp_ExitCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 6 */
TCL_EXTERN(int)		Exp_ExpContinueCmd _ANSI_ARGS_((
				ClientData clientData, Tcl_Interp * interp, 
				int argc, char * argv[]));
/* Slot 7 is reserved */
/* 8 */
TCL_EXTERN(int)		Exp_ExpPidCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 9 */
TCL_EXTERN(int)		Exp_GetpidDeprecatedCmd _ANSI_ARGS_((
				ClientData clientData, Tcl_Interp * interp, 
				int argc, char * argv[]));
/* Slot 10 is reserved */
/* 11 */
TCL_EXTERN(int)		Exp_LogFileCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 12 */
TCL_EXTERN(int)		Exp_LogUserCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 13 */
TCL_EXTERN(int)		Exp_OpenCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* Slot 14 is reserved */
/* Slot 15 is reserved */
/* Slot 16 is reserved */
/* 17 */
TCL_EXTERN(int)		Exp_SendLogCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 18 */
TCL_EXTERN(int)		Exp_SleepCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 19 */
TCL_EXTERN(int)		Exp_SpawnCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 20 */
TCL_EXTERN(int)		Exp_StraceCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 21 */
TCL_EXTERN(int)		Exp_WaitCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 22 */
TCL_EXTERN(int)		Exp_ExpVersionCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 23 */
TCL_EXTERN(int)		Exp_Prompt1Cmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 24 */
TCL_EXTERN(int)		Exp_Prompt2Cmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 25 */
TCL_EXTERN(int)		Exp_TrapCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 26 */
TCL_EXTERN(int)		Exp_SttyCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 27 */
TCL_EXTERN(int)		Exp_SystemCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 28 */
TCL_EXTERN(int)		Exp_ExpectCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int objc, 
				Tcl_Obj *CONST objv[]));
/* 29 */
TCL_EXTERN(int)		Exp_ExpectGlobalCmd _ANSI_ARGS_((
				ClientData clientData, Tcl_Interp * interp, 
				int argc, Tcl_Obj *CONST objv[]));
/* 30 */
TCL_EXTERN(int)		Exp_MatchMaxCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 31 */
TCL_EXTERN(int)		Exp_RemoveNullsCmd _ANSI_ARGS_((
				ClientData clientData, Tcl_Interp * interp, 
				int argc, char * argv[]));
/* 32 */
TCL_EXTERN(int)		Exp_ParityCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 33 */
TCL_EXTERN(int)		Exp_TimestampCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 34 */
TCL_EXTERN(int)		Exp_CloseCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 35 */
TCL_EXTERN(int)		Exp_InterpreterCmd _ANSI_ARGS_((
				ClientData clientData, Tcl_Interp * interp, 
				int argc, char * argv[]));
/* 36 */
TCL_EXTERN(int)		Exp_SendCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* 37 */
TCL_EXTERN(int)		Exp_KillCmd _ANSI_ARGS_((ClientData clientData, 
				Tcl_Interp * interp, int argc, char * argv[]));
/* Slot 38 is reserved */
/* Slot 39 is reserved */
/* 40 */
TCL_EXTERN(char *)	exp_printify _ANSI_ARGS_((char * s));
/* Slot 41 is reserved */
/* Slot 42 is reserved */
/* Slot 43 is reserved */
/* Slot 44 is reserved */
/* Slot 45 is reserved */
/* Slot 46 is reserved */
/* Slot 47 is reserved */
/* Slot 48 is reserved */
/* Slot 49 is reserved */
/* 50 */
TCL_EXTERN(void)	exp_errorlog _ANSI_ARGS_(TCL_VARARGS(char *,fmt));
/* 51 */
TCL_EXTERN(void)	exp_log _ANSI_ARGS_(TCL_VARARGS(int,force_stdout));
/* 52 */
TCL_EXTERN(void)	exp_debuglog _ANSI_ARGS_(TCL_VARARGS(char *,fmt));
/* 53 */
TCL_EXTERN(void)	exp_nflog _ANSI_ARGS_((char * buf, int force_stdout));
/* 54 */
TCL_EXTERN(void)	exp_nferrorlog _ANSI_ARGS_((char * buf, 
				int force_stdout));
/* 55 */
TCL_EXTERN(void)	exp_error _ANSI_ARGS_(TCL_VARARGS(Tcl_Interp *,interp));
/* Slot 56 is reserved */
/* Slot 57 is reserved */
/* Slot 58 is reserved */
/* Slot 59 is reserved */
/* 60 */
TCL_EXTERN(void)	exp_parse_argv _ANSI_ARGS_((Tcl_Interp * interp, 
				int argc, char ** argv));
/* 61 */
TCL_EXTERN(int)		exp_interpreter _ANSI_ARGS_((Tcl_Interp * interp));
/* 62 */
TCL_EXTERN(int)		exp_interpret_cmdfile _ANSI_ARGS_((
				Tcl_Interp * interp, Tcl_Channel cmdfile));
/* 63 */
TCL_EXTERN(int)		exp_interpret_cmdfilename _ANSI_ARGS_((
				Tcl_Interp * interp, char * filename));
/* 64 */
TCL_EXTERN(void)	exp_interpret_rcfiles _ANSI_ARGS_((
				Tcl_Interp * interp, int my_rc, int sys_rc));
/* 65 */
TCL_EXTERN(char *)	exp_cook _ANSI_ARGS_((CONST char * s, int * len));
/* Slot 66 is reserved */
/* 67 */
TCL_EXTERN(int)		exp_getpidproc _ANSI_ARGS_((void));
/* 68 */
TCL_EXTERN(Tcl_Channel)	 ExpCreateSpawnChannel _ANSI_ARGS_((
				Tcl_Interp * interp, Tcl_Channel chan));
/* 69 */
TCL_EXTERN(int)		ExpPlatformSpawnOutput _ANSI_ARGS_((
				ClientData instanceData, CONST char * bufPtr, 
				int toWrite, int * errorPtr));
/* 70 */
TCL_EXTERN(void)	exp_create_commands _ANSI_ARGS_((Tcl_Interp * interp, 
				struct exp_cmd_data * c));
/* 71 */
TCL_EXTERN(void)	exp_init_main_cmds _ANSI_ARGS_((Tcl_Interp * interp));
/* 72 */
TCL_EXTERN(void)	exp_init_expect_cmds _ANSI_ARGS_((
				Tcl_Interp * interp));
/* 73 */
TCL_EXTERN(void)	exp_init_most_cmds _ANSI_ARGS_((Tcl_Interp * interp));
/* 74 */
TCL_EXTERN(void)	exp_init_trap_cmds _ANSI_ARGS_((Tcl_Interp * interp));
/* 75 */
TCL_EXTERN(void)	exp_init_interact_cmds _ANSI_ARGS_((
				Tcl_Interp * interp));
/* 76 */
TCL_EXTERN(int)		exp_init_tty_cmds _ANSI_ARGS_((Tcl_Interp * interp));
/* Slot 77 is reserved */
/* Slot 78 is reserved */
/* 79 */
TCL_EXTERN(int)		exp_exact_write _ANSI_ARGS_((struct exp_f * f, 
				char * buffer, int rembytes));
/* Slot 80 is reserved */
/* 81 */
TCL_EXTERN(struct exp_f *) exp_f_find _ANSI_ARGS_((Tcl_Interp * interp, 
				char * spawnId));
/* 82 */
TCL_EXTERN(struct exp_f *) exp_f_new _ANSI_ARGS_((Tcl_Interp * interp, 
				Tcl_Channel chan, char * spawnId, int pid));
/* 83 */
TCL_EXTERN(int)		exp_f_new_platform _ANSI_ARGS_((struct exp_f * f));
/* 84 */
TCL_EXTERN(void)	exp_f_free _ANSI_ARGS_((struct exp_f * f));
/* 85 */
TCL_EXTERN(void)	exp_f_free_platform _ANSI_ARGS_((struct exp_f * f));
/* 86 */
TCL_EXTERN(Tcl_Channel)	 ExpCreatePairChannel _ANSI_ARGS_((
				Tcl_Interp * interp, CONST char * chanInId, 
				CONST char * chanOutId, 
				CONST char * chanName));
/* 87 */
TCL_EXTERN(int)		ExpSpawnOpen _ANSI_ARGS_((Tcl_Interp * interp, 
				char * chanId, int leaveopen));
/* 88 */
TCL_EXTERN(struct exp_f *) exp_update_master _ANSI_ARGS_((
				Tcl_Interp * interp, int opened, int adjust));
/* 89 */
TCL_EXTERN(CONST char *) exp_get_var _ANSI_ARGS_((Tcl_Interp * interp, 
				char * var));
/* 90 */
TCL_EXTERN(void)	exp_exit _ANSI_ARGS_((Tcl_Interp * interp, 
				int status));
/* 91 */
TCL_EXTERN(int)		exp_get_next_event _ANSI_ARGS_((Tcl_Interp * interp, 
				struct exp_f ** masters, int n, 
				struct exp_f ** master_out, int timeout, 
				int key));
/* 92 */
TCL_EXTERN(int)		exp_get_next_event_info _ANSI_ARGS_((
				Tcl_Interp * interp, struct exp_f * fd, 
				int ready_mask));
/* 93 */
TCL_EXTERN(int)		exp_dsleep _ANSI_ARGS_((Tcl_Interp * interp, 
				double sec));
/* 94 */
TCL_EXTERN(void)	exp_init_event _ANSI_ARGS_((void));
/* Slot 95 is reserved */
/* 96 */
TCL_EXTERN(void)	exp_event_disarm _ANSI_ARGS_((struct exp_f * f));
/* 97 */
TCL_EXTERN(void)	exp_arm_background_filehandler _ANSI_ARGS_((
				struct exp_f * f));
/* 98 */
TCL_EXTERN(void)	exp_disarm_background_filehandler _ANSI_ARGS_((
				struct exp_f * f));
/* 99 */
TCL_EXTERN(void)	exp_disarm_background_filehandler_force _ANSI_ARGS_((
				struct exp_f * f));
/* 100 */
TCL_EXTERN(void)	exp_unblock_background_filehandler _ANSI_ARGS_((
				struct exp_f * f));
/* 101 */
TCL_EXTERN(void)	exp_block_background_filehandler _ANSI_ARGS_((
				struct exp_f * f));
/* 102 */
TCL_EXTERN(void)	exp_background_filehandler _ANSI_ARGS_((
				ClientData clientData, int mask));
/* 103 */
TCL_EXTERN(void)	exp_exit_handlers _ANSI_ARGS_((ClientData clientData));
/* 104 */
TCL_EXTERN(void)	exp_close_on_exec _ANSI_ARGS_((int fd));
/* 105 */
TCL_EXTERN(int)		exp_flageq_code _ANSI_ARGS_((char * flag, 
				char * string, int minlen));
/* 106 */
TCL_EXTERN(void)	exp_tty_break _ANSI_ARGS_((Tcl_Interp * interp, 
				struct exp_f * f));
/* 107 */
TCL_EXTERN(void)	exp_close_tcl_files _ANSI_ARGS_((void));
/* 108 */
TCL_EXTERN(void)	exp_lowmemcpy _ANSI_ARGS_((char * dest, 
				CONST char * src, int n));
/* 109 */
TCL_EXTERN(void)	exp_timestamp _ANSI_ARGS_((Tcl_Interp * interp, 
				time_t * timeval, char * array));

typedef struct ExpStubHooks {
    struct ExpPlatStubs *expPlatStubs;
    struct ExpIntStubs *expIntStubs;
    struct ExpIntPlatStubs *expIntPlatStubs;
} ExpStubHooks;

typedef struct ExpStubs {
    int magic;
    struct ExpStubHooks *hooks;

    int (*expect_Init) _ANSI_ARGS_((Tcl_Interp * interp)); /* 0 */
    void *reserved1;
    void *reserved2;
    int (*exp_ExpInternalCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 3 */
    void *reserved4;
    int (*exp_ExitCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 5 */
    int (*exp_ExpContinueCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 6 */
    void *reserved7;
    int (*exp_ExpPidCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 8 */
    int (*exp_GetpidDeprecatedCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 9 */
    void *reserved10;
    int (*exp_LogFileCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 11 */
    int (*exp_LogUserCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 12 */
    int (*exp_OpenCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 13 */
    void *reserved14;
    void *reserved15;
    void *reserved16;
    int (*exp_SendLogCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 17 */
    int (*exp_SleepCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 18 */
    int (*exp_SpawnCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 19 */
    int (*exp_StraceCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 20 */
    int (*exp_WaitCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 21 */
    int (*exp_ExpVersionCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 22 */
    int (*exp_Prompt1Cmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 23 */
    int (*exp_Prompt2Cmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 24 */
    int (*exp_TrapCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 25 */
    int (*exp_SttyCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 26 */
    int (*exp_SystemCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 27 */
    int (*exp_ExpectCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int objc, Tcl_Obj *CONST objv[])); /* 28 */
    int (*exp_ExpectGlobalCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, Tcl_Obj *CONST objv[])); /* 29 */
    int (*exp_MatchMaxCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 30 */
    int (*exp_RemoveNullsCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 31 */
    int (*exp_ParityCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 32 */
    int (*exp_TimestampCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 33 */
    int (*exp_CloseCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 34 */
    int (*exp_InterpreterCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 35 */
    int (*exp_SendCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 36 */
    int (*exp_KillCmd) _ANSI_ARGS_((ClientData clientData, Tcl_Interp * interp, int argc, char * argv[])); /* 37 */
    void *reserved38;
    void *reserved39;
    char * (*exp_printify) _ANSI_ARGS_((char * s)); /* 40 */
    void *reserved41;
    void *reserved42;
    void *reserved43;
    void *reserved44;
    void *reserved45;
    void *reserved46;
    void *reserved47;
    void *reserved48;
    void *reserved49;
    void (*exp_errorlog) _ANSI_ARGS_(TCL_VARARGS(char *,fmt)); /* 50 */
    void (*exp_log) _ANSI_ARGS_(TCL_VARARGS(int,force_stdout)); /* 51 */
    void (*exp_debuglog) _ANSI_ARGS_(TCL_VARARGS(char *,fmt)); /* 52 */
    void (*exp_nflog) _ANSI_ARGS_((char * buf, int force_stdout)); /* 53 */
    void (*exp_nferrorlog) _ANSI_ARGS_((char * buf, int force_stdout)); /* 54 */
    void (*exp_error) _ANSI_ARGS_(TCL_VARARGS(Tcl_Interp *,interp)); /* 55 */
    void *reserved56;
    void *reserved57;
    void *reserved58;
    void *reserved59;
    void (*exp_parse_argv) _ANSI_ARGS_((Tcl_Interp * interp, int argc, char ** argv)); /* 60 */
    int (*exp_interpreter) _ANSI_ARGS_((Tcl_Interp * interp)); /* 61 */
    int (*exp_interpret_cmdfile) _ANSI_ARGS_((Tcl_Interp * interp, Tcl_Channel cmdfile)); /* 62 */
    int (*exp_interpret_cmdfilename) _ANSI_ARGS_((Tcl_Interp * interp, char * filename)); /* 63 */
    void (*exp_interpret_rcfiles) _ANSI_ARGS_((Tcl_Interp * interp, int my_rc, int sys_rc)); /* 64 */
    char * (*exp_cook) _ANSI_ARGS_((CONST char * s, int * len)); /* 65 */
    void *reserved66;
    int (*exp_getpidproc) _ANSI_ARGS_((void)); /* 67 */
    Tcl_Channel (*expCreateSpawnChannel) _ANSI_ARGS_((Tcl_Interp * interp, Tcl_Channel chan)); /* 68 */
    int (*expPlatformSpawnOutput) _ANSI_ARGS_((ClientData instanceData, CONST char * bufPtr, int toWrite, int * errorPtr)); /* 69 */
    void (*exp_create_commands) _ANSI_ARGS_((Tcl_Interp * interp, struct exp_cmd_data * c)); /* 70 */
    void (*exp_init_main_cmds) _ANSI_ARGS_((Tcl_Interp * interp)); /* 71 */
    void (*exp_init_expect_cmds) _ANSI_ARGS_((Tcl_Interp * interp)); /* 72 */
    void (*exp_init_most_cmds) _ANSI_ARGS_((Tcl_Interp * interp)); /* 73 */
    void (*exp_init_trap_cmds) _ANSI_ARGS_((Tcl_Interp * interp)); /* 74 */
    void (*exp_init_interact_cmds) _ANSI_ARGS_((Tcl_Interp * interp)); /* 75 */
    int (*exp_init_tty_cmds) _ANSI_ARGS_((Tcl_Interp * interp)); /* 76 */
    void *reserved77;
    void *reserved78;
    int (*exp_exact_write) _ANSI_ARGS_((struct exp_f * f, char * buffer, int rembytes)); /* 79 */
    void *reserved80;
    struct exp_f * (*exp_f_find) _ANSI_ARGS_((Tcl_Interp * interp, char * spawnId)); /* 81 */
    struct exp_f * (*exp_f_new) _ANSI_ARGS_((Tcl_Interp * interp, Tcl_Channel chan, char * spawnId, int pid)); /* 82 */
    int (*exp_f_new_platform) _ANSI_ARGS_((struct exp_f * f)); /* 83 */
    void (*exp_f_free) _ANSI_ARGS_((struct exp_f * f)); /* 84 */
    void (*exp_f_free_platform) _ANSI_ARGS_((struct exp_f * f)); /* 85 */
    Tcl_Channel (*expCreatePairChannel) _ANSI_ARGS_((Tcl_Interp * interp, CONST char * chanInId, CONST char * chanOutId, CONST char * chanName)); /* 86 */
    int (*expSpawnOpen) _ANSI_ARGS_((Tcl_Interp * interp, char * chanId, int leaveopen)); /* 87 */
    struct exp_f * (*exp_update_master) _ANSI_ARGS_((Tcl_Interp * interp, int opened, int adjust)); /* 88 */
    CONST char * (*exp_get_var) _ANSI_ARGS_((Tcl_Interp * interp, char * var)); /* 89 */
    void (*exp_exit) _ANSI_ARGS_((Tcl_Interp * interp, int status)); /* 90 */
    int (*exp_get_next_event) _ANSI_ARGS_((Tcl_Interp * interp, struct exp_f ** masters, int n, struct exp_f ** master_out, int timeout, int key)); /* 91 */
    int (*exp_get_next_event_info) _ANSI_ARGS_((Tcl_Interp * interp, struct exp_f * fd, int ready_mask)); /* 92 */
    int (*exp_dsleep) _ANSI_ARGS_((Tcl_Interp * interp, double sec)); /* 93 */
    void (*exp_init_event) _ANSI_ARGS_((void)); /* 94 */
    void *reserved95;
    void (*exp_event_disarm) _ANSI_ARGS_((struct exp_f * f)); /* 96 */
    void (*exp_arm_background_filehandler) _ANSI_ARGS_((struct exp_f * f)); /* 97 */
    void (*exp_disarm_background_filehandler) _ANSI_ARGS_((struct exp_f * f)); /* 98 */
    void (*exp_disarm_background_filehandler_force) _ANSI_ARGS_((struct exp_f * f)); /* 99 */
    void (*exp_unblock_background_filehandler) _ANSI_ARGS_((struct exp_f * f)); /* 100 */
    void (*exp_block_background_filehandler) _ANSI_ARGS_((struct exp_f * f)); /* 101 */
    void (*exp_background_filehandler) _ANSI_ARGS_((ClientData clientData, int mask)); /* 102 */
    void (*exp_exit_handlers) _ANSI_ARGS_((ClientData clientData)); /* 103 */
    void (*exp_close_on_exec) _ANSI_ARGS_((int fd)); /* 104 */
    int (*exp_flageq_code) _ANSI_ARGS_((char * flag, char * string, int minlen)); /* 105 */
    void (*exp_tty_break) _ANSI_ARGS_((Tcl_Interp * interp, struct exp_f * f)); /* 106 */
    void (*exp_close_tcl_files) _ANSI_ARGS_((void)); /* 107 */
    void (*exp_lowmemcpy) _ANSI_ARGS_((char * dest, CONST char * src, int n)); /* 108 */
    void (*exp_timestamp) _ANSI_ARGS_((Tcl_Interp * interp, time_t * timeval, char * array)); /* 109 */
} ExpStubs;

#ifdef __cplusplus
extern "C" {
#endif
extern ExpStubs *expStubsPtr;
#ifdef __cplusplus
}
#endif

#if defined(USE_EXP_STUBS) && !defined(USE_EXP_STUB_PROCS)

/*
 * Inline function declarations:
 */

#ifndef Expect_Init
#define Expect_Init \
	(expStubsPtr->expect_Init) /* 0 */
#endif
/* Slot 1 is reserved */
/* Slot 2 is reserved */
#ifndef Exp_ExpInternalCmd
#define Exp_ExpInternalCmd \
	(expStubsPtr->exp_ExpInternalCmd) /* 3 */
#endif
/* Slot 4 is reserved */
#ifndef Exp_ExitCmd
#define Exp_ExitCmd \
	(expStubsPtr->exp_ExitCmd) /* 5 */
#endif
#ifndef Exp_ExpContinueCmd
#define Exp_ExpContinueCmd \
	(expStubsPtr->exp_ExpContinueCmd) /* 6 */
#endif
/* Slot 7 is reserved */
#ifndef Exp_ExpPidCmd
#define Exp_ExpPidCmd \
	(expStubsPtr->exp_ExpPidCmd) /* 8 */
#endif
#ifndef Exp_GetpidDeprecatedCmd
#define Exp_GetpidDeprecatedCmd \
	(expStubsPtr->exp_GetpidDeprecatedCmd) /* 9 */
#endif
/* Slot 10 is reserved */
#ifndef Exp_LogFileCmd
#define Exp_LogFileCmd \
	(expStubsPtr->exp_LogFileCmd) /* 11 */
#endif
#ifndef Exp_LogUserCmd
#define Exp_LogUserCmd \
	(expStubsPtr->exp_LogUserCmd) /* 12 */
#endif
#ifndef Exp_OpenCmd
#define Exp_OpenCmd \
	(expStubsPtr->exp_OpenCmd) /* 13 */
#endif
/* Slot 14 is reserved */
/* Slot 15 is reserved */
/* Slot 16 is reserved */
#ifndef Exp_SendLogCmd
#define Exp_SendLogCmd \
	(expStubsPtr->exp_SendLogCmd) /* 17 */
#endif
#ifndef Exp_SleepCmd
#define Exp_SleepCmd \
	(expStubsPtr->exp_SleepCmd) /* 18 */
#endif
#ifndef Exp_SpawnCmd
#define Exp_SpawnCmd \
	(expStubsPtr->exp_SpawnCmd) /* 19 */
#endif
#ifndef Exp_StraceCmd
#define Exp_StraceCmd \
	(expStubsPtr->exp_StraceCmd) /* 20 */
#endif
#ifndef Exp_WaitCmd
#define Exp_WaitCmd \
	(expStubsPtr->exp_WaitCmd) /* 21 */
#endif
#ifndef Exp_ExpVersionCmd
#define Exp_ExpVersionCmd \
	(expStubsPtr->exp_ExpVersionCmd) /* 22 */
#endif
#ifndef Exp_Prompt1Cmd
#define Exp_Prompt1Cmd \
	(expStubsPtr->exp_Prompt1Cmd) /* 23 */
#endif
#ifndef Exp_Prompt2Cmd
#define Exp_Prompt2Cmd \
	(expStubsPtr->exp_Prompt2Cmd) /* 24 */
#endif
#ifndef Exp_TrapCmd
#define Exp_TrapCmd \
	(expStubsPtr->exp_TrapCmd) /* 25 */
#endif
#ifndef Exp_SttyCmd
#define Exp_SttyCmd \
	(expStubsPtr->exp_SttyCmd) /* 26 */
#endif
#ifndef Exp_SystemCmd
#define Exp_SystemCmd \
	(expStubsPtr->exp_SystemCmd) /* 27 */
#endif
#ifndef Exp_ExpectCmd
#define Exp_ExpectCmd \
	(expStubsPtr->exp_ExpectCmd) /* 28 */
#endif
#ifndef Exp_ExpectGlobalCmd
#define Exp_ExpectGlobalCmd \
	(expStubsPtr->exp_ExpectGlobalCmd) /* 29 */
#endif
#ifndef Exp_MatchMaxCmd
#define Exp_MatchMaxCmd \
	(expStubsPtr->exp_MatchMaxCmd) /* 30 */
#endif
#ifndef Exp_RemoveNullsCmd
#define Exp_RemoveNullsCmd \
	(expStubsPtr->exp_RemoveNullsCmd) /* 31 */
#endif
#ifndef Exp_ParityCmd
#define Exp_ParityCmd \
	(expStubsPtr->exp_ParityCmd) /* 32 */
#endif
#ifndef Exp_TimestampCmd
#define Exp_TimestampCmd \
	(expStubsPtr->exp_TimestampCmd) /* 33 */
#endif
#ifndef Exp_CloseCmd
#define Exp_CloseCmd \
	(expStubsPtr->exp_CloseCmd) /* 34 */
#endif
#ifndef Exp_InterpreterCmd
#define Exp_InterpreterCmd \
	(expStubsPtr->exp_InterpreterCmd) /* 35 */
#endif
#ifndef Exp_SendCmd
#define Exp_SendCmd \
	(expStubsPtr->exp_SendCmd) /* 36 */
#endif
#ifndef Exp_KillCmd
#define Exp_KillCmd \
	(expStubsPtr->exp_KillCmd) /* 37 */
#endif
/* Slot 38 is reserved */
/* Slot 39 is reserved */
#ifndef exp_printify
#define exp_printify \
	(expStubsPtr->exp_printify) /* 40 */
#endif
/* Slot 41 is reserved */
/* Slot 42 is reserved */
/* Slot 43 is reserved */
/* Slot 44 is reserved */
/* Slot 45 is reserved */
/* Slot 46 is reserved */
/* Slot 47 is reserved */
/* Slot 48 is reserved */
/* Slot 49 is reserved */
#ifndef exp_errorlog
#define exp_errorlog \
	(expStubsPtr->exp_errorlog) /* 50 */
#endif
#ifndef exp_log
#define exp_log \
	(expStubsPtr->exp_log) /* 51 */
#endif
#ifndef exp_debuglog
#define exp_debuglog \
	(expStubsPtr->exp_debuglog) /* 52 */
#endif
#ifndef exp_nflog
#define exp_nflog \
	(expStubsPtr->exp_nflog) /* 53 */
#endif
#ifndef exp_nferrorlog
#define exp_nferrorlog \
	(expStubsPtr->exp_nferrorlog) /* 54 */
#endif
#ifndef exp_error
#define exp_error \
	(expStubsPtr->exp_error) /* 55 */
#endif
/* Slot 56 is reserved */
/* Slot 57 is reserved */
/* Slot 58 is reserved */
/* Slot 59 is reserved */
#ifndef exp_parse_argv
#define exp_parse_argv \
	(expStubsPtr->exp_parse_argv) /* 60 */
#endif
#ifndef exp_interpreter
#define exp_interpreter \
	(expStubsPtr->exp_interpreter) /* 61 */
#endif
#ifndef exp_interpret_cmdfile
#define exp_interpret_cmdfile \
	(expStubsPtr->exp_interpret_cmdfile) /* 62 */
#endif
#ifndef exp_interpret_cmdfilename
#define exp_interpret_cmdfilename \
	(expStubsPtr->exp_interpret_cmdfilename) /* 63 */
#endif
#ifndef exp_interpret_rcfiles
#define exp_interpret_rcfiles \
	(expStubsPtr->exp_interpret_rcfiles) /* 64 */
#endif
#ifndef exp_cook
#define exp_cook \
	(expStubsPtr->exp_cook) /* 65 */
#endif
/* Slot 66 is reserved */
#ifndef exp_getpidproc
#define exp_getpidproc \
	(expStubsPtr->exp_getpidproc) /* 67 */
#endif
#ifndef ExpCreateSpawnChannel
#define ExpCreateSpawnChannel \
	(expStubsPtr->expCreateSpawnChannel) /* 68 */
#endif
#ifndef ExpPlatformSpawnOutput
#define ExpPlatformSpawnOutput \
	(expStubsPtr->expPlatformSpawnOutput) /* 69 */
#endif
#ifndef exp_create_commands
#define exp_create_commands \
	(expStubsPtr->exp_create_commands) /* 70 */
#endif
#ifndef exp_init_main_cmds
#define exp_init_main_cmds \
	(expStubsPtr->exp_init_main_cmds) /* 71 */
#endif
#ifndef exp_init_expect_cmds
#define exp_init_expect_cmds \
	(expStubsPtr->exp_init_expect_cmds) /* 72 */
#endif
#ifndef exp_init_most_cmds
#define exp_init_most_cmds \
	(expStubsPtr->exp_init_most_cmds) /* 73 */
#endif
#ifndef exp_init_trap_cmds
#define exp_init_trap_cmds \
	(expStubsPtr->exp_init_trap_cmds) /* 74 */
#endif
#ifndef exp_init_interact_cmds
#define exp_init_interact_cmds \
	(expStubsPtr->exp_init_interact_cmds) /* 75 */
#endif
#ifndef exp_init_tty_cmds
#define exp_init_tty_cmds \
	(expStubsPtr->exp_init_tty_cmds) /* 76 */
#endif
/* Slot 77 is reserved */
/* Slot 78 is reserved */
#ifndef exp_exact_write
#define exp_exact_write \
	(expStubsPtr->exp_exact_write) /* 79 */
#endif
/* Slot 80 is reserved */
#ifndef exp_f_find
#define exp_f_find \
	(expStubsPtr->exp_f_find) /* 81 */
#endif
#ifndef exp_f_new
#define exp_f_new \
	(expStubsPtr->exp_f_new) /* 82 */
#endif
#ifndef exp_f_new_platform
#define exp_f_new_platform \
	(expStubsPtr->exp_f_new_platform) /* 83 */
#endif
#ifndef exp_f_free
#define exp_f_free \
	(expStubsPtr->exp_f_free) /* 84 */
#endif
#ifndef exp_f_free_platform
#define exp_f_free_platform \
	(expStubsPtr->exp_f_free_platform) /* 85 */
#endif
#ifndef ExpCreatePairChannel
#define ExpCreatePairChannel \
	(expStubsPtr->expCreatePairChannel) /* 86 */
#endif
#ifndef ExpSpawnOpen
#define ExpSpawnOpen \
	(expStubsPtr->expSpawnOpen) /* 87 */
#endif
#ifndef exp_update_master
#define exp_update_master \
	(expStubsPtr->exp_update_master) /* 88 */
#endif
#ifndef exp_get_var
#define exp_get_var \
	(expStubsPtr->exp_get_var) /* 89 */
#endif
#ifndef exp_exit
#define exp_exit \
	(expStubsPtr->exp_exit) /* 90 */
#endif
#ifndef exp_get_next_event
#define exp_get_next_event \
	(expStubsPtr->exp_get_next_event) /* 91 */
#endif
#ifndef exp_get_next_event_info
#define exp_get_next_event_info \
	(expStubsPtr->exp_get_next_event_info) /* 92 */
#endif
#ifndef exp_dsleep
#define exp_dsleep \
	(expStubsPtr->exp_dsleep) /* 93 */
#endif
#ifndef exp_init_event
#define exp_init_event \
	(expStubsPtr->exp_init_event) /* 94 */
#endif
/* Slot 95 is reserved */
#ifndef exp_event_disarm
#define exp_event_disarm \
	(expStubsPtr->exp_event_disarm) /* 96 */
#endif
#ifndef exp_arm_background_filehandler
#define exp_arm_background_filehandler \
	(expStubsPtr->exp_arm_background_filehandler) /* 97 */
#endif
#ifndef exp_disarm_background_filehandler
#define exp_disarm_background_filehandler \
	(expStubsPtr->exp_disarm_background_filehandler) /* 98 */
#endif
#ifndef exp_disarm_background_filehandler_force
#define exp_disarm_background_filehandler_force \
	(expStubsPtr->exp_disarm_background_filehandler_force) /* 99 */
#endif
#ifndef exp_unblock_background_filehandler
#define exp_unblock_background_filehandler \
	(expStubsPtr->exp_unblock_background_filehandler) /* 100 */
#endif
#ifndef exp_block_background_filehandler
#define exp_block_background_filehandler \
	(expStubsPtr->exp_block_background_filehandler) /* 101 */
#endif
#ifndef exp_background_filehandler
#define exp_background_filehandler \
	(expStubsPtr->exp_background_filehandler) /* 102 */
#endif
#ifndef exp_exit_handlers
#define exp_exit_handlers \
	(expStubsPtr->exp_exit_handlers) /* 103 */
#endif
#ifndef exp_close_on_exec
#define exp_close_on_exec \
	(expStubsPtr->exp_close_on_exec) /* 104 */
#endif
#ifndef exp_flageq_code
#define exp_flageq_code \
	(expStubsPtr->exp_flageq_code) /* 105 */
#endif
#ifndef exp_tty_break
#define exp_tty_break \
	(expStubsPtr->exp_tty_break) /* 106 */
#endif
#ifndef exp_close_tcl_files
#define exp_close_tcl_files \
	(expStubsPtr->exp_close_tcl_files) /* 107 */
#endif
#ifndef exp_lowmemcpy
#define exp_lowmemcpy \
	(expStubsPtr->exp_lowmemcpy) /* 108 */
#endif
#ifndef exp_timestamp
#define exp_timestamp \
	(expStubsPtr->exp_timestamp) /* 109 */
#endif

#endif /* defined(USE_EXP_STUBS) && !defined(USE_EXP_STUB_PROCS) */

/* !END!: Do not edit above this line. */

#endif /* _EXPDECLS */
