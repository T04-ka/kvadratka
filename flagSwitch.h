#ifndef FLAGSWITCH_H
#define FLAGSWITCH_H

#include "Diagnostic.h"


//######################ENUMS##########################
enum Flags {
    TEST = 0,
    PARSE = 1,
    WRONG = -1
};


//##############MACROSES##############################
#define FILEOPEN(A) FILE *file = fopen(A,"r");                                    \
                    if (file == NULL) {                                           \
                        _RED print("No such file \"%s\".\n", A); _WHITE           \
                        return true;                                              \
                    }


#define TESTFLAGCHECK if (strcmp(argv[1], STARTTEST_FLAG))                       \
                      {                                                           \
                          _RED print("Unknown option: %s\n", argv[1]); _WHITE     \
                          print("Usage: [--test] [--parse]\n");                   \
                          return true;                                            \
                      }


#define FILEFLAGCHECK if (strcmp(argv[2], READFROMFILE_FLAG))                     \
                      {                                                           \
                         _RED print("Unknown option: %s\n", argv[2]); _WHITE      \
                         print("Usage: [-f | -f filename.txt]\n");                \
                         return true; \
                      }


#define ELSEPRINT _RED print("Unknown option.\n"); _WHITE                         \
                  print("Usage: [-test] [-f | -f filename.txt]\n");


//################INITIALIZATION##################
bool flagSwitch(int argc, char **argv);


const char STARTTEST_FLAG[] = "--test";
const char PARSE_FLAG[] = "--parse";
const char READFROMFILE_FLAG[] = "-f";

#endif
