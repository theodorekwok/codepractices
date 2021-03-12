#include <stdio.h>
#include <stdbool.h>

bool area_greater_than_volume(long dimensions[]) {
    long area = 2*(dimensions[0]*dimensions[1] + dimensions[1]*dimensions[2] + dimensions[0]*dimensions[2]);

    long volume = dimensions[0]*dimensions[1]*dimensions[2];
    if (area >= volume) {
        return true;
    }
    return false;
}

long count_boxes(long bounds[]) {
    long counter = 0;
    for (long i = bounds[0]; i <= bounds[1]; i += 1) {
        for (long j = i; j <= bounds[1]; j += 1) {
            for (long h = j; h <= bounds[1]; h += 1) {
                long dimensions[3] = { i, j, h };
                // printf("%li %li %li \n", i, j, h);
                if (area_greater_than_volume(dimensions)) {
                    counter += 1;
                }
            }
        }
    }
    return counter;
}


int main() {
    long bounds[2];
    scanf("%li", &bounds[0]);
    scanf("%li", &bounds[1]);

    long num = count_boxes(bounds);
    printf("%li \n", num);

    return 0;    
}
