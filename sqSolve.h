#ifndef SQSOLVE_H
#define SQSOLVE_H

//############INCLUDES#############
#include <stdio.h>
#include <math.h>

//-------------------------------------------
//############DEFINES##############
#define ZERO_BORDER 0.000001

//-----------------------------
//############ENUMS################
enum Nroots {
  ZERO_ROOT = 0,
  ONE_ROOT = 1,
  TWO_ROOT = 2,
  INF_ROOT = 8,
  INPUT_ERROR = -1,
  EMPTY_INPUT = -2
};

//----------------------------------
//############INITIALIZATION##########
bool is_zero(double x);

Nroots squareSolve(const double *coefs, double *roots);

#endif




