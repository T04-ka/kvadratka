#include "main.h"


int main(int argc, char **argv){
      
      if (flagSwitch(argc, argv)) {
            
            return 0;
      }
      
      //initialization      
      Data params = {};
      Data roots = {};


      //many square solve addition
      do {
          
            //starting message
            _WHITE print("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0.");
            
            
            bool is_input_ends = false;
            
            READ_PARAM('A', a)
            READ_PARAM('B', b)
            READ_PARAM('C', c)
            
            //finding roots
            roots.nroots = squareSolve(params, &roots);
            
            printRes(roots);
            
            //asking body if he wants another equation to solve
            _WHITE print("Write n if you want to quit program or continue solving equations.\t");
            
            
      } while (readAnswear());
      
      return 0;   
}
