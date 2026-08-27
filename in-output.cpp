#include "bin/in-output.h"



//----------------------------------------------------------------------------
/// Reads user's answear about continuation of program
///
/// @returns true if user wanted to continue program,
///          false if wanted to stop
///
//----------------------------------------------------------------------------

bool readAnswear(void){  
      
      //asking person until get the answer or program ends by him
      int c = getchar();
      
      //clearing input buffer (if needed)
      clearBuffer(c);
      
      //anal answear
      switch (c){
            
            case STOPSYMB: {
            
                  return false;
            }
            
            default: {
            
                  return true;
            }
      }
}



//----------------------------------------------------------------------------
/// Reads input parametrs from stdin
///
/// @param[in]    const char type_param    Type of parametr (A, B, C)
/// @param[out]   double* param            Pointer on var that parametr need to be written in
///
/// @return true if param has written,
///         false if user stoped input (Ctrl + D)
///
/// @note Prints prints error message if input was wrong and
///       repeats input until correct parametr will be written.
///
//----------------------------------------------------------------------------

bool readParam(const char type_param, double* param){

      Errors input_error = EMPTY_INPUT;
      do {  
            _WHITE slowPrint("\nPlease, enter parametr %c: ", type_param); //space for entering the param
              
            char line[MAXLEN] = {}; //space for input line
            int len = get_line(line, MAXLEN); //taking line from input stream            
            
            //###ENDOFINPUT CHECK###
            if (len == 0){
                  
                  printErrors(EMPTY_INPUT);
                  return true;
            } 
            
            //ERROR CHECK and taking param from line
            input_error = readDouble(line, param);
            
            if (input_error){
            
                  printErrors(input_error);      
            }      
                  
      } while (input_error); //stoping cicl if no errors
      return false;
}



//----------------------------------------------------------------------------
/// Prints error message
///
/// @param[in]    Errors error      Type of error
///
//----------------------------------------------------------------------------

void printErrors(Errors error){
      switch (error) {
          
          case EMPTY_INPUT: {
                _RED slowPrint("\nError: empty input.\n"); _WHITE
                break;
          }
          
          case INPUT_ERROR: {
                _RED slowPrint("\nError: wrong input.\n"); _WHITE
                break;
          }
          
         case NO_ERROR: {break;}

         default: {}
      }
}



//----------------------------------------------------------------------------
/// Prints result of equations solving
///
/// @param[in]    Data roots    "Data" structure with solving results
///
//----------------------------------------------------------------------------

void printRes(Data roots){
    //  assert(roots);
      
      switch (roots.nroots) {
      
          case ZERO_ROOT: {
                _YELLOW slowPrint("\nEquation has no roots.\n"); _WHITE
                break;
          }
          
          case ONE_ROOT: {
                _YELLOW slowPrint("\nEquation has 1 root: x = %g.\n", roots.x1); _WHITE
                break;
          }
          
          case TWO_ROOT: {
                _YELLOW slowPrint("\nEquation has 2 roots: x1 = %g, x2 = %g.\n", roots.x1, roots.x2); _WHITE
                break;
          }
          
          case INF_ROOT: {
                _YELLOW slowPrint("\nEquation has infinity roots.\n"); _WHITE
                break;
          }
          
          default: {}
      }
}



//----------------------------------------------------------------------------
/// Reading line from input stream
///
/// @param[in]     int mxlen   Maximum possible len of input line
/// @param[out]    char *s     Stroke where symbols from input are written
///
/// @return Lenth of entered stroke
///
/// @note Puts '\0' on every stroke end
//----------------------------------------------------------------------------

int get_line(char *s, int mxlen){
      
      int c = 0;
      int len = 0;
      
      while ((c = getchar()) != '\n' && c != EOF && len < mxlen){
            
            s[len++] = (char) c;
      }

      
      if (c == '\n') {
      
            s[len++] = (char) c;
      }
      
      s[len] = '\0';
      
      return len;      
}



//-------------------------------------------------------------------------
/// Reading line from file
///
/// @param[in]     int mxlen   Maximum possible len of input line
/// @param[out]    char *s     Stroke where symbols from input are written
///
/// @return Lenth of entered stroke
///
/// @note Puts '\0' on every stroke end
///
//-------------------------------------------------------------------------

int get_lineF(FILE *pfile, char *s, int maxlen){
    
    int c = 0, len = 0;
    while ((c = getc(pfile)) != EOF && c != '\n' && len < maxlen){
        
        s[len++] = (char) c;
    }
    
    if (c == '\n') {
        
        s[len++] = (char) c;
    }
    
    s[len] = '\0';
    
    return len;
}



//--------------------------------------------------------------------------
/// Make the slow output
///
/// @param[in]    const char *format      A stroke with output format
/// @paramp[in]   ...                     Variables for output
///
/// @note Puts every symbol with delation, defined in header file.
///
//-------------------------------------------------------------------------

void slowPrint(const char *format, ...){
      
      va_list argptr;
      
      va_start(argptr, format);
      
      char lineOfData[PRINTSIZE] = {};      
      
      vsprintf(lineOfData, format, argptr);      
      
      va_end (argptr);
      
      char *lineptr = lineOfData;
      
      while(*lineptr != '\0'){
          
          for (int nltr = rand() % 3 + 3; nltr > 0; nltr--){
          
                putchar(*(lineptr++));
                fflush(stdout);
          }
          
          nanosleep(&SLEEPTIME, NULL);
      }    
}


//-------------------------------------------------------------
