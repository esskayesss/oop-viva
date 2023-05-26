#include <stdio.h>

double f(double x){
    return x*x;
}

double integrand(double a, double b, int interval){
    double height = (b - a)/interval;
    double sum = f(a);
    int count = 1;
    while(a + height < b){
        a += height;
        if(count % 2 == 1){
            sum += 4 * f(a);
        }else { 
            sum += 2 * f(a);    
        }
        count++;
    }

    sum += f(b);
    return height / 3 * sum;
}

int main(){
    double lower, upper, interval;
    printf("enter the values for the lower and upper limits and also the interval: ");
    scanf("%lf %lf %lf", &lower, &upper, &interval);
    
    double sum = 0;
    printf("%lf\n", integrand(lower, upper, interval));
}

