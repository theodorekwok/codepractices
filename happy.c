#include <stdio.h>
#include <stdbool.h>

long sum_square_digits(long starting_value) {
    long sum = 0;
    while (starting_value > 0) {
        long remainder = starting_value % 10;
        sum += (remainder * remainder);
        starting_value -= remainder;
        starting_value /= 10;
    }

    return sum;

}

bool ishappy(long starting_value) {
    long reached_array[10] = { 0, 1, 4, 16, 20, 37, 42, 58, 89, 145 };
    for (long i = 0; i < 10; i += 1) {
        if (starting_value == reached_array[i]) {
            if (starting_value == 1) {
                return true;
            }
            else {
                return false;
            }
        }
    }

    long new_starting_value = sum_square_digits(starting_value);
    
    return ishappy(new_starting_value);
        
}

long computeHappyNumbers(long lower, long upper) {
    long num_happy_numbers = 0;

    for (long i = lower; i <= upper; i += 1) {
        if (ishappy(i)) {
            num_happy_numbers += 1;
        }
    }

    return num_happy_numbers;
}

void print_num_happy_in_range(long range_one_happy, long range_two_happy) {
    printf("The numbers of happy numbers in the two ranges are: %li %li\n", range_one_happy, range_two_happy);

    if (range_one_happy > range_two_happy) {
        printf("There are more happy numbers in the first range.\n");
    }
    else if (range_one_happy == range_two_happy) {
        printf("The numbers of happy numbers in both ranges are the same.\n");
    }
    else {
        printf("There are more happy numbers in the second range.\n");
    }
}

int main() {
    long range_one_lower;
    long range_one_upper;

    long range_two_lower;
    long range_two_upper;

    printf("Enter 1st range: ");
    scanf("%li %li", &range_one_lower, &range_one_upper);
    
    printf("Enter 2nd range: ");
    scanf("%li %li", &range_two_lower, &range_two_upper);

    long range_one_happy = computeHappyNumbers(range_one_lower, range_one_upper);
    long range_two_happy = computeHappyNumbers(range_two_lower, range_two_upper);

    print_num_happy_in_range(range_one_happy, range_two_happy);

    return 0;
}

