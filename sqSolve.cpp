#include "sqSolve.h"

//######INCIDE FUNCTIONS INITILIZATION######
Nroots linearSolve(const double a, const double b, double *x);
Nroots squareZeroC(const double a, const double b, double *roots);
Nroots normalSquare(const double a, const double b, const double c, double *roots);

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

//###SOLVING SQUARE EQUATION Ax^2+Bx+C=0###
Nroots squareSolve(const double *coefs, double *roots){

      double a = *coefs, 
             b = *(coefs + 1),
             c = *(coefs + 2);
      *roots = *(roots + 1) = NAN; //set roots in default NAN value

      if (isEqual_d(a, 0.0)){ //A=0
      
            return linearSolve(b, c, roots);
      }
      //A!=0 
      if (isEqual_d(c, 0.0)){ //Ax^2 + Bx = 0 <=> x(Ax + B) = 0

             return squareZeroC(a, b, roots);
      }

      return normalSquare(a, b, c, roots);
}

//###GIVE SOLUTION FOR EQUATION AX+B=0###
Nroots linearSolve(const double a, const double b, double *x){

      if (isEqual_d(a, 0.0)){ //a=0

            return isEqual_d(b, 0.0) ? INF_ROOT
                                     : ZERO_ROOT;
      } else { //a!=0
            
            *x = -b/a;
            return ONE_ROOT;
      }
}

Nroots squareZeroC(const double a, const double b, double *roots){
      
      *roots = 0;
      linearSolve(a, b, roots + 1);
      
      //check x1=x2=0
      if (isEqual_d(*(roots + 1), 0.0)){
            
            *(roots + 1) = NAN;
            return ONE_ROOT;
      }
      
      sortRoots(roots);
      return TWO_ROOT;
}

Nroots normalSquare(const double a, const double b, const double c, double *roots){
      
        //now its normal square equation
        //finding descrimiinant
        double D = b * b - 4.0 * a * c;
        
        if (isEqual_d(D, 0.0)){ //D == 0
              
              *roots = -b / (2.0 * a);
              
              return ONE_ROOT;
        }
        else if (D < 0) { //D < 0
              
              return ZERO_ROOT;
        }
        else { //D > 0
        
              *roots = (-b - sqrt(D)) / (2.0 * a); //x1
              *(roots+1) = (-b + sqrt(D)) / (2.0 * a); //x2
              
              sortRoots(roots);
              return TWO_ROOT;
        }
}
