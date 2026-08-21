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
      else{
      
            return (x > -ZERO_BORDER) ? true
                                      : false;
      }
}

//-------------------------------------------------------------
