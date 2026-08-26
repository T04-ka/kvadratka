#include "flagSwitch.h"
#include "parser.h"


Flags flagDef(char *s);

/// FLAG SWITCHER
bool flagSwitch(int argc, char **argv){

    switch (argc){
        case 1:
        {
            return false;
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
                    parser();
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
            ELSEPRINT
        }
    }

    return true;
}


//----------------------------------------------------------------
///FLAG DEFINER
Flags flagDef(char *s){

    if (!strcmp(s, STARTTEST_FLAG)) {

        return TEST;
    }

    if (!strcmp(s, PARSE_FLAG)) {

        return PARSE;
    }

    return WRONG;
}


//------------------------------------------------------------------



