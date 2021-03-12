#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long largest_number_of_factors(long input) {
    long answer = 0;

    long factor = 2;
    while (factor*factor <= input) {
        if (input % factor == 0) {
            input /= factor;
            answer += 1;
        }
        else {
            factor += 1;
        }
    }

    return answer + 1;
}

int main() {
    long input;
    scanf("%li", &input);

    long k = largest_number_of_factors(input);

    printf("%li\n", k);
    return 0;
}
