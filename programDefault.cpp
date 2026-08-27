#include "programDefault.h"

void enterParams(Data *coeffs);


//------------------------------------------------------------------------
///RUNING DEFAULT PART OF PROGRAM
void runDefault(){

    //initialization
    Data params = {};
    Data roots = {};


    //many square solve addition
    do {
        enterParams(&params);

        squareSolve(params, &roots);

        printRes(roots);

        _WHITE slowPrint("Write q if you want to quit program: ");

    } while (readAnswear());
}


//--------------------------------------------------
///ENTERING PARAMS IN DEFAULT PROGRAM
#define READ_PARAM(A, B)    if (readParam(A, &(params -> B))) \
                                return;

void enterParams(Data* params){


    //starting message
    _WHITE slowPrint("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0.");

    READ_PARAM('A', a)
    READ_PARAM('B', b)
    READ_PARAM('C', c)

}

