#include "cube.h"

#include <math.h>
#include <stdlib.h>

Cube * create_cube(double s) {
  Cube * cube = malloc(sizeof(Cube));
  cube->side_length = s;
  return cube;
}

void destroy_cube(Cube * c) {
  free(c);
}

double get_area_of_one_side(Cube * c) {
  return pow(c->side_length, 2);
}

double get_cube_area(Cube * c) {
  return 6 * pow(c->side_length, 2);
}

double get_cube_volume(Cube * c) {
  return pow(c->side_length, 3);
}