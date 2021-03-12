#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void isdiagonal(long dimension, long **matrix) {
    for (long i = 1; i < dimension; i += 1) {
        for (long j = 1; j < dimension; j += 1) {
            if (i != j) {
                if (matrix[i][j] != 0 || matrix[j][i] != 0) {
                    printf("Not diagonal \n");
                    return;
                }
            }
        } 
    }

    printf("Is diagonal \n");
}

void isUptriangular(long dimension, long **matrix) {
    for (long i = 0; i < dimension; i += 1) {
        for (long j = 0; j < i; j += 1) {
            if (matrix[i][j] != 0) {
                printf("Not upper triangular \n");
                return;
            }
        }
    }
    printf("Is upper triangular \n");
}


int main() {
    long dimension;
    scanf("%li", &dimension);

    long **matrix;
    matrix = malloc((size_t)dimension * sizeof(long));
    if (matrix != NULL) {
        for (long i = 0; i < dimension; i += 1) {
            matrix[i] = malloc((size_t)dimension * sizeof(long));
        }
        // check memory;
        for (long i = 0; i < dimension; i += 1) {
            if (matrix[i] == NULL) {
                for (long j = 0; j < dimension; j += 1) {
                    if (matrix[j] != NULL) {
                        free(matrix[j]);
                    }
                }
                free(matrix);
                printf("Error in memory allocation");
                return 1;
            }
        }
    }
    else {
        printf("Error in memory allocation");
        return 1;
    }
    for (long i = 0; i < dimension; i += 1) {
        for (long j = 0; j < dimension; j += 1) {
            scanf("%li", &matrix[i][j]);
        }
    }

    
    isdiagonal(dimension, matrix);

    isUptriangular(dimension, matrix);

    for (long j = 0; j < dimension; j += 1) {
        free(matrix[j]);
    }
    free(matrix);

    return 0;
}
