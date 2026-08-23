#include "main.h"


int main(int argc, char **argv){
      
      if (runDiagnostic(argc, argv)) {
            
            return 0;
      }
      
      //initialization      
      Coeffs coeffs = {.a = 0, .b = 0, .c = 0};
      Roots roots = {.x1 = 0, .x2 = 0};

      //many square solve addition
      do {
          
            //starting message
            _WHITE printf("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0.");
            
            
            bool is_input_ends = false;
            
            READ_PARAM('A', a)
            READ_PARAM('B', b)
            READ_PARAM('C', c)
            
            
            /*
            bool is_input_ends = readParam(TYPES[0], &coeffs.a); 
            if (is_input_ends) return 0;      
                  //if input ends breaking up the program
            if (is_input_ends) return 0;
                        
            bool is_input_ends = readParam(TYPES[1], &coeffs.b); 
                  
                  //if input ends breaking up the program
                  if (is_input_ends){   
                  
                        return 0;
            
            bool is_input_ends = readParam(TYPES[0], &coeffs.c); 
                  
                  //if input ends breaking up the program
                  if (is_input_ends){   
                  
                        return 0;
            */
            /*
            //reading input parametrs
            for (int i = 0; i < 3; i++){
                  //reading coeffs and checking on input end
                  bool is_input_ends = readParam(TYPES[i], coefs+i); 
                  
                  //if input ends breaking up the program
                  if (is_input_ends){   
                  
                        return 0;
                  }
            }
            */
            //finding roots
            Nroots nroots =  squareSolve(coeffs, &roots);
            
            printRes(roots, nroots);
            
            //asking body if he wants another equation to solve
            _WHITE printf("Write n if you want to quit program or continue solving equations.\t");
            
            
      } while (readAnswear());
      
      return 0;   
}
