#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

//###############INCLUDES#######################
#include <stdio.h>

#include "colors.h"
#include "enums.h"
#include "sqSolve.h"
#include "functions.h"
#include "in-output.h"



#define MAXLEN 10000
#define MAXFLEN 100
#define EXPECTED "Expected: "
#define GOT "Got: "
#define INFROOTS "infinity roots\n"
#define NOROOTS "no roots\n"


//#################INITIALIZATION######################
bool runDiagnostic(int argc, char **argv);


//################CONSTANTS##############################
const char TEST_FLAG[] = "--test";


#endif
