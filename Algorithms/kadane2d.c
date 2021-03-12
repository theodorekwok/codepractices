#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


long kadane(long n, long *store, long *possible_top, long *possible_bot) {
    long max_global = store[0];
    long max_local = store[0];
    
    bool alone = false;
    for (long i = 1; i < n; i += 1) {
        if (store[i] + max_local > store[i]) {
            max_local += store[i];
            alone = false;
        }
        else {
            max_local = store[i];
            alone = true;
        }

        if (max_local > max_global) {
            *possible_bot = i;
            max_global = max_local;
            if (alone) {
                *possible_top = i;
            }
        }
    }

    return max_global;
}


// m is col, n is row
// O(m*m*n)
long kadane_2d(long n, long m, long **array, long *store) {
    long max_sum = array[0][0];
    long best_left = -1;
    long best_right = -1;
    long best_top = -1;
    long best_bot = -1;
    for (long left = 0; left < m; left += 1) {
        for (long i = 0; i < n; i += 1) {
            store[i] = 0;
        }
        for (long right = left; right < m; right += 1) {
            for (long i = 0; i < n; i += 1) {
                store[i] += array[i][right];
            }
            long possible_top = 0;
            long possible_bot = 0;
            long possible_max = kadane(n, store, &possible_top, &possible_bot);
            if (possible_max > max_sum) {
                best_left = left;
                best_right = right;
                best_top = possible_top;
                best_bot = possible_bot;
                max_sum = possible_max;
            }
        }
    }
    
    printf("Left: %li Right: %li Up: %li Down: %li \n", best_left, best_right, best_top, best_bot);

    return max_sum;
}

int main() {
    long n;
    scanf("%li", &n);
    long m;
    scanf("%li", &m);
    
    long **array = malloc((size_t)n * sizeof(long *));
    if (array != NULL) {
        for (long i = 0; i < n; i += 1) {
            array[i] = malloc((size_t)m * sizeof(long));
        }
    }
    else {
        printf("Error allocating memory \n");
        return 1;
    }
    bool unsuccessful = false;
    for (long i = 0; i < n; i += 1) {
        if (array[i] == NULL) {
            unsuccessful = true;
        }
    }
    if (unsuccessful) {
        for (long i = 0; i < n; i += 1) {
            free(array[i]);
        }
        free(array);

        printf("Error allocating memory \n");
        return 1;
    }

    for (long i = 0; i < n; i += 1) {
        for (long j = 0; j < m; j += 1) {
            scanf("%li", &array[i][j]);
        }
    }

    long *store = malloc((size_t)n * sizeof(long));
    if (store == NULL) {
        printf("Error allocating memory \n");
        return 1;
    }

    long max_sum = kadane_2d(n, m, array, store);
    printf("%li \n", max_sum);
    for (long i = 0; i < n; i += 1) {
        free(array[i]);
    }
    free(array);
    free(store);

    return 0;

}
