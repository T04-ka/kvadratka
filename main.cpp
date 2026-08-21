#include "./main.h"


int main(){
      
      //initialization
      double coefs[] = {0, 0, 0}; // A B C
      double roots[] = {0, 0}; // x1 x2
      
      
      printf("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0.");
      
      int i = 0;
      Bool is_input_empty = NO;
      
      for (i = 0; i < 3; i++){
      
            is_input_empty = readParam(types[i], coefs+i);
            if (is_input_empty == YES){
                  
                  break;
            }
      }
      
      if (is_input_empty == NO){
      
            Nroots nroots =  squareSolve(coefs, roots);
            
            printRes(roots, nroots);
      }
      
      return 0;   
}

//------------------------------------------------

Bool readParam(const char type_param, double *param){
      
      char line[MAXLEN] = {};
      int input=0, len=0;
      Bool err = NO; //error flag to help detecting errors
      
      
      do {  
            printf("\nPlease, enter parametr %c: ", type_param);  
            
            err = NO; //set the error flag in false
            
            len = get_line(line, MAXLEN);            
            input = sscanf(line, "%lg", param);
            
            //###END OF INPUT CHECK###
            if (len == 0){
                  
                  
                        printRes({0}, EMPTY_INPUT);
                        return YES;
                  
            }
            
            if (is_OnlySpace_in_line(line) == YES) {
                        
                  printRes({0}, EMPTY_INPUT);
                  err = YES;
            }
            
            else if (is_OnlyDigit_in_line(line) == NO){
                  
                  printRes({0}, INPUT_ERROR);
                  err = YES;
            }
      
      } while (!(input == 1 && err == NO));
      return NO;
}

//--------------------------------

Bool is_OnlySpace_in_line(char *s){

      int i = 0;
      char c = 0;
      while ((c = s[i++]) != '\n' && c != '\0'){
      
            if (!isspace(c)) return NO;
      }
      
      return YES;
}

//------------------------------------

Bool is_OnlyDigit_in_line(char *s){
      
      int i = 0;
      char c = 0;
      while ((c=s[i++]) != '\n' && c != '\0'){
            
            if (!isdigit(c)) return NO;
      }
      
      return YES;
}

//---------------------------------------------------------

int get_line(char *s, int mxlen){
      
      int c = 0;
      int len = 0;
      
      while ((c=getchar()) != '\n' && c != EOF && len < mxlen){
            
            s[len++] = (char) c;      
      }
      
      if (c == '\n') {
      
            s[len++] = (char) c;
      }
      
      s[len] = '\0';
      
      return len;      
}

//------------------------------------------------------------

void printRes(const double *roots, Nroots nroots){
      
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
