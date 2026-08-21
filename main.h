#ifndef MAIN_H
#define MAIN_H

//###############INCLUDES#######################
#include <stdio.h>
#include <ctype.h>

//----------------------------------
//############DEFINES############################
#define MAXLEN 10000

//----------------------------------------------------------
//####################ENUMS############################
enum Nroots {
  ZERO_ROOT = 0,
  ONE_ROOT = 1,
  TWO_ROOT = 2,
  INF_ROOT = 8,
  INPUT_ERROR = -1,
  EMPTY_INPUT = -2
};

//-------------------------------------------------------
//################CONSTANTS##############################
const char types[] = {'A','B','C'};

//-------------------------------------------------------
//#################INITIALIZATION######################
bool is_OnlySpace_in_line(char *s);

bool is_OnlyDigit_in_line(char *s);

int get_line(char *s, int maxlen);

Nroots squareSolve(const double *coefs, double *roots);

void printRes(const double *roots, enum Nroots nroots);

bool readParam(const char type_of_param, double *param);

#endif
