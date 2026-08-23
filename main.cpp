#include "main.h"


int main(int argc, char **argv){
      
      if (flagSwitch(argc, argv)) {
            
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
            
            //finding roots
            Nroots nroots =  squareSolve(coeffs, &roots);
            
            printRes(roots, nroots);
            
            //asking body if he wants another equation to solve
            _WHITE printf("Write n if you want to quit program or continue solving equations.\t");
            
            
      } while (readAnswear());
      
      return 0;   
}
