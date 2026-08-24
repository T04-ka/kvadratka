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

//##############MACROSES##############################       

#define FILEOPEN(A) FILE *file = fopen(A,"r");                                    \
                    if (file == NULL) {                                           \
                        _RED printf("No such file \"%s\".\n", A); _WHITE          \
                        return true;                                              \
                    }
                    
#define TESTFLAGCHECK if (strcmp(argv[1], STARTTEST_FLAG))                        \
                         {                                                        \
                             _RED printf("Unknown option: %s\n", argv[1]); _WHITE \
                             printf("Usage: [--test]\n");                         \
                             return true;                                         \
                         }
                         
#define FILEFLAGCHECK if (strcmp(argv[2], READFROMFILE_FLAG))                     \
                      {                                                           \
                          _RED printf("Unknown option: %s\n", argv[2]); _WHITE    \
                          printf("Usage: [-f | -f filename.txt]\n");              \
                          return true; \
                      }
                      
#define ELSEPRINT _RED printf("Unknown option.\n"); _WHITE \
                  printf("Usage: [-test] [-f | -f filename.txt]\n"); 


//#################INITIALIZATION######################
bool flagSwitch(int argc, char **argv);

//################CONSTANTS##############################
const char* const STARTTEST_FLAG = "--test";
const char* const READFROMFILE_FLAG = "-f";

const Data localData[] = {
                    {0, 0, 0, INF_ROOT},
                    {0, 0, 1, ZERO_ROOT},
                    {1, 0, -1, TWO_ROOT, -1, 1}
                    };


const unsigned int sizeofDataStruct = sizeof(Data);
#endif
