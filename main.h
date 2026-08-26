#ifndef MAIN_H
#define MAIN_H

//###############INCLUDES#######################
#include "sqSolve.h"
#include "in-output.h"
#include "Diagnostic.h"

#include "parser.h"
#include "flagSwitch.h"

//############MACROSES################

#define READ_PARAM(A, B) \
is_input_ends = readParam(A, &(params.B)); \
if (is_input_ends) return 0; 



#endif
