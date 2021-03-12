#include <stdio.h>



void generateMagic(long square_matrix[][15], long odd_integer) {
    long number_of_cells = odd_integer * odd_integer;
    long counter = 2;
    
    long row = 0;
    long column = odd_integer/2;

    square_matrix[row][column] = 1;

    while (counter <= number_of_cells) {
        row -= 1;
        column += 1;
        if (row == -1) {
            if (column == odd_integer) {
                if (square_matrix[row + odd_integer][column - odd_integer] == 0) {
                    row += odd_integer;
                    column -= odd_integer;
                }
                else {
                    row += 2;
                    column -= 1;
                }   
            }
            else {
                if (square_matrix[row + odd_integer][column] == 0) {
                    row += odd_integer;
                }
                else {
                    row += 2;
                }
            }
        }    
        else {
            if (column == odd_integer) {
                if (square_matrix[row][column - odd_integer] == 0) {
                    column -= odd_integer;
                }
                else {
                    row += 2;
                    column -= 1;
                    if (row == odd_integer) {
                        row = 0;
                    }

                }
            }
            else {
                if (square_matrix[row][column] != 0) {
                    row += 2;
                    column -= 1;
                    if (row == odd_integer) {
                        row = 0;
                    }
                }
            }
        }
        square_matrix[row][column] = counter;
        counter += 1;
    }

    for (long i = 0; i < odd_integer; i += 1) {
        for (long j = 0; j < odd_integer; j += 1) {
            printf("%li", square_matrix[i][j]);
            printf(" ");
        } 
        printf(" \n");
    }
    printf(" \n");
}


int main() {
    long odd_integer;
    scanf("%li", &odd_integer);

    long square_matrix[15][15];

    for (long i = 0; i < 15; i += 1) {
        for (long j = 0; j < 15; j += 1) {
            square_matrix[i][j] = 0;
        }
    }

    generateMagic(square_matrix, odd_integer);

    return 0;
}
