#include "in-output.h"

//###READING BODY ANSWEAR TO CONTINUE SOLVING###
bool readAnswear(void){
      
      int c = 0;      
      
      //asking body until get the answear or program ends by him
      while (1){
            
            //skip spaces
            while (isspace((c=getchar())) && c != '\n') {}
           
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
}

//------------------------------------------------
//###READING INPUT PARAM A/B/C###
bool readParam(const char type_param, double *param){
      
      char line[MAXLEN] = {};
      int input=0, len=0;
      bool err = false; //error flag to help detecting errors
      
      
      do {  
            printf("\nPlease, enter parametr %c: ", type_param);  
            
            err = false; //set the error flag in false
            
            len = get_line(line, MAXLEN);            
            input = sscanf(line, "%lg", param);
            
            //###END OF INPUT CHECK###
            if (len == 0){
                  
                  
                        printRes({0}, EMPTY_INPUT);
                        return true;
                  
            }
            
            if (is_OnlySpace_in_line(line)) {
                        
                  printRes({0}, EMPTY_INPUT);
                  err = true;
            }
            
            else if (!is_OnlyDigit_in_line(line)){
                  
                  printRes({0}, INPUT_ERROR);
                  err = true;
            }
      
      } while (!(input == 1 && !err));
      return false;
}

//----------------------------------------------------------------------------
//###PRINTING RESULTS OF SOLVING EQUATION###
void printRes(const double *roots, Nroots nroots){
    //  assert(roots);
      
      switch (nroots) {
      
          case ZERO_ROOT: {
                printf("\nEquation has no roots.\n");
                break;
          }
          
          case ONE_ROOT: {
                printf("\nEquation has 1 root: x = %g.\n", roots[0]);
                break;
          }
          
          case TWO_ROOT: {
                printf("\nEquation has 2 roots: x1 = %g, x2 = %g.\n", roots[0], roots[1]);
                break;
          }
          
          case INF_ROOT: {
                printf("\nEquation has infinity roots.\n");
                break;
          }
          
          case EMPTY_INPUT: {
                printf("\nError: empty input.\n");
                break;
          }
          
          case INPUT_ERROR: {
                printf("\nError: wrong input.\n");
                break;
          }
          
          default: {
                
                printf("\nUnknown error.\n");
          }
      }
}
//-------------------------------------------------------------------------

