#include "./../headers/programDefault.h"

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

        _WHITE slowPrint("Write q if you want to quit program: ");

    } while (readAnswear());
}



//-------------------------------------------------------------------------
/// Call function and write parameter in "Data" structure
///
/// @param[in]  A   Type of parameter (A, B, C)
/// @param[in]  B   "Data" structure case
///
//-------------------------------------------------------------------------

#define READ_PARAM(A, B)    if (readParam(A, &(params -> B))) \
                                return;



//-------------------------------------------------------------------------
/// Enters coefficients
///
/// @param[out]   Data* params    Pointer on "Data" structure with parametrs
///
//-------------------------------------------------------------------------

void enterParams(Data* params){


    //starting message
    _WHITE slowPrint("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0.");

    READ_PARAM('A', a)
    READ_PARAM('B', b)
    READ_PARAM('C', c)

}

