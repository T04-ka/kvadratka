#include "in-output.h"

//###READING BODY ANSWER TO CONTINUE SOLVING###
bool readAnswear(int *last_char){  
      
      //asking person until get the answer or program ends by him
      int c = getchar();

      *last_char = c; //needed for not clear buffer if c = '\n'. see main

      //anal answear
      switch (c){
            
            case 'n': {
            
                  return false;
            }
            
            default: {
            
                  return true;
            }
      }
}

//------------------------------------------------
//###READING INPUT PARAM A/B/C###
bool readParam(const char type_param, double *param){

      Errors input_error = EMPTY_INPUT;
      do {  
            _WHITE printf("\nPlease, enter parametr %c: ", type_param); //space for entering the param
              
            char line[MAXLEN] = {}; //space for input line
            int len = get_line(line, MAXLEN); //taking line from input stream            
            
            //###END OF INPUT CHECK###
            if (len == 0){
                  
                  printErrors(EMPTY_INPUT);
                  return true;
            } 
            
            //ERROR CHECK and taking param from line
            input_error = readDouble(line, param);
            
            if (input_error){
            
                  printErrors(input_error);      
            }      
                  
      } while (input_error); //stoping cicl if no errors
      return false;
}

//-----------------------------------------
//###PRINTING ERRORS###
void printErrors(Errors error){
      switch (error) {
          
          case EMPTY_INPUT: {
                _RED printf("\nError: empty input.\n"); _WHITE
                break;
          }
          
          case INPUT_ERROR: {
                _RED printf("\nError: wrong input.\n"); _WHITE
                break;
          }
          
         case NO_ERROR: {break;}

         default: {}
      }
}

//----------------------------------------------------------------------------
//###PRINTING RESULTS OF SOLVING EQUATION###
void printRes(const double *roots, Nroots nroots){
    //  assert(roots);
      
      switch (nroots) {
      
          case ZERO_ROOT: {
                _YELLOW printf("\nEquation has no roots.\n");
                break;
          }
          
          case ONE_ROOT: {
                _YELLOW printf("\nEquation has 1 root: x = %g.\n", roots[0]);
                break;
          }
          
          case TWO_ROOT: {
                _YELLOW printf("\nEquation has 2 roots: x1 = %g, x2 = %g.\n", roots[0], roots[1]);
                break;
          }
          
          case INF_ROOT: {
                _YELLOW printf("\nEquation has infinity roots.\n");
                break;
          }
          
          default: {}
      }
}


//---------------------------------------------------------------
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


//-------------------------------------------------------------------------
/// READING LINE FROM FILE
int get_lineF(FILE *pfile, char *s, int maxlen){
    
    int c = 0, len = 0;
    while ((c = getc(pfile)) != EOF && c != '\n' && len < maxlen){
        
        s[len++] = c;
    }
    
    if (c == '\n') {
        
        s[len++] = c;
    }
    
    s[len] = '\0';
    
    return len;
}
