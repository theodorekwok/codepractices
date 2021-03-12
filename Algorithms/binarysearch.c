#include <stdio.h>


long binarySearch(long length, long array[], long to_search) {
    
    long start = 0;
    long end = length - 1;

    while (start <= end) {
        long midpoint = (start + end)/2;

        if (array[midpoint] == to_search) {
            printf("Found it at index: %li\n", midpoint);
            return midpoint;
        }
        else if (array[midpoint] < to_search) {
            start = midpoint + 1;
        }
        else {
            end = midpoint - 1;
        }
    
    }
    printf("Unable to find element\n");
    return 0;

}

void binarySearch_modified(long length, long array[], long to_search) {
    long start = 0;
    long end = length - 1;

    while (start <= end) {
        long midpoint = (start + end)/2;

        if (array[midpoint] == to_search) {
            printf("Found it at index: %li\n", midpoint);
            return;
        }
        else if (array[midpoint] < to_search) {
            start = midpoint + 1;
        }
        else {
            end = midpoint - 1;
        }
    }

    if (end == -1) {
        printf("closest index: -1 \n");
        return;
    }    
    else if (start == length) {
        printf("closest index: %li\n", length - 1);
    }
    else {
        if (array[start] > to_search) {
            printf("closest index: %li\n", start - 1);
        }
        else {
            printf("closest index: %li\n", start);
        }
    }
}

int main() {
    long length;
    printf("Input the length of array: ");

    scanf("%li", &length);

    long array[length];
    printf("Input the array: ");
    for (long i = 0; i < length; i += 1) {
        scanf("%li", &array[i]);
    }

    long to_search;
    printf("Input element to search: ");
    scanf("%li", &to_search);

    //long index = binarySearch(length, array, to_search);
    //binarySearch_modified(length, array, to_search);
    return 0;
}
