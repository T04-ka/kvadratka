#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

//###############INCLUDES#######################
#include <stdio.h>

#include "colors.h"
#include "enums.h"
#include "sqSolve.h"
#include "functions.h"
#include "in-output.h"
#include "structures.h"


//#############STRUCTURES#####################
struct LocalData {
                  double a, b, c;
                  Nroots nroots;
                  double x1=NAN, x2=NAN;
                  };



//###############DEFINES########################

#define MAXLEN 10000
#define MAXFLEN 100
#define EXPECTED "Expected: "
#define GOT "Got: "
#define INFROOTS "infinity roots\n"
#define NOROOTS "no roots\n"
#define LOCALDATALEN 3


//##############MACROSES##############################

#define INIT_STARTTEST int n_fail = 0; \
                       Nroots nroots_ref = ONE_ROOT; \
                       Coeffs coeffs {.a = 0, .b = 0, .c = 0}; \
                       Roots xref {.x1 = 0, .x2 = 0}; \
                       xref.x1 = xref.x2 = NAN; \
                       int testN = 0;
                      
#define COEFFREAD(A) coeffs.A = localData[testN].A;

#define NROOTSREAD nroots_ref = localData[testN].nroots;

#define XREED(A) xref.A = localData[testN].A;

//#################INITIALIZATION######################
bool runDiagnostic(int argc, char **argv);


//################CONSTANTS##############################
const char TEST_FLAG[] = "--test";

const LocalData localData[] = {
                    {0, 0, 0, INF_ROOT},
                    {0, 0, 1, ZERO_ROOT},
                    {1, 0, -1, TWO_ROOT, -1, 1}
                    };

#endif
