/*
 * expDecls.h --
 *
 *	Declarations of functions in the platform independent public
 *	Expect API.
 *
 * RCS: $Id: expDecls.h,v 1.1.2.2 2001/10/28 08:56:51 davygrvy Exp $
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
EXTERN int		Expect_Init _ANSI_ARGS_((Tcl_Interp * interp));
/* 1 */
EXTERN int		Expect_SafeInit _ANSI_ARGS_((Tcl_Interp * interp));

typedef struct ExpStubHooks {
    struct ExpPlatStubs *expPlatStubs;
    struct ExpIntStubs *expIntStubs;
    struct ExpIntPlatStubs *expIntPlatStubs;
} ExpStubHooks;

typedef struct ExpStubs {
    int magic;
    struct ExpStubHooks *hooks;

    int (*expect_Init) _ANSI_ARGS_((Tcl_Interp * interp)); /* 0 */
    int (*expect_SafeInit) _ANSI_ARGS_((Tcl_Interp * interp)); /* 1 */
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
#ifndef Expect_SafeInit
#define Expect_SafeInit \
	(expStubsPtr->expect_SafeInit) /* 1 */
#endif

#endif /* defined(USE_EXP_STUBS) && !defined(USE_EXP_STUB_PROCS) */

/* !END!: Do not edit above this line. */

#endif /* _EXPDECLS */
