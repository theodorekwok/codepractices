#include <stdio.h>


char* printOrdinal(long century) {
    long last_digit = century % 10;
    long second_last_digit = ((century - last_digit)/10) % 10;
    char* ordinal;
    if (second_last_digit != 1 && last_digit <= 3 && last_digit != 0) {
        if (last_digit == 1) {
            ordinal = "st";
        }
        else if (last_digit == 2) {
            ordinal = "nd";
        }
        else {
            ordinal = "rd";
        }
    }
    else {
        ordinal = "th";
    }

    return ordinal;

}



long get_century(long year) {
    long century = year/100 + 1;

    return century;
}

void printCentury(long year, long century) {
    char* ordinal = printOrdinal(century);
    printf("The year %li falls in the %li%s century.\n", year, century, ordinal);
}

int main() {
    long year;

    printf("Enter year: ");
    scanf("%li", &year);    
    
    long century = get_century(year);
    printCentury(year, century);

    return 0;

}
