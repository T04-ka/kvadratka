#ifndef MAIN_H
#define MAIN_H

#include "programDefault.h"
#include "Diagnostic.h"
#include "sqSolve.h"
#include "in-output.h"
#include "parser.h"
#include "functions.h"

//##############MACROSES##############################
#define FILEOPEN(A) FILE *file = fopen(A,"r");                                    \
if (file == NULL) {                                                               \
    _RED print("No such file \"%s\".\n", A); _WHITE                               \
    return 0;                                                                     \
}


//------------------------------------------------------------------------
#define TESTFLAGCHECK if (strcmp(argv[1], STARTTEST_FLAG))                        \
{                                                                                 \
    _RED print("Unknown option: %s\n", argv[1]); _WHITE                           \
    print("Usage: [--test] [--parse]\n");                                         \
    return 0;                                                                     \
}


//------------------------------------------------------------------------
#define FILEFLAGCHECK if (strcmp(argv[2], READFROMFILE_FLAG))                     \
{                                                                                 \
    _RED print("Unknown option: %s\n", argv[2]); _WHITE                           \
        print("Usage: [-f | -f filename.txt]\n");                                 \
        return 0;                                                                 \
}


#endif
