#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//###############INCLUDES#######################
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "enums.h"

//############DEFINES##############
#define ZERO_BORDER 0.000001


//#################INITIALIZATION######################
bool is_OnlySpace_in_line(char *s);

bool is_OnlyDigit_in_line(char *s);

int get_line(char *s, int maxlen);

bool is_zero(double x);

Errors is_input_correct(char *line);

#endif
