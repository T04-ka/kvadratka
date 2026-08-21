#include "sqSolve.h"


Nroots squareSolve(const double *coefs, double *roots){
      double a = *coefs, b = *(coefs+1), c = *(coefs+2);
      if (is_zero(a)){ //A=0
      
            if (is_zero(b)){ //B=0
                        
                  return (is_zero(c)) ? INF_ROOT : ZERO_ROOT; //A=0 B=0 C?=0
            }
            else { //A=0 B!=0 C?=0
                  
                  *roots = -c/b;
                  return ONE_ROOT;
            }
      }
      else { //A!=0 B?=0 C?=0
            
            double D = b * b - 4.0 * a * c;
            
            if (is_zero(D)){
            
                  *roots = -b / (2.0*a);
                  
                  return ONE_ROOT;
            }
            else if (D < 0) {
                  
                  return ZERO_ROOT;
            }
            else {
            
                  *roots = (-b - sqrt(D)) / (2.0 * a); //x1
                  *(roots+1) = (-b + sqrt(D)) / (2.0 * a); //x2
                  
                  return TWO_ROOT;
            }
      }
}

//-------------------------------------------------

bool is_zero(double x){
      
      if (x > 0){
            
            return (x < ZERO_BORDER) ? true
                                     : false;
      }
      else{
      
            return (x > -ZERO_BORDER) ? true
                                      : false;
      }
}

