#include <stdio.h>
#include <stdlib.h>

void print(long *wave, long new_size) {
    for (long i = 0; i < new_size; i += 1) {
        printf("%li", wave[i]);
        printf(" ");
    }   
    printf("\n");
}

void echo(long size, long *wave, long num_echos, long decay_percentage) {
    long new_size = size*(num_echos + 1);
    long *new_wave = realloc(wave, (size_t)new_size * sizeof(long));
    if (new_wave != NULL) {
        for (long i = size; i < new_size; i += 1) {
            double decayed_value = new_wave[i - size]*(100 - decay_percentage)/100.0;
            long cast_value = (long) decayed_value;
            new_wave[i] = cast_value;
        }
        print(new_wave, new_size);
        free(new_wave);
    }
    else {
        printf("Error allocating memory \n");
    }
}

int main() {
    long size;
    scanf("%li", &size);

    long *wave = malloc((size_t)size * sizeof(long));
    if (wave != NULL) {
        for (long i = 0; i < size; i += 1) {
            scanf("%li", &wave[i]);
        }
        long num_echos;
        scanf("%li", &num_echos);

        long decay_percentage;
        scanf("%li", &decay_percentage);

        echo(size, wave, num_echos, decay_percentage);
    }
    else {
        printf("Error allocating memory \n");
        return 1;
    }   

}
