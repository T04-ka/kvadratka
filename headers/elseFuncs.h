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
bool is_OnlySpace_in_line(char *s);

bool isEqual_d(double a, double b);

Errors readDouble(char *line, double *input_d);

void clearBuffer(const int last_char);

void sortRoots(Data *roots);

bool isZero_d(double x);

Flags flagDef(char *s);


//######################CONSTANTS######################
const char STARTTEST_FLAG[] = "--test";
const char PARSE_FLAG[] = "--parse";
const char READFROMFILE_FLAG[] = "-f";

#endif
