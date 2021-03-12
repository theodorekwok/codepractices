#include <stdio.h>
#include <stdbool.h>


long calculate_expression(char *comb) {
    long answer = 0;
    long num_multiply = 0;
    long num_divide = 0;
    for (long i = 0; i < 3; i += 1) {
        if (comb[i] == '*') {
            num_multiply += 1;
        }
        else if (comb[i] == '/') {
            num_divide += 1;
        }
    }
    // more than one divide and multiply
    if (num_multiply + num_divide == 2) {
        // 2, means must check if got a arithmetic in between
        // non consecutive operations
        long part_1;
        long part_2;
        if (comb[1] == '+' || comb[1] == '-') {
            if (comb[0] == '*') {
                part_1 += 4*4;
            }
            else {
                // must be divide cause got 1 arithmetic and 2 higher order operations
                part_1 += 4/4;
            }
            if (comb[2] == '/') {
                part_2 += 4/4;
            }
            else {
                part_2 += 4*4;
            }
            if (comb[1] == '+') {
                answer = part_1 + part_2;
            }
            else {
                answer = part_1 - part_2;
            }
        }
        else {
            // consecutive operations
            // first operator encountered
            bool first_part = false;
            if (comb[0] == '*' || comb[0] == '/') {
                first_part = true;
            }
                      
            if (first_part) {
                // means that the 2 consecutive higher order operators are at index 0 and 1
                if (comb[0] == '*') {
                    if (comb[1] == '/') {
                        answer += 4;
                    }
                    else {
                        answer += 4*4*4;
                    }
                }
                else {
                    if (comb[1] == '/') {
                        answer += 0;
                    }
                    else {
                        answer += 4;
                    }
                }
            }
            else {
                // means index 1 and 2 has the higher order operators
                if (comb[1] == '*') {
                    if (comb[2] == '/') {
                        answer += 4;
                    }
                    else {
                        answer += 4*4*4;
                    }
                }
                else {
                    if (comb[2] == '/') {
                        answer += 0;
                    }
                    else {
                        answer += 4;
                    }
                }
            }
        
            // just addition
            if (comb[0] == '+' || comb[2] == '+') {
                answer += 4;
            }
            else if (comb[0] == '-') {
                answer = 4 - answer;
            }
            else if (comb[2] == '-') {
                answer -= 4;
            }
        }
    }
    else {
        // either 0, 1 or 3 higher order operations
        // zero higher order
        if (num_multiply + num_divide == 0) {
            if (comb[0] == '+') {
                answer += 8;
            }
            else {
                answer += 0;
            }
            for (long i = 1; i < 3; i += 1) {
                if (comb[i] == '+') {
                    answer += 4;
                }
                else {
                    answer -= 4;
               }
            }
        }
        // one higher order
        else if (num_multiply + num_divide == 1) {
            long merged_val = 0;
            for (long i = 0; i < 3; i += 1) {
                if (comb[i] == '*') {
                    merged_val += 4*4;      
                }
                else if (comb[i] == '/') {
                    merged_val += 4/4;
                }
            }

            // loop through but for arithemtic operations
            bool first = true;
            if (comb[0] == '*' || comb[0] == '/') {
                answer += merged_val;
                for (long  i = 1; i < 3; i += 1) {
                    if (comb[i] == '+') {
                        answer += 4;
                    }
                    else {
                        answer -= 4;
                    }
                }
            }
            else if (comb[1] == '*' || comb[1] == '/') {
                if (comb[0] == '+') {
                    answer = 4 + merged_val;
                }
                else if (comb[0] == '-') {
                    answer = 4 - merged_val;
                }

                if (comb[2] == '+') {
                    answer += 4;
                } 
                else if (comb[2] == '-') {
                    answer -= 4;
                }
            }

        }
        // 3 higher order operations
        else {
            if (comb[0] == '*') {
                answer += 4*4;
            }
            else {
                answer += 4/4;
            }
            for (long i = 1; i < 3; i += 1) {
                if (comb[i] == '*') {
                    answer *= 4;
                }
                else {
                    answer /= 4;
                }
            }
        }
    }
    return answer;
}

void print_expression(long val) {
    char expression[4] = {'*', '+', '-', '/'};
    long i = 0; 
    bool found = false;
    for (long first = 0; first < 4; first += 1) {   
        for (long second = 0; second < 4; second += 1) {
            for (long third = 0; third < 4; third += 1) {
                char comb[4] = {expression[first], expression[second], expression[third]};
                long possible_val = calculate_expression(comb);
                if (possible_val == val && !found) {
                    printf("%c %c %c %c %c %c %c %c %li\n", '4', comb[0], '4', comb[1], '4', comb[2], '4', '=', val); 
                    found = true;
                }
            }
        }

    }
    if (!found) {
        printf("no solution\n");
    }
}

int main() {
    long num_test;
    scanf("%li", &num_test);
    
    long input_array[num_test];
    for (long i = 0; i < num_test; i += 1) {
        scanf("%li", &input_array[i]);
    }

    for (long i = 0; i < num_test; i += 1) {
        print_expression(input_array[i]);
    }
    
    return 0;
}
