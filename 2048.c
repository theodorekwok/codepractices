#include "stdio.h"


void print_results(long grid[][4]) {
    for (long row = 0; row < 4; row += 1) {
        printf("%li %li %li %li\n", grid[row][0], grid[row][1], grid[row][2], grid[row][3]);
    }     
}

// left movement
void left_flush(long grid[4][4], long* row_num_zeros) {
    // flush left
    for (long row = 0; row < 4; row += 1) {
        long num[4];
        long i = 0;
        long num_zero = 0;
        for (long col = 0; col < 4; col += 1) {
            if (grid[row][col] != 0) {
                num[i] = grid[row][col];
                i += 1;
            }   
            else {
                num_zero += 1;
            }   
        }
        for (long col = 0; col < 4; col += 1) {
            if (col < 4 - num_zero) {
                grid[row][col] = num[col];
            }
            else {
                grid[row][col] = 0;
            }
        }
        row_num_zeros[row] = num_zero;
    }
}

void left_swipe(long grid[4][4], long* row_num_zeros) {
    left_flush(grid, row_num_zeros);
    // merge
    for (long row = 0; row < 4; row += 1) {
        // means whole row has at least 2 numbers
        if (row_num_zeros[row] < 3) {
            if (grid[row][0] == grid[row][1]) {
                grid[row][0] *= 2;
                grid[row][1] = 0;
                if (grid[row][2] == grid[row][3]) {
                    grid[row][2] *= 2;
                    grid[row][3] = 0;
                }
            }
            else {
                if (grid[row][1] == grid[row][2]) {
                    grid[row][1] *= 2;
                    grid[row][2] = 0;
                }
                else if (grid[row][2] == grid[row][3]) {
                    grid[row][2] *= 2;
                    grid[row][3] = 0;
                }
            }
        }
    }
    left_flush(grid, row_num_zeros);
   
}



// right movement
void right_flush(long grid[4][4], long* row_num_zeros) {
    // flush right
    for (long row = 0; row < 4; row += 1) {
        long num[4];
        long i = 3;
        long num_zero = 0;
        for (long col = 3; col >= 0; col -= 1) {
            if (grid[row][col] != 0) {
                num[i] = grid[row][col];
                i -= 1;
            }   
            else {
                num_zero += 1;
            }   
        }
        

        for (long col = 3; col >= 0; col -= 1) {
            if (col >= num_zero) {
                grid[row][col] = num[col];
            }
            else {
                grid[row][col] = 0;
            }
        }
        row_num_zeros[row] = num_zero;
    }
}

void right_swipe(long grid[4][4], long* row_num_zeros) {
    right_flush(grid, row_num_zeros);
    // merge
    for (long row = 0; row < 4; row += 1) {
        // means whole row has at least 2 numbers
        if (row_num_zeros[row] < 3) {
            if (grid[row][3] == grid[row][2]) {
                grid[row][3] *= 2;
                grid[row][2] = 0;
                if (grid[row][1] == grid[row][0]) {
                    grid[row][1] *= 2;
                    grid[row][0] = 0;
                }
            }
            else {
                if (grid[row][2] == grid[row][1]) {
                    grid[row][2] *= 2;
                    grid[row][1] = 0;
                }
                else if (grid[row][1] == grid[row][0]) {
                    grid[row][1] *= 2;
                    grid[row][0] = 0;
                }
            }
        }
    }
    right_flush(grid, row_num_zeros);
   
}


// up movement
void up_flush(long grid[4][4], long* row_num_zeros) {
    // flush up
    for (long col = 0; col < 4; col += 1) {
        long num[4];
        long i = 0;
        long num_zero = 0;
        for (long row = 0; row < 4; row += 1) {
            if (grid[row][col] != 0) {
                num[i] = grid[row][col];
                i += 1;
            }   
            else {
                num_zero += 1;
            }   
        }
        

        for (long row = 0; row < 4; row += 1) {
            if (row < 4 - num_zero) {
                grid[row][col] = num[row];
            }
            else {
                grid[row][col] = 0;
            }
        }
        row_num_zeros[col] = num_zero;
    }
}

void up_swipe(long grid[4][4], long* row_num_zeros) {
    up_flush(grid, row_num_zeros);
    // merge
    for (long col = 0; col < 4; col += 1) {
        // means whole col has at least 2 numbers
        if (row_num_zeros[col] < 3) {
            if (grid[0][col] == grid[1][col]) {
                grid[0][col] *= 2;
                grid[1][col] = 0;
                if (grid[2][col] == grid[3][col]) {
                    grid[2][col] *= 2;
                    grid[3][col] = 0;
                }
            }
            else {
                if (grid[1][col] == grid[2][col]) {
                    grid[1][col] *= 2;
                    grid[2][col] = 0;
                }
                else if (grid[2][col] == grid[3][col]) {
                    grid[2][col] *= 2;
                    grid[3][col] = 0;
                }
            }
        }
    }
    up_flush(grid, row_num_zeros);
   
}

// down movement
void down_flush(long grid[4][4], long* row_num_zeros) {
    // flush down
    for (long col = 0; col < 4; col += 1) {
        long num[4];
        long i = 3;
        long num_zero = 0;
        for (long row = 3; row >= 0; row -= 1) {
            if (grid[row][col] != 0) {
                num[i] = grid[row][col];
                i -= 1;
            }
            else {
                num_zero += 1;
            }   
        }
        

        for (long row = 3; row >= 0; row -= 1) {
            if (row >= num_zero) {
                grid[row][col] = num[row];
            }
            else {
                grid[row][col] = 0;
            }
        }
        row_num_zeros[col] = num_zero;
    }
}

void down_swipe(long grid[4][4], long* row_num_zeros) {
    down_flush(grid, row_num_zeros);
    // merge
    for (long col = 0; col < 4; col += 1) {
        // means whole col has at least 2 numbers
        if (row_num_zeros[col] < 3) {
            if (grid[3][col] == grid[2][col]) {
                grid[3][col] *= 2;
                grid[2][col] = 0;
                if (grid[1][col] == grid[0][col]) {
                    grid[1][col] *= 2;
                    grid[0][col] = 0;
                }
            }
            else {
                if (grid[2][col] == grid[1][col]) {
                    grid[2][col] *= 2;
                    grid[1][col] = 0;
                }
                else if (grid[1][col] == grid[0][col]) {
                    grid[1][col] *= 2;
                    grid[0][col] = 0;
                }
            }
        }
    }
    down_flush(grid, row_num_zeros);
   
}


void swipe(long grid[][4], long direction) {
    long row_num_zeros[4];
    if (direction == 0) {
        left_swipe(grid, row_num_zeros);
    }
    else if (direction == 2) {
        right_swipe(grid, row_num_zeros);
    }    
    else if (direction == 1) {
        up_swipe(grid, row_num_zeros);
    }
    else {
        down_swipe(grid, row_num_zeros);
    }


    print_results(grid);
}


int main() {
    long grid[4][4];
    long direction;

    // input and populate grid
    for (long row = 0; row < 4; row += 1) {
        for (long col = 0; col  < 4; col += 1) {
            long digit;
            scanf("%li", &digit);
            grid[row][col] = digit;
        }
    }

    // input the direction
    scanf("%li", &direction);
    
    swipe(grid, direction);
        
    return 0;
}
