#ifndef PLANE_H_
#define PLANE_H_

#define MAX_NAME_LENGTH 100

typedef struct {
  char name[MAX_NAME_LENGTH];
} Plane;

Plane * create_plane(char * name);
void destroy_plane(Plane * plane);

void print_plane(Plane * plane);

#endif /* PLANE_H_ */