#include <stdio.h>
#include <stdlib.h>


long kadane(long length, long *array) {
    long max = array[0];
    long local_max = array[0];
    for (long i = 1; i < length; i += 1) {
        if (local_max + array[i] > array[i]) {
            local_max += array[i];
        }
        else {
            local_max = array[i];
        }
        if (local_max > max) {
            max = local_max;
        }
    }
    return max;
}


int main() {
    long length;
    scanf("%li", &length);

    long *array = malloc((size_t)length * sizeof(long));
    if (array != NULL) {
        for (long i = 0; i < length; i += 1) {
            scanf("%li", &array[i]);
        }
    }
    else {
        printf("Error allocating memory \n");
        return 1;
    }

    long sum = kadane(length, array);
    printf("%li \n", sum);
    free(array);
    return 0;
}
