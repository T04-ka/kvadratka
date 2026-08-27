#include "elseFuncs.h"

/// CHECKING IF ONLY SPACE IN LINE
///
///
///
///
///
///
///
///
//---------------------------------------------------------

bool is_OnlySpace_in_line(char *s){

      int i = 0;
      char c = 0;
      while ((c = s[i++]) != '\n' && c != '\0'){
      
            if (!isspace(c)) return false;
      }
      
      return true;
}

//-------------------------------------------------------
//###CHECKING IF ONLY DIGITS IN LINE###
bool is_OnlyDigit_in_line(char *s){
      
      int i = 0, dot_count = 0;
      char c = 0;
      while ((c=s[i++]) != '\n' && c != '\0'){
            
            if (!(isdigit(c) || c == '.' || isspace(c))) return false;
            
            if (c == '.'){
                  
                  dot_count++;
            }
      }
      
      return (dot_count < 2) ? true
                             : false;
}


//-------------------------------------------------------------
/// CHECK ON CORRECTION INPUT
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


//------------------------------------------------------------------------
/// CLEARS INPUT BUFFER
void clearBuffer(int last_char){

      if (last_char == '\n'){

            return;
      }

      int c = 0;
      while ((c = getchar()) != '\n') {}
}


//------------------------------------------------------------
/// RETURNS TRUE IF DOUBLE A = DOUBLE B AND FALSE IF NOT
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
/// MAKE ROOTS X1 < X2
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


//------------------------------------------------

bool isZero_d(double x){
    
    return isEqual_d(x, 0.0);
}


//----------------------------------------------
///FLAG DEFINER
Flags flagDef(char *s){

      if (!strcmp(s, STARTTEST_FLAG)) {

            return TEST;
      }

      if (!strcmp(s, PARSE_FLAG)) {

            return PARSE;
      }

      return WRONG;
}
