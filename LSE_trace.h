#ifndef _LSE_H
#define _LSE_H

#define SUCCESS 1
#define FAILURE 0

/*******************************************************************************
				Trace details
*******************************************************************************/

#define NO_TRACE       1
#define BRIEF_TRACE    2
#define DETAILED_TRACE 3

#ifdef TRACE_FEATURE
 #define LSE_TRACE(level, x)  if (g_trace_level >= level) printf x
#else
 #define LSE_TRACE(level, x) /* no definition */
#endif


/*******************************************************************************
			Function Prototypes
*******************************************************************************/

extern void set_trace_flag(int trace_val);
void lse_error(int err_level,int err_code);

/*******************************************************************************
				Error details
*******************************************************************************/

#define ERROR_NONE     1
#define ERROR_CRITICAL 2
#define ERROR_MAJOR    3
#define ERROR_MINOR    4

/* l_error is defined in lse_error.c */
#define LSE_ERROR(err_level, err_code) lse_error(err_level, err_code)

/* Error Codes */
#define ERROR_INVALID_WRITE  0
#define ERROR_INVALID_READ   1
#define ERROR_MEMORY_FAILURE 2
#define ERROR_INVALID_INPUT  3
#define ERROR_FILE_OPEN  4


#endif

