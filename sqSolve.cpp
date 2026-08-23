#include "sqSolve.h"


//######INCIDE FUNCTIONS INITILIZATION######
Nroots linearSolve(const double a, const double b, double *x);
Nroots squareZeroC(const double a, const double b, Roots *roots);
Nroots normalSquare(const double a, const double b, const double c, Roots *roots);

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

///##SOLVING SQUARE EQUATION Ax^2+Bx+C=0###
Nroots squareSolve(Coeffs coeffs, Roots *roots) {

      double a = coeffs.a, 
             b = coeffs.b,
             c = coeffs.c;
      roots -> x1 = roots -> x2 = NAN; //set roots in default NAN value

      if (isZero_d(a)){ //A=0
      
            return linearSolve(b, c, &(roots -> x1));
      }
      //A!=0 
      if (isZero_d(c)){ //Ax^2 + Bx = 0 <=> x(Ax + B) = 0

             return squareZeroC(a, b, roots);
      }

      return normalSquare(a, b, c, roots);
}


//--------------------------------------------------------------
///GIVE SOLUTION FOR EQUATION AX+B=0###
Nroots linearSolve(const double a, const double b, double *x){

      if (isZero_d(a)){ //a=0

            return isZero_d(b) ? INF_ROOT
                                     : ZERO_ROOT;
      } else { //a!=0
            
            *x = -b/a;
            return ONE_ROOT;
      }
}


//----------------------------------------------------------------
///Solving part of square equation with C=0 
Nroots squareZeroC(const double a, const double b, Roots *roots){
      
         //   putchar('\n');
      roots -> x1 = 0;
      linearSolve(a, b, &(roots -> x2));
      
      //check x1=x2=0
      
     // printf("\nx1 %lg\nx2 %lg\n", roots -> x1, roots -> x2);
      
      if (isEqual_d(roots -> x2, 0.0)) {
            
            roots -> x2 = NAN;
            return ONE_ROOT;
      }
      
      sortRoots(roots); 
      
      return TWO_ROOT;
}


//-------------------------------------------------------------------------------------
///SOLVING NORMAL SQUARE, WHERE DISCRIMINANT NEDEED
Nroots normalSquare(const double a, const double b, const double c, Roots *roots){
      
        //now its normal square equation
        //finding descrimiinant
        double D = b * b - 4.0 * a * c;
        
        if (isZero_d(D)){ //D == 0
              
              roots -> x1 = -b / (2.0 * a);
              
              return ONE_ROOT;
        }
        else if (D < 0) { //D < 0
              
              return ZERO_ROOT;
        }
        else { //D > 0
        
              roots -> x1 = (-b - sqrt(D)) / (2.0 * a); 
              roots -> x2 = (-b + sqrt(D)) / (2.0 * a);
              
              sortRoots(roots);
              
              return TWO_ROOT;
        }
}
