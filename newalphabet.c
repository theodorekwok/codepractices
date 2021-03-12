#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void translate(char* string) {

    char dictionary[26][6] = { "@", "8", "(", "|)", "3", "#", "6", "[-]",
                               "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]",
                               "0", "|D", "(,)", "|Z", "$", "']['", "|_|",
                               "\\/", "\\/\\/", "}{", "`/", "2" };

    char* letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    long string_length = strlen(string);
    for (long i = 0; i < string_length; i += 1) {
        bool is_alphabet = false;
        for (long letter = 0; letter < 52; letter += 1) {
            if (string[i] == letters[letter]) {
                if (letter == 12 || letter == 38) {
                    printf("%s", "[]\\/[]");
                }
                else {
                    if (letter < 26) {
                        printf("%s", dictionary[letter]);
                    }
                    else {
                        printf("%s", dictionary[letter - 26]);
                    }
                }
                is_alphabet = true;
            }
        }
        if (is_alphabet == false) {
            printf("%c", string[i]);
        }
    }
    printf("\n");   
}


int main() {
    char string[10000];

    scanf("%[^\n]s", string);

    translate(string);
    
    return 0;
}
