#include "Diagnostic.h"

//сделать считывание из файла в массив и обьединить в функиию считывание труктур из массива
//Сделать норм дефолт тесты
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

bool RunTest(const int testN, Data refData);

size_t readArgsF(FILE *file, Data** dataptr);

void print_switch(const TypeNroots type, Data data);

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
    
    for (int testN = 0; testN < LOCALDATALEN; testN++) {                   
          Data refData = localData[testN];
          if (!RunTest(testN + 1, refData)) {
                n_fail++;
          }
          
    }
}


//-------------------------------------------------------------------
/// DO DIAGNOSTIC OF SQUARE_SOLVE
void startTestsFromFile(FILE *file){
    
    int n_fail = 0;
    
    Data *fileData = NULL;
    
    size_t fileDataLen = readArgsF(file, &fileData);
    
    
    for (size_t testN = 0; testN < fileDataLen; testN++) {                   
          Data refData = fileData[testN];
          if (!RunTest(testN + 1, refData)) {
                n_fail++;
          }
          
    }
    
    free(fileData);
}

/*
void readFileData(FILE file){
    

}
*/


//--------------------------------------------------------------------------------------------------
/// RUN TEST WITH GIVEN coeffs AND REFERENCE VALUES
bool RunTest(const int testN, Data refData){

        Data solveData = {};

        solveData.nroots = squareSolve(refData, &solveData);
        
        //got and reference dont match
        if (! (
                 solveData.nroots == refData.nroots
              && isEqual_d(solveData.x1, refData.x1) 
              && isEqual_d(solveData.x2, refData.x2)
              ) ) {

            _RED printf("Test #%d FAILED. For parametrs a = %lg  b = %lg  c = %lg\n",
                             testN,                    refData.a, refData.b, refData.c); _WHITE
                                          
            //print "expected" stroke
            print_switch(Expected, refData); 
            //print "got" stroke
            print_switch(Got, solveData);
            
            return false;
        }
        
        //else: got and referense mach: OK
        _GREEN printf("Test #%d passed.\n", testN); _WHITE
        return true;
}


void print_switch(const TypeNroots type, Data data){

      switch (data.nroots){
                  
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
                    
                          _RED printf("     %s 1 root x = %lg\n", str_type(type), data.x1); _WHITE
                    }
                    else{
                          
                          _RED printf("%s :1 root x = %lg\n", str_type(type), data.x1); _WHITE
                    }
                    
                    break;
                }
                
                case TWO_ROOT: {
                    
                    if (type == Got)
                    {
                        _RED printf("     " GOT "2 roots x1 = %lg x2 = %lg\n", data.x1, data.x2); _WHITE
                    } else 
                    { 
                          _RED printf("     " EXPECTED "2 roots x1 = %lg x2 = %lg\n", data.x1, data.x2); _WHITE
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
size_t readArgsF(FILE *file, Data** dataArr){

//input line must complains to format: "A B C N X1 X2\n" X1 can be not written if N = 0, X2 can be not written if N < 2, if eq has inf roots, write -1 insted N
      char line[MAXLEN] = {};
      
      size_t testsN = 0;
      for (; get_lineF(file, line, MAXLEN) > 1; testsN++){
      
          
          *dataArr = (Data*) realloc(*dataArr, sizeofDataStruct * (testsN + 1)); // very dolgo 
          
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
          
   //       printf("%lg %lg %lg \n--------------------\n", datatoRead.a, datatoRead.b, datatoRead.c);
          
          sortRoots(datatoRead);
      }
    for (int i = 0; i < testsN; i++){
          
          printf("%lg %lg %lg \n", (*dataArr)[i].a, (*dataArr)[i].b, (*dataArr)[i].c);
    }
      return testsN;
}


//-----------------------------------------------------------------------------------------------------------------------------------------
