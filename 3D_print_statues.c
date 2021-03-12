#include <stdio.h>
#include <math.h>

long min_days(long n_statues) {
    long machines = 1;
    long days = 1;
    while (machines < n_statues) {
        machines *= 2;
        days += 1;
    }
    return days;
}


int main() {

    // input from 1 - 10000
    long n_statues;
    scanf("%li", &n_statues);
    
    long mininum_days;
    mininum_days = min_days(n_statues);
    printf("%li", mininum_days);
    
    return 0;
}
