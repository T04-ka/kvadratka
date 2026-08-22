#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//###############INCLUDES#######################
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "enums.h"


//############DEFINES##############
#define BORDER 0.000001


//#################INITIALIZATION######################
bool is_OnlySpace_in_line(char *s);

bool is_OnlyDigit_in_line(char *s);

int get_line(char *s, int maxlen);

bool is_Equald(double a, double b);

Errors is_input_correct(char *line, double *input_d);

void clearBuffer(const int last_char);

void sortRoots(double *roots);

#endif
