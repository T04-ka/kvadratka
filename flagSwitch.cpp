#include "flagSwitch.h"
#include "parser.h"


Flags flagDef(char *s);
void runMain();

/// FLAG SWITCHER
void flagSwitch(int argc, char **argv){

    switch (argc){
        case 1:
        {
            runMain();
            return;
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
            ELSEPRINT
        }
    }
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


//-----------------------------------------------------------
void runMain(){

    //initialization
    Data params = {};
    Data roots = {};


    //many square solve addition
    do {

        //starting message
        _WHITE print("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0.");

        READ_PARAM('A', a)
        READ_PARAM('B', b)
        READ_PARAM('C', c)

        //finding roots
        roots.nroots = squareSolve(params, &roots);

        printRes(roots);

        //asking body if he wants another equation to solve
        _WHITE print("Write q if you want to quit program or continue solving equations. ");


    } while (readAnswear());
}


