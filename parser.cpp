#include "parser.h"
#include "enums.h"


Errors parse(Data *coeffs);

void spaceDel(char *s);


///RUNING THE PARSE PROGRAM
void runParse(void){

    Data coeffs = {.a = 0, .b = 0, .c = 0};

    Errors err = parse(&coeffs);

    // switch err

    printf("A: %lg, B: %lg, C: %lg\n", coeffs.a, coeffs.b, coeffs.c);
}


//------------------------------------------------------------------
///PARSING THE STROKE
Errors parse(Data *coeffs){

    char inputLine[MAXLEN] = {};

    int len = get_line(inputLine, MAXLEN);
    if (len < 1){

        return EMPTY_INPUT;
    }
    spaceDel(inputLine);
   //  printf("[%s]\n", inputLine);
    SideOfEq sideOfEq = LEFT;

    int sign = 1;

    for (char *cptr = inputLine; *cptr != '\n' && *cptr != EOF && *cptr != '\0'; cptr++){

        if (*cptr == '=') {

            sideOfEq = RIGHT;
            continue;
        }

        if (*cptr == '+') {

            continue;
        }

        if (*cptr == '-') {

            sign = -1;
            continue;
        }

        double temp = 0;

        bool isNumberEx = true;

        int endN = 0;

        //проверка наличия коэфициента, если его нет, то он равен единице
        if (!sscanf(cptr, "%lg%n", &temp, &endN)) {

            isNumberEx = false;
        }

        //      скип знака *
        if (*(cptr + endN) == '*'){

            endN ++;
        }


        if (*(cptr + endN) != 'X' && *(cptr + endN) != 'x'){

            coeffs -> c += sign * sideOfEq * ((isNumberEx) ? temp : 0);
            // printf("*cptr: %c, temp = %lg, sign = %d, sideOfEq = %d ", *cptr, temp, sign, sideOfEq);
            cptr += endN-1;
            // printf("*cptr: %c\n", *cptr);
            sign = 1;
        }
        else if (*(cptr + endN + 1) == '^'){

            coeffs -> a += sign * sideOfEq * ((isNumberEx) ? temp : 1);
            // printf("*cptr: %c, temp = %lg, sign = %d, sideOfEq = %d ", *cptr, temp, sign, sideOfEq);
            cptr += endN + 2;
            // printf("*cptr: %c\n", *cptr);

            sign = 1;
        }
        else {

            coeffs -> b += sign * sideOfEq * ((isNumberEx) ? temp : 1);
            // printf("*cptr: %c, temp = %lg, sign = %d, sideOfEq = %d ", *cptr, temp, sign, sideOfEq);
            cptr += endN;
            // printf("*cptr: %c\n", *cptr);
            sign = 1;
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
