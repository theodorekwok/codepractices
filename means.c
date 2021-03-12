#include <stdio.h>
#include <math.h>


void compute_AM_GM(long integers[], double *am_ptr, double *gm_ptr) {
    *am_ptr = (integers[0] + integers[1] + integers[2])/3;
    double multiplied = integers[0] * integers[1] * integers[2] * 1.0;
    *gm_ptr = pow(multiplied, 1.0/3.0);
}


int main() {
    long integers[3];
    for (long i = 0; i < 3; i += 1) {
        scanf("%li", &integers[i]);
    }
    double am;
    double gm;
    double *am_ptr = &am;
    double *gm_ptr = &gm;
    compute_AM_GM(integers, am_ptr, gm_ptr);

    printf("%.2f %.2f \n", am, gm);

    return 0;

}
