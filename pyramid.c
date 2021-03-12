#include <stdio.h>
#include <stdlib.h>


void maximum_path_value(long num_rows, long **pyramid_array) {
    for (long i = num_rows - 2; i >= 0; i -= 1) {
        for (long j = 0; j <= i; j += 1) {
            if (pyramid_array[i + 1][j] > pyramid_array[i + 1][j + 1]) {
                pyramid_array[i][j] += pyramid_array[i + 1][j];
            }
            else {
                pyramid_array[i][j] += pyramid_array[i + 1][j + 1];
            }
        }
    }

    printf("%li \n", pyramid_array[0][0]);
}


int main() {
    long num_rows;
    scanf("%li", &num_rows);

    long **pyramid_array;
    pyramid_array = malloc((size_t)num_rows * sizeof(long *));
    if (pyramid_array != NULL) {
        for (long i = 0; i < num_rows; i += 1) {
            pyramid_array[i] = malloc((size_t)(i + 1) * sizeof(long));
        }

        for (long i = 0; i < num_rows; i += 1) {
            if (pyramid_array[i] == NULL) {
                for (long j = 0; j < num_rows; j += 1) {
                    if (pyramid_array[j] !=  NULL) {
                        free(pyramid_array[j]);
                    }
                }
                free(pyramid_array);
                printf("Error allocating memory");
                return 1;
            }
        }
        for (long i = 0; i < num_rows; i += 1)  {
            for (long j = 0; j < i + 1; j += 1) {
                scanf("%li", &pyramid_array[i][j]);
            }
        }
        maximum_path_value(num_rows, pyramid_array);
        for (long i = 0; i < num_rows; i += 1) {
            free(pyramid_array[i]);
        }
        free(pyramid_array);
    }

    else {
        printf("Error in allocating memory \n");
        return 1;
    }
    return 0;
}
