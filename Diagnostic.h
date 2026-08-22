#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

//###############INCLUDES#######################
#include <stdio.h>
#include "colors.h"
#include "enums.h"
#include "sqSolve.h"
#include "functions.h"


//#################INITIALIZATION######################
bool RunTest(const int testN, const double *params, const Nroots nroots_ref, const double *roots_ref);


#endif
