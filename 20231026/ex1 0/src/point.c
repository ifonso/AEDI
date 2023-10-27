#include "point.h"

#include <stdlib.h>
#include <math.h>

Point * create_point(float x, float y) {
  Point * p = malloc(sizeof(Point));
  p->x = x;
  p->y = y;
  return p;
}

void destroy_point(Point * p) {
  free(p);
}

int access_point(Point * p, float * x, float * y) {
  if (p == NULL) return -1;
  *x = p->x;
  *y = p->y;
  return 1;
}

int set_point(Point * p, float x, float y) {
  if (p == NULL) return -1;
  p->x = x;
  p->y = y;
  return 1;
}

float distance_between_points(Point * p1, Point * p2) {
  if (p1 == NULL || p2 == NULL) return -1;
  return (float)sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}
