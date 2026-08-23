#include "Diagnostic.h"

//##########################################################
//реализовать считывание из файла
//#########################################################

/*
char* a = "123";

const char* a = "123";
// char const* a; same
a = "234567";
a = "345678901234"; // a can be changed



char * const a;
const char const * a;

*/


//###############INITIALIZATION#######################
bool RunTest(const int testN, const double *params, const Nroots nroots_ref, const double *roots_ref);
bool read_args(int testN, double *params, Nroots *nroots, double *x_ref);
void print_switch(const TypeNroots type, const double *roots, const Nroots nroots);
const char *str_type(const TypeNroots type);

/// DO DIAGNOSTIC OF SQUARE_SOLVE
void RunDiagnostic(void){
    
    int n_fail = 0;
    int testN = 0;
    
    double params[3] = {};    
    Nroots nroots_ref = ONE_ROOT;
    double x_ref[2] = {};
    
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
            print_switch(Expected, roots_ref, nroots_ref);
            //print "got" stroke
            print_switch(Got, roots, nroots);
            
            return false;
        }
        
        //else: got and referense mach: OK
        _GREEN printf("Test #%d passed.\n", testN); _WHITE
        return true;
}


void print_switch(const TypeNroots type, const double *roots, const Nroots nroots){

      switch (nroots){
                  
                case INF_ROOT: {
                    
                    _RED printf("%s " INFROOTS, str_type(type)); _WHITE
                    break;
                }
                
                case ZERO_ROOT: {
                
                    _RED printf("%s " NOROOTS, str_type(type)); _WHITE
                    break;
                }
                
                case ONE_ROOT: {
                
                    if (type == Got){
                    
                          _RED printf("     %s 1 root x = %lg\n", str_type(type), *roots); _WHITE
                    }
                    else{
                          
                          _RED printf("%s :1 root x = %lg\n", str_type(type), *roots); _WHITE
                    }
                    
                    break;
                }
                
                case TWO_ROOT: {
                    
                    if (type == Got){
                    
                          _RED printf("     " GOT "2 roots x1 = %lg x2 = %lg\n", *roots, *(roots + 1)); _WHITE
                    }
                    else{
                          
                          _RED printf("     " EXPECTED "2 roots x1 = %lg x2 = %lg\n", *roots, *(roots + 1)); _WHITE
                    }
                    
                    break;
                }
                
                default : {}            
            }
}


//---------------------------------------------------------
///CONVERTS TYPE TO ITS STR MEANING
const char *str_type(const TypeNroots type){
    
    static const char *GOT_WORD = "Got";
    static const char *EXPECTED_WORD = "Expected";
    
    return (type == Got) ? GOT_WORD : EXPECTED_WORD;
}

//--------------------------------------------------------------------
/// READS INPUT ARGS AND RETURN TRUE/FALSE IN MEAN OF EXISTENCE of THIS ARGS
bool read_args(const int testN, double *params, Nroots *nroots, double *x_ref){

      //input line must complains to format: "A B C N X1 X2\n" X1 can be not written if N = 0, X2 can be not written if N < 2, if eq has inf roots, write -1 insted N
      
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
                break;
          }
          
          case -1: {
                
                *nroots = INF_ROOT;
                break;
          }
          
          default: {}      
      }
      
      sortRoots(x_ref);
      
      return true;
}


//-----------------------------------------------------------------------------------------------------------------------------------------


