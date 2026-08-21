#include "main.h"

// убрать из мейна реализацию функций

int main(){
      
      //initialization
      double coefs[] = {0, 0, 0}; // A B C
      double roots[] = {0, 0}; // x1 x2
      
      
      int i = 0;
      bool is_input_ends = false; //to catch the moment with end of input stream
      
      //many square solve addition
      while (1){
            
            //starting message
            printf("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0.");
            
            //reading input parametrs
            for (i = 0; i < 3; i++){
                  
                  //reading coeffs and checking on input end
                  is_input_ends = readParam(types[i], coefs+i); 
                  
                  //if input ends breaking up the program
                  if (is_input_ends){
                        
                        return 0;
                  }
            }
            
            //finding roots
            Nroots nroots =  squareSolve(coefs, roots);
            
            //printing results
            printRes(roots, nroots);
            
            
            //asking body if he wants another equation to solve
            printf("Write n if you want to quit program or continue solving equations.\t");
            
            if (!readAnswear()){
                  
                  break;
            }
      }
      return 0;   
}

//-----------------------------------------------

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

//--------------------------------

bool is_OnlySpace_in_line(char *s){

      int i = 0;
      char c = 0;
      while ((c = s[i++]) != '\n' && c != '\0'){
      
            if (!isspace(c)) return false;
      }
      
      return true;
}

//------------------------------------

bool is_OnlyDigit_in_line(char *s){
      
      int i = 0;
      char c = 0;
      while ((c=s[i++]) != '\n' && c != '\0'){
            
            if (!isdigit(c)) return false;
      }
      
      return true;
}

//---------------------------------------------------------

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

//------------------------------------------------------------

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
