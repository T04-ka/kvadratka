#include "bin/programDefault.h"

void enterParams(Data *coeffs);



//-------------------------------------------------------------------------
/// Running default part of program
///
//-------------------------------------------------------------------------

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



//-------------------------------------------------------------------------
/// Enters coefficients
///
/// @param[out]   Data* params    Pointer on "Data" structure with parametrs
///
//-------------------------------------------------------------------------

#define READ_PARAM(A, B)    if (readParam(A, &(params -> B))) \
                                return;

void enterParams(Data* params){


    //starting message
    _WHITE slowPrint("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0.");

    READ_PARAM('A', a)
    READ_PARAM('B', b)
    READ_PARAM('C', c)

}

