#include "vector.h"

#include <stdlib.h>

Vector * create_vector(float x, float y, float z) {
  Vector * v = malloc(sizeof(Vector));
  v->x = x;
  v->y = y;
  v->z = z;
  return v;
}

void destroy_vector(Vector * v) {
  free(v);
}

Vector * sum_vector(Vector * v1, Vector * v2) {
  return create_vector(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
}

float dot_product(Vector * v1, Vector * v2) {
  return (float)(v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}