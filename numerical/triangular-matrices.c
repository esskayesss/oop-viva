#include <stdio.h>
#include <stdlib.h>


int*
triangular_matrix(int size, int sign){
    int *matrix = (int*)malloc(sizeof(int) * (size * size + 1));
    *(matrix++) = size;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(sign * (i - j) <= 0){
                printf("enter the value: ");
                scanf("%d", (matrix + i * size + j));
            }
            else 
                *(matrix + i * size + j) = 0;
        }
    }

    return matrix;
}

void print_square_matrix(int *matrix){
    int size = *(matrix - 1);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            printf("%d ", *(matrix + i*size + j));

        printf("\n");
    }
}

int main(int argc, char **argv){
    int size;
    int sign = -1;
    if(argc == 3){
        size = atoi(*(argv + 1));
        if(*(*(argv + 2)) == 'u')
            sign = 1;
    }

    printf("configured: size = %d | sign = %d\n", size, sign);

    int *matrix = triangular_matrix(size, sign);
    printf("calculated\n");
    print_square_matrix(matrix);
}
