#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//###############INCLUDES##############################
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "enums.h"
#include "structures.h"


//######################ENUMS##########################
//-----------------------------------------------------
/// Enumeration with type of input flags
///
//-----------------------------------------------------

enum Flags {
    TEST = 0,
    PARSE = 1,
    WRONG = -1
};


//######################DEFINES########################
#define BORDER 0.000001


//#################INITIALIZATION######################
//------------------------------------------------------------------
/// Checks is only space in string
///
/// @param[in]    s     string
///
/// @return true if string is empty,
///         false if not.
///
//------------------------------------------------------------------

bool is_OnlySpace_in_line(char *s);



//------------------------------------------------------------------
/// Checks the equality of two Double numbers
///
/// @param[in]    a     First double
/// @param[in]    b     Second double
///
/// @return true if numbers are equal
///     and false if not
///
/// @note Compares double numbers with accuracy BORDER,
///       defined in header file
///
//------------------------------------------------------------------

bool isEqual_d(double a, double b);


//------------------------------------------------------------------
/// Checks the correctness of input
///
/// @param[in]    line            Input string
/// @param[out]   input_d    The pointer to double read
///
/// @return INPUT_ERROR if input was wrong,
///         EMPTY_INPUT if input was empty,
///         NO_ERROR if input was correct;
///
/// @note A correct input is one number of type Double
//------------------------------------------------------------------

Errors readDouble(char *line, double *input_d);



//------------------------------------------------------------------
/// Clears input buffer, if needed
///
/// @param[in]    last_char   The last char written to buffer
///
/// @note Clears buffer until '\\n' is written
///
//------------------------------------------------------------------

void clearBuffer(const int last_char);



//------------------------------------------------------------------
/// Sorts roots in structure
///
/// @param[in]    roots      Pointer on "Data" structure
/// @param[out]   roots      Changed value of roots right in structure
///
//------------------------------------------------------------------

void sortRoots(Data *roots);



//------------------------------------------------------------------
/// Checks is double equal to zero
///
/// @param[in]    x     Double number
///
/// @return true if x = 0,
///         false if x != 0.
///
//------------------------------------------------------------------

bool isZero_d(double x);



//------------------------------------------------------------------
/// Defines flag entered in string
///
/// @param[in]    s     Input string
///
/// @return TEST if test flag was entered,
///         PARSE if parse flag was entered,
///         WRONG if wrong flag was entered.
///
//------------------------------------------------------------------

Flags flagDef(char *s);

//######################CONSTANTS######################
const char STARTTEST_FLAG[] = "--test";
const char PARSE_FLAG[] = "--parse";
const char READFROMFILE_FLAG[] = "-f";

#endif
