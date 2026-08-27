#include "main.h"


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
                              _RED print("Unknown option: %s\n", argv[1]); _WHITE
                              print("Usage: [--test] [--parse]\n");
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
                  _RED print("Unknown option.\n"); _WHITE
                  print("Usage: [--test] [--parse] [-f | -f filename.txt]\n");
            }
      }
      return 0;
}
