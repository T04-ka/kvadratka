#include "parser.h"

void parser(void){

    char inputLine[MAXLEN] = {};

    Data coeffs = {.a = 0, .b = 0, .c = 0};

    int len = get_line(inputLine, MAXLEN);


   // printf("[%s]", inputLine);

    SideOfEq sideOfEq = LEFT;

    for (char *cptr = inputLine; *cptr != '\n' && *cptr != EOF && *cptr != '\0'; cptr++){

        if (*cptr == '=') {

            sideOfEq = RIGHT;
            continue;
        }

//      скип пробелов
        if (isspace(*cptr)){

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

            coeffs.c += sideOfEq * ((isNumberEx) ? temp : 0);
            cptr += endN;
        }
        else if (*(cptr + endN + 1) == '^'){

            coeffs.a += sideOfEq * ((isNumberEx) ? temp : 1);
            cptr += endN + 3;
        }
        else {

            coeffs.b += sideOfEq * ((isNumberEx) ? temp : 1);
            cptr += endN + 1;
        }
    }

    printf("A: %lg, B: %lg, C: %lg\n", coeffs.a, coeffs.b, coeffs.c);
}


