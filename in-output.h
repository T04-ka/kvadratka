#ifndef INOUTPUT_H
#define INOUTPUT_H

//######################INCLUDES#######################
#include "functions.h"
#include "enums.h"
#include "colors.h"
#include "structures.h"

#include <stdarg.h>
#include <time.h>
#include <unistd.h>
  

//######################DEFINES########################
#define MAXLEN 10000
#define PRINTSIZE 1000


//#################INITIALIZATION######################
void printRes(Data roots);

void printErrors(Errors error);

bool readParam(const char type_of_param, double *param);

bool readAnswear();

int get_line(char *s, int maxlen);

int get_lineF(FILE *file, char *s, int maxlen);

void print(const char *format, ...);


//###################CONSTANTS#########################
static const timespec SLEEPTIME = {.tv_sec = 0, .tv_nsec = (int) 1E7};

#endif
