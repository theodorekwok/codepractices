#include <stdio.h>
#include <stdbool.h>

bool check_digit(long value, long must_have) {
    
    while (value > 0) {
        long remainder = value % 10;
        if (remainder == must_have) {
            return true;
        }
        value -= remainder;
        value /= 10;
    }
    return false;

}

void print_num_winners(long factor, long must_have, long participants) {
    long num_winners;
    
    for (long person = 1; person <= participants; person += 1) {
        if (check_digit(person, must_have) && person % factor == 0) {
            num_winners += 1;
        }
    }

    printf("Number of winners: %li\n", num_winners);
}

int main() {
    long factor;

    printf("Enter factor-digit: ");
    scanf("%li", &factor);
    
    long must_have;
    printf("Enter must-have-digit: ");
    scanf("%li", &must_have);

    long participants;
    printf("Enter number of participants: ");
    scanf("%li", &participants);
    
    print_num_winners(factor, must_have, participants);

    return 0;
}
