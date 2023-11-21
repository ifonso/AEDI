#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {
  Vector * v1 = create_vector(1.0, 2.0, 3.0);
  Vector * v2 = create_vector(4.0, 5.0, 6.0);

  Vector * v3 = sum_vector(v1, v2);
  float dot = dot_product(v1, v2);

  printf("v1 = (%.2f, %.2f, %.2f)\n", v1->x, v1->y, v1->z);
  printf("v2 = (%.2f, %.2f, %.2f)\n", v2->x, v2->y, v2->z);

  printf("\nsum: v1 + v2 = (%.2f, %.2f, %.2f)\n", v3->x, v3->y, v3->z);
  printf("dot product: v1 . v2 = %.2f\n", dot);

  // free memory
  destroy_vector(v1);
  destroy_vector(v2);
  destroy_vector(v3);

  return 0;
}