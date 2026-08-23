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
#define EXPECTED "Expected: "
#define GOT "Got: "
#define INFROOTS "infinity roots\n"
#define NOROOTS "no roots\n"


//#################INITIALIZATION######################
void RunDiagnostic(FILE *file);


#endif
