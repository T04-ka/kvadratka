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



//###############DEFINES########################

#define MAXLEN 10000
#define MAXFLEN 100
#define EXPECTED "Expected: "
#define GOT "Got: "
#define INFROOTS "infinity roots\n"
#define NOROOTS "no roots\n"
#define LOCALDATALEN 3
#define DEFAULTFILE "test.txt"





//#################INITIALIZATION######################
void startTestsFromFile(FILE *file);

void runTests(const Data *refData, size_t len);

//################CONSTANTS##############################

const Data localData[] = {
                    {0, 0, 0, INF_ROOT},
                    {0, 0, 1, ZERO_ROOT},
                    {1, 0, -1, TWO_ROOT, -1, 1}
                    };


const unsigned int sizeofDataStruct = sizeof(Data);
#endif
