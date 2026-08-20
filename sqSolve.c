#ifndef STDIO
#define STDIO

#include <stdio.h>

#endif 

#include <math.h>

#define INF -1

int squareSolve(double *coefs, double *roots){
      double a = *coefs, b = *(coefs+1), c = *(coefs+2);
      if (a == 0){ //A=0
      
            if (b == 0){ //B=0
                        
                  return (c == 0) ? INF : 0; //A=0 B=0 C?=0
            }
            else { //A=0 B!=0 C?=0
                  
                  *roots = -c/b;
                  return 1;
            }
      }
      else { //A!=0 B?=0 C?=0
            
            double D = b * b - 4.0 * a * c;
            
            if (D == 0){
            
                  *roots = -b / (2.0*a);
                  
                  return 1;
            }
            else if (D < 0) {
                  
                  return 0;
            }
            else {
            
                  *roots = (-b - sqrt(D)) / (2.0 * a); //x1
                  *(roots+1) = (-b + sqrt(D)) / (2.0 * a); //x2
                  
                  return 2;
            }
      }
}
