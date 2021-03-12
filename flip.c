#include <stdio.h>
#include <stdlib.h>


void flipD(long size, long **image) {
    for (long i = 0; i < size; i += 1) {
        for (long j = 0; j < i; j += 1) {
            long temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }

    for (long i = 0; i < size; i += 1) {
        for (long j = 0; j < size; j += 1) {
            printf("%li", image[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
  
}

void flipH(long size, long **image) {
    for (long i = 0; i < size/2; i += 1) {
        for (long j = 0; j < size; j += 1) {
            long temp = image[i][j];
            image[i][j] = image[size - i - 1][j];
            image[size - i - 1][j] = temp;
        }
    }   

    for (long i = 0; i < size; i += 1) {
        for (long j = 0; j < size; j += 1) {
            printf("%li", image[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    long size;
    scanf("%li", &size);

    long **image;
    image = malloc((size_t)size * sizeof(long *));
    if (image != NULL) {
        for (long i = 0; i < size; i += 1) {
            image[i] = malloc((size_t)size * sizeof(long));
        }

        for (long i = 0; i < size; i += 1) {
            if (image[i] == NULL) {
                for (long j = 0; j < size; j += 1) {
                    if (image[j] != NULL) {
                        free(image[j]);
                    }
                }
                free(image);
                printf("Error in allocating memory");
                return 1;
            }
        }

        for (long i = 0; i < size; i += 1) {
            for (long j = 0; j < size; j += 1) {
                scanf("%li", &image[i][j]);
            }
        }
        
        char direction;
        scanf(" %c", &direction);
        if (direction - 'a' == 7) {
            flipH(size, image);
        }
        else if (direction - 'a' == 3){
            flipD(size, image);
        }
    }
    else {
        printf("Error in allocation of memory");
        return 1;
    }

    for (long i = 0; i < size; i += 1) {
        free(image[i]); 
    }
    free(image);

    return 0;

}
