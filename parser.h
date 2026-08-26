#ifndef PARSER_H
#define PARSER_H


#include "in-output.h"


//#########MACROSES###############
#define CHECKSIGNEX if (isSignEx) {         \
                        return INPUT_ERROR; \
                    }                       \
                    isSignEx = true;        \
                    continue;

#define SETDEFAUTLT     sign = 1;        \
                        isSignEx = false;


enum SideOfEq {

    LEFT = 1,
    RIGHT = -1
};

void runParse(void);

#endif
