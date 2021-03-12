#include <stdio.h>
#include <stdbool.h>
#include <limits.h>


long compute_flips(long time_one, long time_two, long duration, long *flip_one_ptr, long *flip_two_ptr) {
    long flip_one_max = duration/time_one;
    long flip_two_max = 0;
    long max = INT_MAX;

    bool possible = false;
    for (long i = flip_one_max; i >= 0; i -= 1) {
        long remaining_time = duration - i*time_one;
        flip_two_max = remaining_time/time_two;
        if (remaining_time % time_two == 0) {
            if (i + flip_two_max < max) {
                *flip_one_ptr = i;
                *flip_two_ptr = flip_two_max;
                possible = true;
                //printf("%li %li \n", *flip_one_ptr, *flip_two_ptr);

                max = i + flip_two_max;
            }
        }
    }
    if (possible) {
        return 1;
    }
    return 0;
}


int main() {
    long inputs[3];
    for (long i = 0; i < 3; i += 1) {
        scanf("%li", &inputs[i]);
    }
    
    long flip_one = 0;
    long *flip_one_ptr = &flip_one;
    long flip_two = 0;
    long *flip_two_ptr = &flip_two;
    long possible = compute_flips(inputs[0], inputs[1], inputs[2], flip_one_ptr, flip_two_ptr);
    
    if (possible == 1) {
        printf("%li minutes hourglass flip %li times \n" , inputs[0], flip_one);
        printf("%li minutes hourglass flip %li times \n" , inputs[1], flip_two);
    }
    else {
        printf("Not possible \n");
    }

}
