#include <stdio.h>

#define INF -1


int squareSolve(double *coefs, double *roots);


int main(){
      
      printf("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0:\n");
      
      double coefs[] = {0, 0, 0}; // A B C
      double roots[] = {0, 0};
      
      scanf("%lg %lg %lg", coefs, coefs+1, coefs+2);   
      
      int nroots = squareSolve(coefs, roots);
      
      switch (nroots) {
      
          case 0: {
                printf("Equation has no roots.\n");
                break;
          }
          
          case 1: {
                printf("Equation has 1 root: x = %g.\n", roots[0]);
                break;
          }
          
          case 2: {
                printf("Equation has 2 roots: x1 = %g, x2 = %g.\n", roots[0], roots[2]);
                break;
          }
          
          case INF: {
                printf("Equation has infinity roots.\n");
                break;
          }
          
          default: {
                printf("Wrong input.\n");
                break;
          }
      }
      
      return 0;
}
