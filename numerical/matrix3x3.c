#include <stdio.h>

double determinant(double matrix[3][3]) {
    double a = matrix[0][0],
    b = matrix[0][1],
    c = matrix[0][2],
    d = matrix[1][0],
    e = matrix[1][1],
    f = matrix[1][2],
    g = matrix[2][0],
    h = matrix[2][1],
    i = matrix[2][2];

    double det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
    return det;
}

int main() {
    double matrix[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            scanf("%lf", &matrix[i][j]);
    printf("The determinant of the matrix is %f\n", determinant(matrix));

    return 0;
}
