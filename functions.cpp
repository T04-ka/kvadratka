#include "functions.h"

//###READING LINE###
int get_line(char *s, int mxlen){
      
      int c = 0;
      int len = 0;
      
      while ((c = getchar()) != '\n' && c != EOF && len < mxlen){
            
            s[len++] = (char) c;      
      }
      
      if (c == '\n') {
      
            s[len++] = (char) c;
      }
      
      s[len] = '\0';
      
      return len;      
}

//---------------------------------------------------------
//###CHECKING IF ONLY SPACE IN LINE###
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

//------------------------------------------------------
//###CHECKING IF DOUBLE = ZERO###
bool is_zero(double x){
      
      if (x > 0){
            
            return (x < ZERO_BORDER) ? true
                                     : false;
      }
      else {
      
            return (x > -ZERO_BORDER) ? true
                                      : false;
      }
}

//-------------------------------------------------------------
Errors is_input_correct(char *s){

      if (!is_OnlyDigit_in_line(s)){

            return INPUT_ERROR;
      }

      char *first_digit, *dot, *last_digit, *ps;
      bool is_number_exist = false, is_dot_exist = false;

      int len = strlen(s);


      //find first digit in stroke
      ps = s;
      while (*ps != '\n'){ //"as..sd\n\0"

            if (isdigit(*(ps++))) {

                  first_digit = --ps;
                  is_number_exist = true;
                  break;
            }
      }

      //dot find
      ps = s;
      while (*ps != '\n'){ //"as..sd\n\0"
            if (*(ps++) == '.'){

                  dot = --ps;
                  is_dot_exist = true;
                  break;
            }
      }
      
      if (!is_number_exist){

            return (is_dot_exist) ? INPUT_ERROR //ONLY DOT EXIST IN INPUT
                                  : EMPTY_INPUT; //EMPTY INPUT
      }

      //find last digit in stroke
      ps = s;
      for (int i = len - 2; i >= 0; i--){ //"as..sd\n\0" -> s[len-2] = '\n'

            if (isdigit(*(ps + i))){

                  last_digit = ps+i;
                  break;
            }
      }


      if (is_dot_exist && !(first_digit < dot && dot < last_digit)){

            return INPUT_ERROR; //DOT LOCATED NOT IN NUMBER
      }

      
      for (ps = first_digit; ps < last_digit; ps++){

            if (!isdigit(*ps) && *ps != '.') {

                  return INPUT_ERROR; //NOT ONE NUMBER
            }
      } 

      return NO_ERROR; //INPUT IS CORRECT
}
//------------------------------------------------------------------------