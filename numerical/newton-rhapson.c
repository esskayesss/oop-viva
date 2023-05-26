// Program to implement Newton-Raphson method in C
#include <stdio.h>
#include <math.h>

double f(double x) {
  return 3 * x - cos(x) - 1; 
}

double g(double x) {
  return 3 + sin(x); 
}

double newton_raphson(double x0, double e, int N) {
  int i = 1; 
  double x1, ea; 
  do {
    double fx0 = f(x0); 
    double gx0 = g(x0); 
    if (gx0 == 0) { 
      printf("Mathematical Error.\n"); 
      return 0;
    }
    printf("%lf\n", x0);
    x1 = x0 - fx0 / gx0; 
    ea = fabs((x1 - x0) / x1) * 100; 
    x0 = x1; 
    i++; 
  } while (ea > e && i <= N); 
  if (ea < e) { // Check if error is less than tolerance
    return x1; 
  }
  else { 
    printf("Not Convergent.\n"); 
    return 0;
  }
}

int main() {
  double x0 = 2.0;
  double e = 0.0001;
  int N = 20;
  double root = newton_raphson(x0, e, N);
  printf("Root is: %f\n", root);
  return 0;
}
