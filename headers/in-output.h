#ifndef INOUTPUT_H
#define INOUTPUT_H

//######################INCLUDES#######################
#include "elseFuncs.h"
#include "colors.h"

#include <stdarg.h>
#include <time.h>
#include <unistd.h>
  

//######################DEFINES########################
#define MAXLEN 10000
#define PRINTSIZE 1000
#define STOPSYMB 'q'

//#################INITIALIZATION######################
//----------------------------------------------------------------------------
/// Prints result of equations solving
///
/// @param[in]    roots    "Data" structure with solving results
///
//----------------------------------------------------------------------------

void printRes(Data roots);



//----------------------------------------------------------------------------
/// Prints error message
///
/// @param[in]    error      Type of error
///
//----------------------------------------------------------------------------

void printErrors(Errors error);



//----------------------------------------------------------------------------
/// Reads input parametrs from stdin
///
/// @param[in]    type_param    Type of parametr (A, B, C)
/// @param[out]   param         Pointer to var that parametr need to be written in
///
/// @return true if param has written,
///         false if user stoped input (Ctrl + D)
///
/// @note Prints prints error message if input was wrong and
///       repeats input until correct parametr will be written.
///
//----------------------------------------------------------------------------

bool readParam(const char type_of_param, double *param);



//----------------------------------------------------------------------------
/// Reads user's answear about continuation of program
///
/// @returns true if user wanted to continue program,
///          false if wanted to stop
///
//----------------------------------------------------------------------------

bool readAnswear();



//----------------------------------------------------------------------------
/// Reads line from input stream
///
/// @param[in]     mxlen   Maximum possible len of input line
/// @param[out]    s     String where symbols from input are written
///
/// @return Lenth of entered string
///
/// @note Puts '\0' on every string end
//----------------------------------------------------------------------------

int get_line(char *s, int maxlen);



//-------------------------------------------------------------------------
/// Reads line from file
///
/// @param[in]     mxlen   Maximum possible len of input line
/// @param[out]    s     String where symbols from input are written
///
/// @return Lenth of entered string
///
/// @note Puts '\0' on every string end
///
//-------------------------------------------------------------------------

int get_lineF(FILE *file, char *s, int maxlen);



//--------------------------------------------------------------------------
/// Makes the slow output
///
/// @param[in]   format      A string with output format
/// @param[in]   ...         Variables for output
///
/// @note Puts every symbol with delation, defined in header file.
///
//-------------------------------------------------------------------------

void slowPrint(const char *format, ...);


//###################CONSTANTS#########################
static const timespec SLEEPTIME = {.tv_sec = 0, .tv_nsec = (int) 1E7};

#endif
