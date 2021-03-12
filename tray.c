#include <stdio.h>


double min_perimeter(double trayHeight, double trayWidth, long* ptr_rounds) {
    if (*ptr_rounds == 0) {
        return trayHeight*2 + trayWidth*2;
    }

    *ptr_rounds -= 1;
    double perimeter;
    if (trayHeight > trayWidth) {
        perimeter = min_perimeter(trayHeight/2, trayWidth, ptr_rounds);
    }
    else {
        perimeter = min_perimeter(trayHeight, trayWidth/2, ptr_rounds);
    }
    return perimeter;
}


int main() {
    double trayHeight, trayWidth;

    printf("Enter trayHeight: ");
    scanf("%lf", &trayHeight);

    printf("Enter trayWidth: ");
    scanf("%lf", &trayWidth);
    
    long rounds = 3;
    long* ptr_rounds = &rounds;
    double perimeter = min_perimeter(trayHeight, trayWidth, ptr_rounds);

    printf("Perimeter %f\n", perimeter);
    return 0;
}
