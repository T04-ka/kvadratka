#include "main.h"


int main(int argc, char **argv){
      
      FILE *file = fopen("test.txt","r");
      
      //if flag F_TEST had written, Diagnostic will be started
      if (argc == 2 && !strcmp(argv[1], TEST_FLAG)){
      
           RunDiagnostic(file);
           fclose(file);
           return 0;
      }
      
      //initialization
      double coefs[] = {0, 0, 0}; // A B C
      double roots[] = {0, 0}; // x1 x2
      
      const char TYPES[] = {'A','B','C'}; 
      //many square solve addition
      while (1){
          
            //starting message
            _WHITE printf("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0.");
            
            //reading input parametrs
            for (int i = 0; i < 3; i++){
                  //reading coeffs and checking on input end
                  bool is_input_ends = readParam(TYPES[i], coefs+i); 
                  
                  //if input ends breaking up the program
                  if (is_input_ends){   
                  
                        return 0;
                  }
            }
            
            //finding roots
            Nroots nroots =  squareSolve(coefs, roots);
            
            printRes(roots, nroots);
            
            //asking body if he wants another equation to solve
            _WHITE printf("Write n if you want to quit program or continue solving equations.\t");
            
            int last_char = 0; //needed to do not clear the buffer if it already clear

            //if body want to stop program -> program stops
            if (!readAnswear(&last_char)){
                  
                  break;
            }
            
            //clearing input buffer (if needed)
            clearBuffer(last_char);
      }
      
      return 0;   
}
