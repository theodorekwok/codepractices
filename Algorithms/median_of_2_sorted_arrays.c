#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


long max(long num_1, long num_2) {
    if (num_1 > num_2) {
        return num_1;
    }
    return num_2;
}

long min(long num_1, long num_2) {
    if (num_1 < num_2) {
        return num_1;
    }
    return num_2;
}

double find_median(long n, long *longer, long m, long *shorter) {
    long total_elements_on_one_side = (n + m + 1)/2;
    long partition_shorter = m/2;
    long partition_longer = total_elements_on_one_side - partition_shorter;

    long start = 0;
    long end = m;
    while (start <= end) {
        long partition_shorter = (start + end)/2;
        long partition_longer = total_elements_on_one_side - partition_shorter;

        long max_left_shorter;
        // no partition out all the elements
        if (partition_shorter == 0) {
            max_left_shorter = INT_MIN;
        }
        else {
            max_left_shorter = shorter[partition_shorter - 1];
        }

        long min_right_shorter;
        if (partition_shorter == m) {
            min_right_shorter = INT_MAX;
        }
        else {
            min_right_shorter = shorter[partition_shorter];
        }

        long max_left_longer;
        // no partition out all the elements
        if (partition_longer == 0) {
            max_left_longer = INT_MIN;
        }
        else {
            max_left_longer = longer[partition_longer - 1];
        }

        long min_right_longer;
        if (partition_longer == m) {
            min_right_longer = INT_MAX;
        }
        else {
            min_right_longer = longer[partition_longer];
        }

        if (max_left_shorter <= min_right_longer && max_left_longer <= min_right_shorter) {
            double median;
            if ((n + m) % 2 == 0) {
                median = ((double) min(min_right_shorter, min_right_longer) + max(max_left_shorter, max_left_longer)) / 2.0;
            }
            else {
                median = (double) max(max_left_shorter, max_left_longer);
            }
            return median;
    
        }
        else {
            if (max_left_shorter > min_right_longer) {
                end = partition_shorter - 1;
            }
            else {
                start = partition_shorter + 1;
            }
        }
    }
    return -1.0;
}

int main() {
    // enter length of array 1
    long n;
    scanf("%li", &n);

    long *array_one = malloc((size_t)n * sizeof(long));
    if (array_one == NULL) {
        printf("Error in allocating memory \n");
        return 1;
    } 

    for (long i = 0; i < n; i += 1) {
        scanf("%li", &array_one[i]);
    }

    // enter length of array 2
    long m;
    scanf("%li", &m);
    long *array_two = malloc((size_t)m * sizeof(long));
    if (array_two == NULL) {
        free(array_one);
        printf("Error in allocating memory \n");
        return 1;
    }   
    for (long i = 0; i < m; i += 1) {
        scanf("%li", &array_two[i]);
    }
    double median;
    if (n > m) {
        // annotated longer array
        median = find_median(n, array_one, m, array_two);
    }
    else {
        median = find_median(m, array_two, n, array_one);
    }
    printf("%lf\n", median);

    free(array_one);
    free(array_two);

}
