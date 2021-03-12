#include <stdio.h>
#include <stdlib.h>

long countJumps(long *rock_positions, long num_rocks) {
    long distance = 0;
    
    long num_jumps = 0;
    for (long i = 0; i < num_rocks - 1; i += 1) {
        if (i == num_rocks - 2) {
            if (rock_positions[i + 1] - distance <= 50) {
                num_jumps += 1;
                distance = rock_positions[i];
                break;
            }
            else if (rock_positions[i] - distance <= 50) {
                num_jumps += 1;
                distance = rock_positions[i];
                if (rock_positions[i + 1] - distance <= 50) {
                    num_jumps += 1;
                    distance = rock_positions[i];
                }
                else {
                    num_jumps = -1;
                }
                break;
            }
        }

        if (rock_positions[i + 1] - distance > 50 && rock_positions[i] - distance <= 50) {
            num_jumps += 1;
            distance = rock_positions[i];
        }
        else if (rock_positions[i] - distance > 50) {
            num_jumps = -1;
            break;
        }
    }

    return num_jumps;
}

int main() {
    long num_rocks;
    scanf("%li", &num_rocks);

    long *rock_positions = malloc((size_t)num_rocks * sizeof(long));
    if (rock_positions != NULL) {
        for (long i = 0; i < num_rocks; i += 1) {
           scanf("%li", &rock_positions[i]);
        }

        long num_jumps = countJumps(rock_positions, num_rocks);
        printf("%li\n", num_jumps);
    }
    else {
        printf("Error allocating memory");
        return 1;
    }
    free(rock_positions);

}
