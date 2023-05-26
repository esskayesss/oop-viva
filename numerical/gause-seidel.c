#include <stdio.h>
#include <limits.h>

#define f1(y, z) (17 - y + 2*z)/20
#define f2(x, z) (-18 -3*x + z)/20
#define f3(y, z) (25 - 2*x + 3*y)/20

int
main(){
    double tolerance_error;
    printf("enter the tolerance error: ");
    scanf("%lf", &tolerance_error);

    double x = 0, y = 0, z = 0;
    double ex = INT_MAX, ey = INT_MAX, ez = INT_MAX;
    while(ex > tolerance_error && ey > tolerance_error && ez > tolerance_error) {
        double x1 = f1(y, z);
        double y1 = f2(x1, z);
        double z1 = f3(x1, y1);

        ex = x1 - x;
        ey = y1 - y;
        ez = z1 - z;
        x = x1;
        y = y1;
        z = z1;
    }

    printf("x = %lf\ny= %lf\nz= %lf\n", x, y, z);
}
