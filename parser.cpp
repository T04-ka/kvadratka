#include "bin/parser.h"

//######INITIALIZATION######
Errors parse(Data *coeffs);

void spaceDel(char *s);



//-------------------------------------------------------------------------
/// Runs "Parse" part of program
///
//-------------------------------------------------------------------------

void runParse(void){

    do
    {
        _WHITE slowPrint("Enter polynomial or equation.\n");

        Data coeffs = {.a = 0, .b = 0, .c = 0};


        if (Errors error = parse(&coeffs)) {

            printErrors(error);
        }
        else{

            Data roots = {.nroots = ZERO_ROOT, .x1 = NAN, .x2 = NAN};

            squareSolve(coeffs, &roots);

            printRes(roots);

           //printf("A: %lg, B: %lg, C: %lg\n", coeffs.a, coeffs.b, coeffs.c);
        }
        _WHITE slowPrint("Enter 'q' if you want to quit the program: ");

    } while(readAnswear()); //SUKA BLYAT DOBAVIT VVOD FRAZI
}



//-------------------------------------------------------------------------
/// Reads stroke from input stream and parses it
///
/// @param[out]    Data* coeffs    Pointer on "Data" structure with coefficients
///
/// @return INPUT_ERROR if input was wrong,
///         EMPTY_INPUT if input was empty,
///         NO_ERROR if input was correct;
///
/// @note Go along the line and analyse symbols:
///          1. Skip the spaces,
///          2. Check equation side "switch",
///          3. Check signs '+' and '-',
///          4. Scan the number (if exist),
///          5. Check that only correct case had written,
///          6. Write the coefficient
///
//-------------------------------------------------------------------------

#define SETARG(A)                                                                        \
                        coeffs -> A += sign * sideOfEq * ((isNumberEx) ? temp : 1);      \
                        cptr += endN + ((#A[0] == 'a') ? 2 : (#A[0] == 'b') ? 0 : -1);   \
                        sign = 1;                                                        \
                        isSignEx = false;                                                \
                        isEqWasPrev = true;                                              \
                        continue;


//------------------------------------------------------------------------
#define CHECKSIGNEX if (isSignEx && !isEqWasPrev && cptr - inputLine != 0) {         \
                        return INPUT_ERROR;                                          \
                    }                                                                \
                    isSignEx = true;                                                 \
                    isEqWasPrev = false;


//------------------------------------------------------------------------
/// PARSE THE STROKE
Errors parse(Data *coeffs){

    char inputLine[MAXLEN] = {};

    if (get_line(inputLine, MAXLEN) < 1){

        return EMPTY_INPUT;
    }
    // spaceDel(inputLine);

    if (*(inputLine) == '\0') {

        return EMPTY_INPUT;
    }
   // printf("[%s]\n", inputLine);
    SideOfEq sideOfEq = LEFT;

    int sign = 1, isSignEx = true, isEqWasPrev = false;

    for (char *cptr = inputLine; *cptr != '\n' && *cptr != EOF && *cptr != '\0'; cptr++){
        // printf("%d\n", cptr - inputLine);

        if (isspace(*cptr)) {

            continue;
        }

        if (*cptr == '=') {
            sideOfEq = RIGHT;
            CHECKSIGNEX
            isEqWasPrev = true;
            continue;
        }

        if (*cptr == '+') {
            CHECKSIGNEX
            continue;
        }

        if (*cptr == '-') {

            sign = -1;
            CHECKSIGNEX
            continue;
        }

        double temp = 0;

        bool isNumberEx = true;

        int endN = 0;

        //проверка наличия коэфициента
        if (!sscanf(cptr, "%lg%n", &temp, &endN)) {

            isNumberEx = false;
        }

        //проверка на .99 && 2 2 2 2
        if ((isNumberEx && temp < 1 && *cptr != '0') ||
            (isNumberEx && !isSignEx))
        {

            return INPUT_ERROR;
        }

        if (*(cptr + endN) != 'X' && *(cptr + endN) != 'x'){

            if (!isNumberEx) { //проверка на весь мусор

                return INPUT_ERROR;
            }
            SETARG(c)
        }
        else if (*(cptr + endN + 1) == '^' && *(cptr + endN + 2) == '2') { //проверка на ^2

            SETARG(a)
        }
        else {

            SETARG(b)
        }
    }
    return NO_ERROR;
}
#undef SETURG
#undef CHECKSIGNEX


//------------------------------------------------------------------------
