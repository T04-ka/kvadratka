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
void runParse(void);

#endif
