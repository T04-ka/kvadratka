#include "Diagnostic.h"

//сделать считывание из файла в массив и обьединить в функиию считывание труктур из массива

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
void startTestsFromFile(FILE *file);

void startTestsFromLocal(void);

bool RunTest(const int testN, Coeffs *coeffs, const Nroots nroots_ref, Roots *xref);

bool read_args(FILE *file, Coeffs *coeffs, Nroots *nroots, Roots *xref);

void print_switch(const TypeNroots type, Roots roots, const Nroots nroots);

const char *str_type(const TypeNroots type);


///HEAD DIAGNOSTIC FUNCTION
bool flagSwitch(int argc, char **argv){
    
    switch (argc){
        case 1: 
        {
            return false;
        }
        
        case 2:
        {
            TESTFLAGCHECK
            
            startTestsFromLocal();
            break;
        }
        
        case 3:
        {
            TESTFLAGCHECK
            
            FILEFLAGCHECK
            
            FILEOPEN(DEFAULTFILE)
            
            startTestsFromFile(file);
            break;
        }
        
        case 4:
        {
            TESTFLAGCHECK
            
            FILEFLAGCHECK
            
            FILEOPEN(argv[3])
            
            startTestsFromFile(file);
            break;
        }
        
        default: 
        {
            ELSEPRINT
        }
    }
    
    return true;
}


//------------------------------------------------------

void startTestsFromLocal(void) {

    int n_fail = 0; 
    Nroots nroots_ref = ONE_ROOT; 
    Coeffs coeffs {.a = 0, .b = 0, .c = 0}; 
    Roots xref {.x1 = 0, .x2 = 0}; 
    xref.x1 = xref.x2 = NAN; 
    
    for (int testN = 0; testN < LOCALDATALEN; testN++) {                   
                         
          coeffs.a = localData[testN].a;
          coeffs.b = localData[testN].b;
          coeffs.c = localData[testN].c;
          
          nroots_ref = localData[testN].nroots;
          
          xref.x1 = localData[testN].x1;          
          xref.x2 = localData[testN].x2;
                    
          if (!RunTest(testN + 1, &coeffs, nroots_ref, &xref)) {
                n_fail++;
          }
          
    }
}


//-------------------------------------------------------------------
/// DO DIAGNOSTIC OF SQUARE_SOLVE
void startTestsFromFile(FILE *file){
    
    int n_fail = 0;
    Nroots nroots_ref = ONE_ROOT;  
    Coeffs coeffs {.a = 0, .b = 0, .c = 0}; 
    Roots xref {.x1 = 0, .x2 = 0}; 
    xref.x1 = xref.x2 = NAN;
    int testN = 1;
    
    
    
    while (read_args(file, &coeffs, &nroots_ref, &xref)){
    
          if (!RunTest(testN + 1, &coeffs, nroots_ref, &xref)) {
                n_fail++;
          }
    }
    
}


//--------------------------------------------------------------------------------------------------
/// RUN TEST WITH GIVEN coeffs AND REFERENCE VALUES
bool RunTest(const int testN, Coeffs *coeffs, const Nroots nroots_ref, Roots *xref){

        Roots roots = {.x1 = NAN, .x2 = NAN};

        Nroots nroots = squareSolve(*coeffs, &roots);
        
        //got and reference dont match
        if (! (
                 nroots == nroots_ref 
              && isEqual_d(roots.x1, xref -> x1) 
              && isEqual_d(roots.x2, xref -> x2)
              ) ) {

            _RED printf("Test #%d FAILED. For parametrs a = %lg  b = %lg  c = %lg\n",
                             testN,                    coeffs -> a, coeffs -> b, coeffs -> c); _WHITE
                                          
            //print "expected" stroke
            print_switch(Expected, *xref, nroots_ref); 
            //print "got" stroke
            print_switch(Got, roots, nroots);
            
            return false;
        }
        
        //else: got and referense mach: OK
        _GREEN printf("Test #%d passed.\n", testN); _WHITE
        return true;
}


void print_switch(const TypeNroots type, Roots roots, const Nroots nroots){

      switch (nroots){
                  
                case INF_ROOT: 
                {
                    _RED printf("%s " INFROOTS, str_type(type)); _WHITE
                    break;
                }
                
                case ZERO_ROOT: 
                {
                    _RED printf("%s " NOROOTS, str_type(type)); _WHITE
                    break;
                }
                
                case ONE_ROOT: {
                
                    if (type == Got){
                    
                          _RED printf("     %s 1 root x = %lg\n", str_type(type), roots.x1); _WHITE
                    }
                    else{
                          
                          _RED printf("%s :1 root x = %lg\n", str_type(type), roots.x1); _WHITE
                    }
                    
                    break;
                }
                
                case TWO_ROOT: {
                    
                    if (type == Got)
                    {
                        _RED printf("     " GOT "2 roots x1 = %lg x2 = %lg\n", roots.x1, roots.x2); _WHITE
                    } else 
                    { 
                          _RED printf("     " EXPECTED "2 roots x1 = %lg x2 = %lg\n", roots.x1, roots.x2); _WHITE
                    }
                    
                    break;
                }
                
                default : {}            
            }
}


//---------------------------------------------------------
///CONVERTS TYPE TO ITS STR MEANING
const char *str_type(const TypeNroots type){
    
    const char *GOT_WORD = "Got";
    const char *EXPECTED_WORD = "Expected";
    
    return (type == Got) ? GOT_WORD : EXPECTED_WORD;
}

//--------------------------------------------------------------------
/// READS INPUT ARGS AND RETURN TRUE/FALSE IN MEAN OF EXISTENCE of THIS ARGS
bool read_args(FILE *file, Coeffs *coeffs, Nroots *nroots, Roots *xref){

      //input line must complains to format: "A B C N X1 X2\n" X1 can be not written if N = 0, X2 can be not written if N < 2, if eq has inf roots, write -1 insted N
      
      //input_line - stroke of input we work with
      char line[MAXLEN] = {};

      int int_nroots = 0;
      int nendptr = 0;
      
      if (get_lineF(file, line, MAXLEN) < 1){
            
            return false;
      }
      
      sscanf(line, "%lg %lg %lg %d%n", &(coeffs -> a), &(coeffs -> b), &(coeffs -> c), &int_nroots, &nendptr);
      
      
      xref -> x1 = xref -> x2 = NAN;
      
      switch (int_nroots) {
      
          case 0: {
                
                *nroots = ZERO_ROOT;
                break;
          }
          
          case 1: {
                
                *nroots = ONE_ROOT;
                sscanf(line + nendptr, " %lg", &(xref -> x1));
                break;
          }
          
          case 2: {
                
                *nroots = TWO_ROOT;
                sscanf(line + nendptr, " %lg %lg", &(xref -> x1), &(xref -> x2));
                break;
          }
          
          case -1: {
                
                *nroots = INF_ROOT;
                break;
          }
          
          default: {}      
      }
      
      sortRoots(xref);
      
      return true;
}


//-----------------------------------------------------------------------------------------------------------------------------------------
