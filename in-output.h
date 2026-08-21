#ifndef INOUTPUT_H
#define INOUTPUT_H

//###############INCLUDES#######################
#include "functions.h"
#include "enums.h"


//############DEFINES##############
#define MAXLEN 10000


//#################INITIALIZATION######################
void printRes(const double *roots, enum Nroots nroots);

bool readParam(const char type_of_param, double *param);

bool readAnswear(void);


#endif
