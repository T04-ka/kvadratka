#ifndef PARSER_H
#define PARSER_H

//---------------------------------
#include "in-output.h"
#include "sqSolve.h"



//---------------------------------
/// Side of equation enumeration
///
//---------------------------------

enum SideOfEq {

    LEFT = 1,
    RIGHT = -1
};



//---------------------------------
/// Runs "Parse" part of program
///
//---------------------------------

void runParse(void);

#endif
