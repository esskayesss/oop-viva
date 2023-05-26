#include <stdio.h>
#include <math.h>

float f(float x){
  return x * x * x * x * x - 2;
}

void bisection(float *x, float a, float b, int *itr){
  *x = (a + b) / 2;
  (*itr)++;
  printf("Iteration no. %d, x = %f\n", *itr, *x);
}

int main(){
  int itr = 0, maxitr;
  float x, a, b, e, x1;
  printf("Enter the values of a, b, allowed error and maximum iterations:\n");
  scanf("%f %f %f %d", &a, &b, &e, &maxitr); 
  bisection(&x, a, b, &itr); 
  do{
    if (f(a) * f(x) < 0){
      b = x; 
    }
    else{
      a = x;
    }
    bisection(&x1, a, b, &itr); 
    if (fabs(x1 - x) < e){
      printf("After %d iterations, root = %f\n", itr, x1); 
      return 0; 
    }
    x = x1;
  } while (itr < maxitr); 
  printf("The solution does not converge or iterations are not sufficient\n"); 
  return 1; 
}
