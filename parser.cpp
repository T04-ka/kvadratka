#include "parser.h"
#include "enums.h"
#include "in-output.h"
#include "sqSolve.h"


Errors parse(Data *coeffs);

void spaceDel(char *s);


///RUNING THE PARSE PROGRAM
void runParse(void){

    _WHITE print("Enter polynomial or equation.\n");

    while (1){
        Data coeffs = {.a = 0, .b = 0, .c = 0};


        if (Errors error = parse(&coeffs)) {

            printErrors(error);
        }
        else{

            Data roots = {.nroots = ZERO_ROOT, .x1 = NAN, .x2 = NAN};

            squareSolve(coeffs, &roots);

            printRes(roots);
          //  printf("A: %lg, B: %lg, C: %lg\n", coeffs.a, coeffs.b, coeffs.c);
        }
    }
}


//------------------------------------------------------------------
///PARSING THE STROKE
Errors parse(Data *coeffs){

    char inputLine[MAXLEN] = {};

    int len = get_line(inputLine, MAXLEN);
    if (len < 1){

        return EMPTY_INPUT;
    }
   // spaceDel(inputLine);

    if (*(inputLine) == '\0') {

        return EMPTY_INPUT;
    }
    //printf("[%s]\n", inputLine);
    SideOfEq sideOfEq = LEFT;

    int sign = 1, isSignEx = true;

    for (char *cptr = inputLine; *cptr != '\n' && *cptr != EOF && *cptr != '\0'; cptr++){
        //printf("%d\n", cptr - inputLine);

        if (isspace(*cptr)) {

            continue;
        }

        if (*cptr == '=') {
            sideOfEq = RIGHT;
            CHECKSIGNEX
        }

        if (*cptr == '+') {

            CHECKSIGNEX
        }

        if (*cptr == '-') {

            sign = -1;
            CHECKSIGNEX
        }

        double temp = 0;

        bool isNumberEx = true;

        int endN = 0;

        //проверка наличия коэфициента, если его нет, то он равен единице
        if (!sscanf(cptr, "%lg%n", &temp, &endN)) {

            isNumberEx = false;
        }

        if (isNumberEx && temp < 1 && *cptr != '0' ||
            isNumberEx && !isSignEx)
        {

            return INPUT_ERROR;
        }
        /*
        //      скип знака *
        if (*(cptr + endN) == '*'){

            endN ++;
        }
        */

        if (*(cptr + endN) != 'X' && *(cptr + endN) != 'x'){

            if (!isNumberEx) {

                return INPUT_ERROR;
            }

            coeffs -> c += sign * sideOfEq * temp;
              //printf("*cptr: %c, temp = %lg, sign = %d, sideOfEq = %d ", *cptr, temp, sign, sideOfEq);
            cptr += endN-1;
             // printf("*cptr: %c\n", *cptr);
            SETDEFAUTLT
        }
        else if (*(cptr + endN + 1) == '^' && *(cptr + endN + 2) == '2') {

            coeffs -> a += sign * sideOfEq * ((isNumberEx) ? temp : 1);
             // printf("*cptr: %c, temp = %lg, sign = %d, sideOfEq = %d ", *cptr, temp, sign, sideOfEq);
            cptr += endN + 2;
             // printf("*cptr: %c\n", *cptr);
            SETDEFAUTLT
        }
        else {

            coeffs -> b += sign * sideOfEq * ((isNumberEx) ? temp : 1);
            // printf("*cptr: %c, temp = %lg, sign = %d, sideOfEq = %d ", *cptr, temp, sign, sideOfEq);
            cptr += endN;
        //     printf("*cptr: %c\n", *cptr);
            SETDEFAUTLT
        }


    }
    return NO_ERROR;
}


//----------------------------------------------------------------------
///DELETES ALL SPASES FROM STROKE
void spaceDel(char *s){
    int j = 0;
    for (int i = 0; s[i] != EOF && s[i] != '\n' && s[i] != '\0'; i++){

        if (!isspace(s[i])){

            s[j++] = s[i];
        }
    }

    s[j] = '\0';
}
