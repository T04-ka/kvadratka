#ifndef FLAGSWITCH_H
#define FLAGSWITCH_H


#include "in-output.h"
#include "sqSolve.h"

//########################MACROSES#############################
#define READ_PARAM(A, B) if (readParam(A, &(params -> B))) return;


//################INITIALIZATION##################
void runDefault();


#endif
