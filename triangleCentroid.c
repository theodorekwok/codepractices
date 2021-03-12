#include <stdio.h>
#include <math.h>

void centroid(double vertexes[], double centre[]) {
    if (fabs(vertexes[0] - vertexes[2]) <= 0.000001 && fabs(vertexes[0] - vertexes[4]) <= 0.000001 && fabs(vertexes[2] - vertexes[4]) <= 0.000001) {
        if (fabs(vertexes[1] - vertexes[3]) <= 0.000001 && fabs(vertexes[1] - vertexes[5]) <= 0.000001 && fabs(vertexes[3] - vertexes[5]) <= 0.000001) {
            centre[0] = vertexes[0];
            centre[1] = vertexes[1];
            return;
        }
    }
    
    long index = 0;
    double vertexes_temp[6];
    for (long i = 0; i < 6; i += 2) {
        for (long j = i + 2; j < 6; j += 2) {
            double x_mid = (vertexes[i] + vertexes[j])/2;
            double y_mid = (vertexes[i + 1] + vertexes[j + 1])/2;

            vertexes_temp[index] = x_mid;
            index += 1;
            vertexes_temp[index] = y_mid;
            index += 1;
        }
    } 
    centroid(vertexes_temp, centre);

    /*while (fabs(vertexes[0] - vertexes[2]) > 0.000001 || fabs(vertexes[0] - vertexes[4]) > 0.000001 || fabs(vertexes[2] - vertexes[4]) > 0.000001 || fabs(vertexes[1] - vertexes[3]) > 0.000001 || fabs(vertexes[1] - vertexes[5]) > 0.000001 || fabs(vertexes[3] - vertexes[5]) > 0.000001) {
      double vertexes_temp[6];
      long index = 0;
      for (long i = 0; i < 6; i += 2) {
      for (long j = i + 2; j < 6; j += 2) {
      double x_mid = (vertexes[i] + vertexes[j])/2;
      double y_mid = (vertexes[i + 1] + vertexes[j + 1])/2;

      vertexes_temp[index] = x_mid;
      index += 1;
      vertexes_temp[index] = y_mid;
      index += 1;
      }
      }     
      for (long i = 0; i < 6; i += 1) {
      printf("%lf ", vertexes_temp[i]);
      vertexes[i] = vertexes_temp[i];
      }
      printf("\n");
      } 

      centre[0] = vertexes[0];
      centre[1] = vertexes[1];*/

}


int main() {
    double vertexes[6];

    for (long i = 0; i < 6; i += 1) {
        scanf("%lf", &vertexes[i]);
    }

    double centre[2];
    centroid(vertexes, centre);

    printf("%.2f %.2f \n", centre[0], centre[1]);
    
    printf("%.2f %.2f \n", (vertexes[0] + vertexes[2] + vertexes[4])/3, (vertexes[1] + vertexes[3] + vertexes[5])/3);
    return 0;
}
