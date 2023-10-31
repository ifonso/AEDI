#ifndef CUBE_H_
#define CUBE_H_

typedef struct {
  double side_length;
} Cube;

Cube * create_cube(double s);
void destroy_cube(Cube * c);
double get_area_of_one_side(Cube * c);
double get_cube_area(Cube * c);
double get_cube_volume(Cube * c);

#endif // CUBE_H_