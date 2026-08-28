#include "./../headers/sqSolve.h"


//######INCIDE FUNCTIONS INITILIZATION######
Nroots linearSolve(const double a, const double b, double *x);
Nroots squareZeroC(const double a, const double b, Data *solveData);
Nroots normalSquare(const double a, const double b, const double c, Data *solveData);

/*

if (is_in_obshaga())
    if (is_not_hungry())
        if (is_not_sleeping))
            botat();
        else
            sleep();
    else
        eat();
else
    go();
return;

if (!1) 0 return
if (!2) 1 return
if (!3) 2 return

*/

//------------------------------------------------------------------------
/// Solves square equation Ax^2 + Bx + C = 0
///
/// @param[in]      Data params      "Data" structure with A, B, C parametrs
/// @param[out]     Data* solveData  Pointer to "Data" structure with results
///
//------------------------------------------------------------------------

void squareSolve(Data params, Data *solveData) {

      double a = params.a, 
             b = params.b,
             c = params.c;

      if (isZero_d(a)){ //A=0
      
            solveData -> nroots =  linearSolve(b, c, &(solveData -> x1));
            return;
      }
      //A!=0 
      if (isZero_d(c)){ //Ax^2 + Bx = 0 <=> x(Ax + B) = 0

             solveData -> nroots = squareZeroC(a, b, solveData);
             return;
      }

      solveData -> nroots =  normalSquare(a, b, c, solveData);
}



//------------------------------------------------------------------------
/// Solves equation AX + B = 0
///
/// @param[in]   double a    Parametr A
/// @param[in]   double b    Parametr B
/// @param[in]   double c    Parametr C
/// @param[out]  double* x   Pointer on root
///
/// @return Number of roots
///
//------------------------------------------------------------------------

Nroots linearSolve(const double a, const double b, double *x){

      if (isZero_d(a)){ //a=0

            return isZero_d(b) ? INF_ROOT
                               : ZERO_ROOT;
      } else { //a!=0
            
            *x = -b/a;
            return ONE_ROOT;
      }
}



//------------------------------------------------------------------------
/// Solves equation AX^2 + BX = 0
///
/// @param[in]   double a          Parametr A
/// @param[in]   double b          Parametr B
/// @param[in]   double c          Parametr C
/// @param[out]  Data* solveData   Pointer on "Data" structure with results
///
/// @return Number of roots
///
//------------------------------------------------------------------------

Nroots squareZeroC(const double a, const double b, Data *solveData){
      
         //   putchar('\n');
      solveData -> x1 = 0;
      linearSolve(a, b, &(solveData -> x2));
      
      //check x1=x2=0
      
     // printf("\nx1 %lg\nx2 %lg\n", roots -> x1, roots -> x2);
      
      if (isEqual_d(solveData -> x2, 0.0)) {
            
            solveData -> x2 = NAN;
            return ONE_ROOT;
      }
      
      sortRoots(solveData); 
      
      return TWO_ROOT;
}



//------------------------------------------------------------------------
/// Solves default square equation with discriminant
///
/// @param[in]   double a          Parametr A
/// @param[in]   double b          Parametr B
/// @param[in]   double c          Parametr C
/// @param[out]  Data* solveData   Pointer on "Data" structure with results
///
/// @return Number of roots
///
//------------------------------------------------------------------------

Nroots normalSquare(const double a, const double b, const double c, Data *solveData){
      
        //now its normal square equation
        //finding descrimiinant
        double discr = b * b - 4.0 * a * c;
        
        if (isZero_d(discr)){ //D == 0
              
              solveData -> x1 = -b / (2.0 * a);
              
              return ONE_ROOT;
        }
        else if (discr < 0) { //D < 0
              
              return ZERO_ROOT;
        }
        else { //D > 0
              double sqrt_D = sqrt(discr);
              solveData -> x1 = (-b - sqrt_D) / (2.0 * a); 
              solveData -> x2 = (-b + sqrt_D) / (2.0 * a);
              
              sortRoots(solveData);
              
              return TWO_ROOT;
        }
}
