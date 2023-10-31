#include <stdio.h>
#include "src/cube.h"

int main() {
  // creating a cube with side length 5
  Cube * cube = create_cube(5);

  double side_area = get_area_of_one_side(cube);
  double total_area = get_cube_area(cube);
  double volume = get_cube_volume(cube);

  printf("Area of one side: %.2f\n", side_area);
  printf("Area of cube: %.2f\n", total_area);
  printf("Volume of cube: %.2f\n", volume);

  // free the memory
  destroy_cube(cube);

  return 0;
}