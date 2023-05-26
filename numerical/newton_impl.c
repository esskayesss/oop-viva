#include <stdio.h>
#include <stdlib.h>

float *
forward_propagate(float *y){
    int n = *(y-1);
    float *dely = (float*)malloc(sizeof(float)*(n));
    *(dely++) = n - 1;
    for(int i = 0; i < n - 1; i++){
        *(dely + i) = *(y + i + 1) - *(y + i);
    }
    free(y - 1);
    return dely;
}

int main(){
    int n_entries;
    printf("enter the number of x values: ");
    scanf("%d", &n_entries);

    float *x = (float*)malloc(sizeof(float) * n_entries);
    float *y = (float*)malloc(sizeof(float) * (n_entries+1));

    *(y++) = n_entries;

    printf("enter the value of x and their corresponding value for y.\n");
    for(int i = 0; i < n_entries; i++){
        scanf("%f%f", x + i, y + i);
    }

    float x_target;
    printf("enter the value of x for the query: ");
    scanf("%f", &x_target);

    float height = *(x + 1) - *x;
    float p = (x_target - *x)/height;

    float f_x = 0;
    float factor = 1;

    for(int i = 1; i <= n_entries; i++){
        printf("%f * %f\n", factor, *y);
        f_x += factor * (*y);
        factor *= p--/i;
        y = forward_propagate(y);
    }

    printf("%f\n", f_x);
}
