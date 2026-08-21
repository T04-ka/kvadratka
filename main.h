#ifndef MAIN_H
#define MAIN_H

//###############INCLUDES#######################
#include <stdio.h>
#include <ctype.h>
#include "sqSolve.h"

//----------------------------------
//############DEFINES############################
#define MAXLEN 10000

//-------------------------------------------------------
//################CONSTANTS##############################
const char types[] = {'A','B','C'};

//-------------------------------------------------------
//#################INITIALIZATION######################
bool is_OnlySpace_in_line(char *s);

bool is_OnlyDigit_in_line(char *s);

int get_line(char *s, int maxlen);

void printRes(const double *roots, enum Nroots nroots);

bool readParam(const char type_of_param, double *param);

bool readAnswear(void);

#endif
