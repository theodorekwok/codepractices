#include <stdio.h>
#include <stdlib.h>


long maxCherries(long num_slice, long *cherry_array) {
    long index = 0;
    long total_cherries = 0;
    for (long i = 0; i < num_slice; i += 1) {
        total_cherries += cherry_array[i];
    }
    long current_max = 0;
    while (index < num_slice) {
        long alice_cherry = 0;
        long bob_cherry = total_cherries;
        long starting_index = index;
        while (alice_cherry + cherry_array[starting_index] <= bob_cherry - cherry_array[starting_index]) {
            alice_cherry += cherry_array[starting_index];
            bob_cherry -= cherry_array[starting_index];
            if (starting_index == num_slice - 1) {
                starting_index = 0;
            }   
            else {
                starting_index += 1;
            }
        }
        if (alice_cherry > current_max) {
            current_max = alice_cherry;
        }
        index += 1;
    }

    return current_max;

}

int main() {
    long num_slice;
    scanf("%li", &num_slice);

    long *cherry_array = malloc((size_t)num_slice * sizeof(long));
    if (cherry_array != NULL) {     
        for (long i = 0; i < num_slice; i += 1) {
            scanf("%li", &cherry_array[i]);
        }
        long alice_cherries = maxCherries(num_slice, cherry_array);
        printf("%li\n", alice_cherries);
    }
    else {
        printf("Error in allocating memory \n");
        return 1;
    }
    free(cherry_array);
    return 0;
}
