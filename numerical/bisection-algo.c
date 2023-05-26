#include <stdio.h>
#include <math.h>

// Define the function to be solved
float f(float x)
{
  return x * x * x - 4 * x - 9;
}

// Perform one iteration of bisection method
void bisection(float *x, float a, float b, int *itr)
{
  *x = (a + b) / 2; // Find the mid point
  (*itr)++; // Increment the iteration count
  printf("Iteration no. %d, x = %f\n", *itr, *x);
}

int main()
{
  int itr = 0, maxitr; // Iteration variables
  float x, a, b, e, x1; // Interval and error variables
  printf("Enter the values of a, b, allowed error and maximum iterations:\n");
  scanf("%f %f %f %d", &a, &b, &e, &maxitr); // Input values
  bisection(&x, a, b, &itr); // Perform first iteration
  do
  {
    if (f(a) * f(x) < 0) // Check if root lies in left subinterval
    {
      b = x; // Update right endpoint
    }
    else // Otherwise root lies in right subinterval
    {
      a = x; // Update left endpoint
    }
    bisection(&x1, a, b, &itr); // Perform next iteration
    if (fabs(x1 - x) < e) // Check if error is within tolerance
    {
      printf("After %d iterations, root = %f\n", itr, x1); // Print the root
      return 0; // Exit the program
    }
    x = x1; // Update the current approximation
  } while (itr < maxitr); // Repeat until maximum iterations are reached
  printf("The solution does not converge or iterations are not sufficient\n"); // Print error message
  return 1; // Exit the program with error code
}
