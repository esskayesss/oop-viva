#include <stdio.h>
#include <stdlib.h>


double 
interpolating_factor(double *x, int size, int k, double target){
    double factor = 1;
    for(int i = 0; i < size; i++){
        if (i == k) continue;
        factor *= (target - *(x + i))/(*(x + k) - *(x + i));
    }

    return factor;
}

int 
main(){
    int n;
    printf("enter the number of records: ");
    scanf("%d", &n);

    double *x, *y;
    x = (double *)malloc(sizeof(double) * n);
    y = (double *)malloc(sizeof(double) * n);

    for(int i = 0; i < n; i++){
        printf("enter the x and y values for record #%d: ", i + 1);
        scanf("%lf %lf", x + i, y + i);
    }

    double target;
    printf("enter the target value of x: ");
    scanf("%lf", &target);

    double f_target = 0;
    for(int i = 0; i < n; i++){
        double factor = interpolating_factor(x, n, i, target);
        printf("%lf += %lf * %lf\n", f_target, *(y + i), factor);
        f_target += *(y + i) * factor;
    }

    printf("the approximate value is: %lf\n", f_target);
}
