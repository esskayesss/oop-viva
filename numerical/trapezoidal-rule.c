#include <stdio.h>

double f(double x){
    return x * x;
}

double integrand(double a, double b, int steps){
    double height = (b - a)/steps;
    double sum = f(a) + f(b);
    a += height;
    for(;a < b; a += height)
        sum += 2 * f(a);

    return sum * height / 2;
}

int main(){
    double lower, upper;
    int steps;

    scanf("%lf %lf %d", &lower, &upper, &steps);
    printf("%lf\n", integrand(lower, upper, steps));
}
