#include "Diagnostic.h"

//##########################################################
//реализовать цикл
//реализовать считывание из файла
//#########################################################

//###############INITIALIZATION#######################
bool RunTest(const int testN, const double *params, const Nroots nroots_ref, const double *roots_ref);
bool read_args(int testN, double *params, Nroots *nroots, double *x_ref);


/// DO DIAGNOSTIC OF SQUARE_SOLVE
void RunDiagnostic(void){
    
    int n_fail = 0;
    int testN = 0;
    
    double params[] = {1, 2, 1};    
    Nroots nroots_ref = ONE_ROOT;
    double x_ref[] = {-1, NAN};
    
    while (read_args(testN++, params, &nroots_ref, x_ref)){
    
          if (!RunTest(testN, params, nroots_ref, x_ref)) {
                n_fail++;
          }
    }
    
}


//--------------------------------------------------------------------------------------------------
/// RUN TEST WITH GIVEN PARAMS AND REFERENCE VALUES
bool RunTest(const int testN, const double *params, const Nroots nroots_ref, const double *roots_ref){

        double roots[] = {NAN, NAN};

        Nroots nroots = squareSolve(params, roots);
        
        //got and reference dont match
        if (! (
                 nroots == nroots_ref 
              && isEqual_d(*roots, *roots_ref) 
              && isEqual_d(*(roots+1), *(roots_ref+1))
              ) ) {

            _RED printf("Test #%d FAILED. For parametrs a = %lg  b = %lg  c = %lg\n",
                             testN,                    *params, *(params+1), *(params+2)); _WHITE
                                          
            //print "expected" stroke
            switch (nroots_ref){
                  
                case INF_ROOT: {
                    
                    _RED printf("Expected: infinity roots\n"); _WHITE
                    break;
                }
                
                case ZERO_ROOT: {
                
                    _RED printf("Expected: no roots\n"); _WHITE
                    break;
                }
                
                case ONE_ROOT: {
                    
                    _RED printf("Expected: 1 root x = %lg\n", *roots_ref); _WHITE
                    break;
                }
                
                case TWO_ROOT: {
                    
                    _RED printf("Expected: 2 roots x1 = %lg x2 = %lg\n", *roots_ref, *(roots_ref + 1)); _WHITE
                    break;
                }
                
                default : {}            
            }
            
            //print "got" stroke
            switch (nroots_ref){
                  
                case INF_ROOT: {
                    
                    _RED printf("Got: infinity roots\n"); _WHITE
                    break;
                }
                
                case ZERO_ROOT: {
                
                    _RED printf("Got: no roots\n"); _WHITE
                    break;
                }
                
                case ONE_ROOT: {
                    
                    _RED printf("     Got: 1 root x = %lg\n", *roots); _WHITE
                    break;
                }
                
                case TWO_ROOT: {
                    
                    _RED printf("     Got: 2 roots x1 = %lg x2 = %lg\n", *roots, *(roots + 1)); _WHITE
                    break;
                }
                
                default : {}            
            }
            
            return false;
        }
        
        //else: got and referense mach: OK
        _GREEN printf("Test #%d passed.\n", testN); _WHITE
        return true;
}


//--------------------------------------------------------------------
/// READS INPUT ARGS AND RETURN TRUE/FALSE IN MEAN OF EXISTENCE of THIS ARGS
bool read_args(const int testN, double *params, Nroots *nroots, double *x_ref){

      //input line must complains to format: "A B C N X1 X2\n" X1 can be not written if N = 0, X2 can be not written if N < 2 
      
      //input_line - stroke of input we work with
      char line[MAXLEN] = {};

      int int_nroots = 0;
      int nendptr = 0;
      
      if (get_line(line, MAXLEN) < 1){
            
            return false;
      }
      
      sscanf(line, "%lg %lg %lg %d%n", params, params + 1, params + 2, &int_nroots, &nendptr);
      
      
      *x_ref = *(x_ref + 1) = NAN;
      
      switch (int_nroots) {
      
          case 0: {
                
                *nroots = ZERO_ROOT;
                break;
          }
          
          case 1: {
                
                *nroots = ONE_ROOT;
                sscanf(line + nendptr, " %lg", x_ref);
                break;
          }
          
          case 2: {
                
                *nroots = TWO_ROOT;
                sscanf(line + nendptr, " %lg %lg", x_ref, x_ref+1);
          }
          
          default: {}      
      }
      
      sortRoots(x_ref);
      
      return true;
}


//-----------------------------------------------------------------------------------------------------------------------------------------


