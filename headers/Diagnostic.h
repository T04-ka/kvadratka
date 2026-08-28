#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

//######################INCLUDES#######################
#include "sqSolve.h"
#include "in-output.h"


//######################DEFINES########################
#define MAXLEN 10000
#define MAXFLEN 100
#define EXPECTED "Expected: "
#define GOT "Got: "
#define INFROOTS "infinity roots\n"
#define NOROOTS "no roots\n"
#define LOCALDATALEN 3
#define DEFAULTFILE "./tests/test.txt"


//#####################ENUMS##########################
//---------------------------------
///  Type of output enumeration
///
//---------------------------------

enum TypeOutput {
    Got = 0,
    Expected = 1
};



//######################INITIALIZATION#################
//------------------------------------------------------------------------
/// Reads data from file and runs unit tests function
///
/// @param[in]    file   The file with data
///
//------------------------------------------------------------------------
void startTestsFromFile(FILE *file);



//------------------------------------------------------------------------
/// Runs "Diagnostic" part of program
///
/// @param[in]    refData    Array with input data structures
/// @param[in]    len       Len of *refData array
///
//------------------------------------------------------------------------u
void runTests(const Data *refData, size_t len);


//######################CONSTANTS######################
//------------------------------------------------------------------------
/// Local array with data for unit tests
///
//------------------------------------------------------------------------

static const Data localData[] = {
    {0, 0, 0, INF_ROOT},
    {0, 0, 1, ZERO_ROOT},
    {1, 0, -1, TWO_ROOT, -1, 1}
};



//------------------------------------------------------------------------
/// Constant with size of "Data" struct
///
//------------------------------------------------------------------------

static const unsigned int sizeofDataStruct = sizeof(Data);


#endif
