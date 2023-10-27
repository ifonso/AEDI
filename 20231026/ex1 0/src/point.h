#ifndef POINT_H_
#define POINT_H_

struct Point {
  float x;
  float y;
};

typedef struct Point Point;

Point * create_point(float x, float y);
void destroy_point(Point * point);
int access_point(Point * point, float * x, float * y);
int set_point(Point * point, float x, float y);
float distance_between_points(Point * p1, Point * p2);

#endif // POINT_H_