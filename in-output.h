#ifndef INOUTPUT_H
#define INOUTPUT_H

//###############INCLUDES#######################
#include "functions.h"
#include "enums.h"
#include "colors.h"

#include "structures.h"
  

//############DEFINES##############
#define MAXLEN 10000


//#################INITIALIZATION######################
void printRes(Roots roots, Nroots nroots);

void printErrors(Errors error);

bool readParam(const char type_of_param, double *param);

bool readAnswear();

int get_line(char *s, int maxlen);

int get_lineF(FILE *file, char *s, int maxlen);

#endif
