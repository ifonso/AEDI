#include <stdio.h>
#include "src/point.h"

int main() {
  // create points
  Point * first_point = create_point(1.0, 2.0);
  Point * second_point = create_point(2.0, 4.0);

  float x1, y1, 
        x2, y2;
  
  // points data
  access_point(first_point, &x1, &y1);
  access_point(second_point, &x2, &y2);
  
  printf("first point:\nx: %.2f\ty: %.2f\n", x1, y1);
  printf("second point:\nx: %.2f\ty: %.2f\n", x2, y2);

  // show the distance between them
  printf("distance between points: %.2f\n", distance_between_points(first_point, second_point));

  // free the memory
  destroy_point(first_point);
  destroy_point(second_point);

  return 0;
}
