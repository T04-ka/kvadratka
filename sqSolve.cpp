#include "sqSolve.h"

//######INCIDE FUNCTIONS INITILIZATION######
Nroots linearSolve(const double a, const double b, double *x);


//###SOLVING SQUARE EQUATION Ax^2+Bx+C=0###
Nroots squareSolve(const double *coefs, double *roots){

      double a = *coefs, b = *(coefs+1), c = *(coefs+2);
   //   *roots = *(roots + 1) = NAN; //set roots in default NAN value

      if (is_zero(a)){ //A=0
      
            return linearSolve(b,c,roots);
      }
      else { //A!=0 
            
            if (is_zero(c)){ //Ax^2 + Bx = 0 <=> x(Ax + B) = 0

                  *roots = 0;
                  linearSolve(a,b,roots+1);
                  return TWO_ROOT;
            }

            //now its normal square equation
            //finding descrimiinant
            double D = b * b - 4.0 * a * c;
            
            if (is_zero(D)){ //D == 0
            
                  *roots = -b / (2.0*a);
                  
                  return ONE_ROOT;
            }
            else if (D < 0) { //D < 0
                  
                  return ZERO_ROOT;
            }
            else { //D > 0
            
                  *roots = (-b - sqrt(D)) / (2.0 * a); //x1
                  *(roots+1) = (-b + sqrt(D)) / (2.0 * a); //x2
                  
                  return TWO_ROOT;
            }
      }
}

//###GIVE SOLUTION FOR EQUATION AX+B=0###
Nroots linearSolve(const double a, const double b, double *x){

      if (is_zero(a)){ //a=0

            return is_zero(b) ? INF_ROOT
                              : ZERO_ROOT;
      } else { //a!=0
            
            *x = -b/a;
            return ONE_ROOT;
      }
}