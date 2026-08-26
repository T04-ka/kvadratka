#include "programDefault.h"

void enterParams(Data *coeffs);



void runDefault(){

    //initialization
    Data params = {};
    Data roots = {};


    //many square solve addition
    do {
        enterParams(&params);

        squareSolve(params, &roots);

        printRes(roots);

        _WHITE print("Write q if you want to quit program. ");

    } while (readAnswear());
}


//--------------------------------------------------
///ENTERING PARAMS IN DEFAULT PROGRAM
void enterParams(Data* params){


    //starting message
    _WHITE print("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0.");

    READ_PARAM('A', a)
    READ_PARAM('B', b)
    READ_PARAM('C', c)

}

