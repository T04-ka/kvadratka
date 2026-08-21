#include "in-output.h"

//###READING BODY ANSWER TO CONTINUE SOLVING###
bool readAnswear(void){
      
      int c = 0;      
      
      //asking body until get the answer or program ends by him
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
      
      char line[MAXLEN] = {}; //space for input line
      int input=0, len=0; //len is a len of line readed
      bool err = false; //error flag to help detecting errors
      
      
      do {  
            printf("\nPlease, enter parametr %c: ", type_param); //space for entering the param
            
            len = get_line(line, MAXLEN); //taking line from input stream
            input = sscanf(line, "%lg", param); //taking param from line
            
            /*
            //###END OF INPUT CHECK###
            if (len == 0){
                  
                        printErrors(EMPTY_INPUT);
                        return true;
                  
            } */
            
            //ERROR CHECK
            switch (is_input_correct(line)){

                  case INPUT_ERROR: {

                        printErrors(INPUT_ERROR);
                        err = true;
                        break;
                  }

                  case EMPTY_INPUT: {

                        printErrors(EMPTY_INPUT);
                        err = true;
                        break;
                  }

                  case NO_ERROR: {

                        err = false;
                        break;
                  }

                  default: {}
            }

      
      } while (!(input == 1 && !err)); //stoping cicl if no errors
      return false;
}

//-----------------------------------------
//###PRINTING ERRORS###
void printErrors(Errors error){
      switch (error) {
          
          case EMPTY_INPUT: {
                printf("\nError: empty input.\n");
                break;
          }
          
          case INPUT_ERROR: {
                printf("\nError: wrong input.\n");
                break;
          }
          
         // case NO_ERROR: {}

          default: {
                
                printf("\nUnknown error.\n");
          }
      }
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
          
          default: {
                
                printf("\nUnknown error.\n");
          }
      }
}
//-------------------------------------------------------------------------

