#include "./../headers/elseFuncs.h"



//------------------------------------------------------------------
/// Checks is only space in string
///
/// @param[in]    char *s     string
///
/// @return true if string is empty,
///         false if not.
///
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
/// Checks the correctness of input
///
/// @param[in]    char *s            Input string
/// @param[out]   double* input_d    The pointer to double read
///
/// @return INPUT_ERROR if input was wrong,
///         EMPTY_INPUT if input was empty,
///         NO_ERROR if input was correct;
///
/// @note A correct input is one number of type Double
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
/// Clears input buffer, if needed
///
/// @param[in]    int last_char   The last char written to buffer
///
/// @note Clears buffer until '\\n' is written
///
//------------------------------------------------------------------

void clearBuffer(int last_char){

      if (last_char == '\n'){

            return;
      }

      int c = 0;
      while ((c = getchar()) != '\n') {}
}



//------------------------------------------------------------------
/// Checks the equality of two Double numbers
///
/// @param[in]    double a     First double
/// @param[in]    double b     Second double
///
/// @return true if numbers are equal
///     and false if not
///
/// @note Compares double numbers with accuracy BORDER,
///       defined in header file
///
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
/// Sorts roots in structure
///
/// @param[in]    Data* roots      Pointer on "Data" structure
/// @param[out]   Data* roots      Changed value of roots right in structure
///
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
/// Checks is double equal to zero
///
/// @param[in]    double x     Double number
///
/// @return true if x = 0,
///         false if x != 0.
///
//------------------------------------------------------------------

bool isZero_d(double x){
    
    return isEqual_d(x, 0.0);
}



//------------------------------------------------------------------
/// Defines flag entered in string
///
/// @param[in]    char *s     Input string
///
/// @return TEST if test flag was entered,
///         PARSE if parse flag was entered,
///         WRONG if wrong flag was entered.
///
//------------------------------------------------------------------

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
