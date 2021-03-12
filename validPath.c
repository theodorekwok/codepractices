#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void isValid(long maze[][6], char path[]) {
    long row_index = 0;
    long col_index = 0;
    
    long path_index = 0;
    bool valid_path = true;
    long string_length = (long) strlen(path);
    while (path_index < string_length) {
        if (path[path_index] == 'N') {
            if (row_index - 1 < 0) {
                printf("Not Valid N %li \n", path_index);
                valid_path = false;
                break;
            }

            row_index -= 1;
        }
        else if (path[path_index] == 'E') {
            if (col_index + 1 == 6) {
                printf("Not Valid E %li \n", path_index);
                valid_path = false;
                break;
            }

            col_index += 1;
        }   
        else if (path[path_index] == 'W') {
            if (col_index - 1 < 0) {
                printf("Not Valid W %li \n", path_index);
                valid_path = false;
                break;
            }

            col_index -= 1;
        }
        else {
            if (row_index + 1 == 6) {
                printf("Not Valid S %li \n", path_index);
                valid_path = false;
                break;
            }

            row_index += 1;

        }
        if (maze[row_index][col_index] == 0) {
            printf("Not Valid hit wall %li \n", path_index);
            valid_path = false;
            break;
        }

        path_index += 1;
    }

    if (valid_path) {
        printf("Valid\n");
    }
}


int main() {
    
    long maze[6][6];
    for (long i = 0; i < 6; i += 1) {
        for (long j = 0; j < 6; j += 1) {
            scanf("%li", &maze[i][j]);
        }
    }

    char path[11];
    scanf("%s", path);

    isValid(maze, path);
    
    return 0;
}
