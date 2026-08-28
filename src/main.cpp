/*
 * main
 * + argparser
 * + programDefault
 * | + square_inoutput
 * | + square_solve
 * + Diagnostic
 * | + fileinput
 * | + inoutput
 * | + square_solve
 * + Parser
 * | + parserinput
 * | + square_solve
 * | + inoutput
 *
 *  square_solve
 *  + Data
 *  + solve()
 *  + enum
 *
 *  square_inoutput <- square_solve, inoutput
 *  +
 *  +
 *  + errors
 *
 *  errors
 *  + enum
 *  + printErrors()
 */

//######################INCLUDES##########################################
#include "./../headers/programDefault.h"
#include "./../headers/Diagnostic.h"
#include "./../headers/parser.h"

//######################MACROSES##########################################
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



//#############################MAIN#######################################
//------------------------------------------------------------------------
///
/// Runs main program
///
/// @param[in]    argc    Argc
/// @param[out]   argv    Argv
///
//------------------------------------------------------------------------

int main(int argc, char **argv){
      
      switch (argc){

            case 1:
            {
                  runDefault();
                  break;
            }

            case 2:
            {
                  switch (flagDef(argv[1])){

                        case TEST:
                        {
                              runTests(localData, LOCALDATALEN);
                              break;
                        }

                        case PARSE:
                        {
                              runParse();
                              break;
                        }

                        case WRONG:
                        {
                              _RED slowPrint("Unknown option: %s\n", argv[1]); _WHITE
                              slowPrint("Usage: [--test] [--parse]\n");
                              break;
                        }

                        default: {}

                  }
                  break;
            }

            case 3:
            {
                  TESTFLAGCHECK
                  FILEFLAGCHECK
                  FILEOPEN(DEFAULTFILE)

                  startTestsFromFile(file);
                  break;
            }

            case 4:
            {
                  TESTFLAGCHECK
                  FILEFLAGCHECK
                  FILEOPEN(argv[3])

                  startTestsFromFile(file);
                  break;
            }

            default:
            {
                  _RED slowPrint("Unknown option.\n"); _WHITE
                  slowPrint("Usage: [--test] [--parse] [-f | -f filename.txt]\n");
            }
      }
      return 0;
}
