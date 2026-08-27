#include "bin/Diagnostic.h"

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
bool runOneTest(const size_t testN, Data refData);

size_t readArgsF(FILE *file, Data** dataptr);

void print_switch(const TypeNroots type, Data data);

const char *str_type(const TypeNroots type);



//------------------------------------------------------------------------
/// Reads data from file and runs unit tests function
///
/// @param[in]    FILE* file    The file with data
///
//------------------------------------------------------------------------

void startTestsFromFile(FILE *file){
    
    Data *fileData = NULL;
    
    size_t fileDataLen = readArgsF(file, &fileData);
    
    runTests(fileData, fileDataLen);
    
    free(fileData);
}



//------------------------------------------------------------------------
/// Runs "Diagnostic" part of program
///
/// @param[in]    Data *refData    Array with input data structures
/// @param[in]    size_t len       Len of *refData array
///
//------------------------------------------------------------------------

void runTests(const Data *refData, size_t len){
      
      int n_fail = 0;
      for (size_t testN = 0; testN < len; testN++) {     
      
          if (!runOneTest(testN + 1, refData[testN])) {
                n_fail++;
          }
      }
}



//------------------------------------------------------------------------
/// Runs one test
///
/// @param[in]    size_t testN    The number of test
/// @param[in]    Data refData    The structure with reference data
///
/// @return true if test has passed and
///         false if not.
///
/// @note Prints the result of test.
//------------------------------------------------------------------------

bool runOneTest(const size_t testN, Data refData){

        Data solveData = {};

        squareSolve(refData, &solveData);
        
        //got and reference dont match
        if (! (
                 solveData.nroots == refData.nroots
              && isEqual_d(solveData.x1, refData.x1) 
              && isEqual_d(solveData.x2, refData.x2)
              ) ) {

            _RED slowPrint("Test #%lu FAILED. For parametrs a = %lg  b = %lg  c = %lg\n",
                             testN,                    refData.a, refData.b, refData.c); _WHITE
                                          
            //print "expected" stroke
            print_switch(Expected, refData);
            //print "got" stroke
            print_switch(Got, solveData);
            
            return false;
        }
        
        //else: got and referense mach: OK
        _GREEN slowPrint("Test #%lu passed.\n", testN); _WHITE
        return true;
}



//------------------------------------------------------------------------
/// Prints result of test
///
/// @param[in]    TypeNroots type    Type of print (got/expected)
/// @param[in]    Data data          "Data" structure with data to print
///
//------------------------------------------------------------------------

void print_switch(const TypeNroots type, Data data){

      switch (data.nroots){
                  
                case INF_ROOT: 
                {
                    _RED slowPrint("%s " INFROOTS, str_type(type)); _WHITE
                    break;
                }
                
                case ZERO_ROOT: 
                {
                    _RED slowPrint("%s " NOROOTS, str_type(type)); _WHITE
                    break;
                }
                
                case ONE_ROOT: {
                
                    if (type == Got){
                    
                          _RED slowPrint("     %s 1 root x = %lg\n", str_type(type), data.x1); _WHITE
                    }
                    else{
                          
                          _RED slowPrint("%s :1 root x = %lg\n", str_type(type), data.x1); _WHITE
                    }
                    
                    break;
                }
                
                case TWO_ROOT: {
                    
                    if (type == Got)
                    {
                        _RED slowPrint("     " GOT "2 roots x1 = %lg x2 = %lg\n", data.x1, data.x2); _WHITE
                    } else 
                    { 
                          _RED slowPrint("     " EXPECTED "2 roots x1 = %lg x2 = %lg\n", data.x1, data.x2); _WHITE
                    }
                    
                    break;
                }
                
                default : {}            
            }
}



//------------------------------------------------------------------------
/// Makes a stroke with type given
///
/// @param[in]    TypeNroots type    Got/Expected type
///
/// @return Pointer on stroked type, located in ROdata.
///
//------------------------------------------------------------------------

const char *str_type(const TypeNroots type){
    
    const char *GOT_WORD = "Got";
    const char *EXPECTED_WORD = "Expected";
    
    return (type == Got) ? GOT_WORD : EXPECTED_WORD;
}



//------------------------------------------------------------------------
/// Reads data entered in file and write in array of structures
///
/// @param[in]     FILE* file        The file with data
/// @param[out]    Data** dataArr    Pointer on pointer on array with "Data" structures
///
/// @return Len of resulting array
///
/// @note Allocate the memory with realloc() and write data in heap buffer,
///       works only with pointers.
///
/// @note Input line must complains to format: "A B C N X1 X2\n",
///       X1 can be not written if N = 0, X2 can be not written if N < 2,
///       if equation has inf roots, -1 must be written insted of N
///
//------------------------------------------------------------------------

size_t readArgsF(FILE* file, Data** dataArr){

      char line[MAXLEN] = {};
      
      size_t testsN = 0;
      size_t ReallocBorder = 0;

      for (; get_lineF(file, line, MAXLEN) > 1; testsN++){
          
          if (testsN == ReallocBorder) {
          
               *dataArr = (Data*) realloc(*dataArr, sizeofDataStruct * (ReallocBorder = 2 * testsN + 1));
          }
          
          Data* datatoRead = *dataArr + testsN;

          int int_nroots = 0;
          int nend = 0;
          
          sscanf(line, "%lg %lg %lg %d%n", &(datatoRead -> a), &(datatoRead -> b), &(datatoRead -> c), &int_nroots, &nend);
          
        //  printf("%lg %lg %lg \n--------------------\n", datatoRead.a, datatoRead.b, datatoRead.c);
          datatoRead -> x1 = datatoRead -> x2 = NAN;
          
          
          switch (int_nroots) {
          
              case 0: {
                    
                    datatoRead -> nroots = ZERO_ROOT;
                    break;
              }
              
              case 1: {
                    
                    datatoRead -> nroots = ONE_ROOT;
                    sscanf(line + nend, " %lg", &(datatoRead -> x1));
                    break;
              }
              
              case 2: {
                    
                    datatoRead -> nroots = TWO_ROOT;
                    sscanf(line + nend, " %lg %lg", &(datatoRead -> x1), &(datatoRead -> x2));
                    break;
              }
              
              case -1: {
                    
                    datatoRead -> nroots = INF_ROOT;
                    break;
              }
              
              default: {}      
          }
          sortRoots(datatoRead);
      }
      
      return testsN;
}


//------------------------------------------------------------------------
