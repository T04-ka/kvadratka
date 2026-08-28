#include "./../headers/elseFuncs.h"



//------------------------------------------------------------------

bool is_OnlySpace_in_line(char *s){

      int i = 0;
      char c = 0;

      while ((c = s[i++]) != '\n' && c != '\0'){

            if (!isspace(c)) return false;
      }

      return true;
}


//------------------------------------------------------------------

Errors readDouble(char *s, double *input_d){

      *input_d = 0;
      char *endptr = NULL, *ps = s;

      *input_d = strtod(ps, &endptr);

      if (isEqual_d(*input_d, 0.0) && ps == endptr) {

            return (endptr != NULL && is_OnlySpace_in_line(endptr)) ? EMPTY_INPUT 
                                                                    : INPUT_ERROR;
      } else {

            return is_OnlySpace_in_line(endptr) ? NO_ERROR
                                                : INPUT_ERROR;
      }
}


//------------------------------------------------------------------

void clearBuffer(int last_char){

      if (last_char == '\n'){

            return;
      }

      int c = 0;
      while ((c = getchar()) != '\n') {}
}


//------------------------------------------------------------------

bool isEqual_d (double a, double b){
    
    //if nan==nan
    if (isnan(a) && isnan(b)) {
        
        return true;
    }
    
    if (abs(a - b) < BORDER) {
        
        return true;
    }
    
    return false;
}


//------------------------------------------------------------------

void sortRoots(Data *roots){
    
    double *x1 = &(roots -> x1);
    double *x2 = &(roots -> x2);
    
    double temp = 0.0;
    if (*x1 > *x2){
        
        temp = *x1;
        *x1 = *x2;
        *x2 = temp;        
    }
}


//------------------------------------------------------------------

bool isZero_d(double x){
    
    return isEqual_d(x, 0.0);
}



Flags flagDef(char *s){

      if (!strcmp(s, STARTTEST_FLAG)) {

            return TEST;
      }

      if (!strcmp(s, PARSE_FLAG)) {

            return PARSE;
      }

      return WRONG;
}


//------------------------------------------------------------------
