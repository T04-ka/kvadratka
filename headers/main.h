#ifndef MAIN_H
#define MAIN_H

//######################INCLUDES#######################
#include "programDefault.h"
#include "Diagnostic.h"
#include "parser.h"

//######################MACROSES#######################
//------------------------------------------------------------------------
/// Opens file
///
/// @param[in]  A   Name of file
///
//------------------------------------------------------------------------

#define FILEOPEN(A) FILE *file = fopen(A,"r");                                    \
                    if (file == NULL) {                                           \
                        _RED slowPrint("No such file \"%s\".\n", A); _WHITE       \
                        return 0;                                                 \
                    }



//------------------------------------------------------------------------
/// Checks on STARTTEST_FLAG flag existance
///
//------------------------------------------------------------------------

#define TESTFLAGCHECK if (strcmp(argv[1], STARTTEST_FLAG))                        \
                      {                                                           \
                          _RED slowPrint("Unknown option: %s\n", argv[1]); _WHITE \
                          slowPrint("Usage: [--test] [--parse]\n");               \
                          return 0;                                               \
                      }



//------------------------------------------------------------------------
/// Checks on READFROMFILE_FLAG flag existance
///
//------------------------------------------------------------------------
#define FILEFLAGCHECK if (strcmp(argv[2], READFROMFILE_FLAG))                     \
                      {                                                           \
                          _RED slowPrint("Unknown option: %s\n", argv[2]); _WHITE \
                          slowPrint("Usage: [-f | -f filename.txt]\n");           \
                          return 0;                                               \
                      }



//------------------------------------------------------------------------
#endif
