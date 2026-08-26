#ifndef PARSER_H
#define PARSER_H


#include "in-output.h"
#include "enums.h"
#include "sqSolve.h"



//#########MACROSES###############
#define CHECKSIGNEX if (isSignEx && !isEqWasPrev && cptr - inputLine != 0) {         \
                        return INPUT_ERROR;                                          \
                    }                                                                \
                    isSignEx = true;                                                 \
                    isEqWasPrev = false;


#define SETARG(A)                                                                        \
                        coeffs -> A += sign * sideOfEq * ((isNumberEx) ? temp : 1);      \
                        cptr += endN + ((#A[0] == 'a') ? 2 : (#A[0] == 'b') ? 0 : -1);   \
                        sign = 1;                                                        \
                        isSignEx = false;                                                \
                        isEqWasPrev = true;                                              \
                        continue;


// #A[0]

enum SideOfEq {

    LEFT = 1,
    RIGHT = -1
};

void runParse(void);

#endif
