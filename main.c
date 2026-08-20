#include <stdio.h>

#define INF -1
#define ERR -2
#define EMPTY -3

int squareSolve(double *coefs, double *roots);
void printRes(double *roots, int nroots);


int main(){
      
      printf("Enter data: \"A B C\" for equation A*x^2 + B*x + c = 0:\n");
      
      double coefs[] = {0, 0, 0}; // A B C
      double roots[] = {0, 0};
      
      char input = scanf("%lg %lg %lg", coefs, coefs+1, coefs+2);   
      
      int nroots = (input == 0) ? ERR : (input == EOF) ? EMPTY : squareSolve(coefs, roots);
      
      printRes(roots, nroots);
        
      return 0;
}

void printRes(double *roots, int nroots){
      
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
          
          case EMPTY: {
                printf("Error: empty input.\n");
                break;
          }
          
          default: {
                printf("\nError: wrong input.\n");
                break;
          }
      }
}
