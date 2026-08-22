#include "Diagnostic.h"

//##########################################################
//реализовать цикл
//реализовать считывание из файла
//#########################################################

//###############INITIALIZATION#######################
bool RunTest(const int testN, const double *params, const Nroots nroots_ref, const double *roots_ref);
bool read_args(double *params, Nroots nroots, double *x_ref);


void RunDiagnostic(void){
    
    int n_fail = 0;
    int testN = 0;
    
    double params[] = {1, 2, 1};    
    Nroots nroots_ref = ONE_ROOT;
    double x_ref[] = {-1, NAN};
    
    while (read_args(params, nroots_ref, x_ref)){
    
          if (!RunTest(++testN, params, nroots_ref, x_ref)) {
                n_fail++;
          }
    }
    
}


bool RunTest(const int testN, const double *params, const Nroots nroots_ref, const double *roots_ref){

        double roots[] = {NAN, NAN};

        Nroots nroots = squareSolve(params, roots);
        
   //     printf("\nnroots == nroots_ref %d\nis_Equald(*roots, *roots_ref) %d\nis_Equald(*(roots+1), *(roots_ref+1) %d\n",nroots == nroots_ref, is_Equald(*roots, *roots_ref), is_Equald(*(roots+1), *(roots_ref+1)));
        
     //  printf("*roots+1 %lg\n*roots_ref+1 %lg", *(roots+1), *(roots_ref+1));
        
        //got and reference dont match
        if (! (
                 nroots == nroots_ref 
              && isEqual_d(*roots, *roots_ref) 
              && isEqual_d(*(roots+1), *(roots_ref+1))
              ) ) {

            _RED printf("Test #%d FAILED. For parametrs a = %lg  b = %lg  c = %lg\n",
                             testN,                    *params, *(params+1), *(params+2));
                                          
            //print "expected" stroke
            switch (nroots_ref){
                  
                case INF_ROOT: {
                    
                    _RED printf("Expected: infinity roots\n");
                    break;
                }
                
                case ZERO_ROOT: {
                
                    _RED printf("Expected: no roots\n");
                    break;
                }
                
                case ONE_ROOT: {
                    
                    _RED printf("Expected: 1 root x = %lg\n", *roots_ref);
                    break;
                }
                
                case TWO_ROOT: {
                    
                    _RED printf("Expected: 2 roots x1 = %lg x2 = %lg\n", *roots_ref, *(roots_ref + 1));
                    break;
                }
                
                default : {}            
            }
            
            //print "got" stroke
            switch (nroots_ref){
                  
                case INF_ROOT: {
                    
                    _RED printf("Got: infinity roots\n");
                    break;
                }
                
                case ZERO_ROOT: {
                
                    _RED printf("Got: no roots\n");
                    break;
                }
                
                case ONE_ROOT: {
                    
                    _RED printf("     Got: 1 root x = %lg\n", *roots);
                    break;
                }
                
                case TWO_ROOT: {
                    
                    _RED printf("     Got: 2 roots x1 = %lg x2 = %lg\n", *roots, *(roots + 1));
                    break;
                }
                
                default : {}            
            }
            
            return false;
        }
        
        //else: got and referense mach: OK
        _GREEN printf("Test #%d passed.\n", testN);
        return true;


}
