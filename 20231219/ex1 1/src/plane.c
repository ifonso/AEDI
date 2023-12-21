#include "plane.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Plane * create_plane(char * name) {
  Plane * p = (Plane *) malloc(sizeof(Plane));

  if (p == NULL) {
    fprintf(stderr, "Error: could not allocate memory for plane.\n");
    exit(1);
  }

  strcpy(p->name, name);

  return p;
}

void destroy_plane(Plane * plane) {
  free(plane);
}

void print_plane(Plane * plane) {
  printf("Plane name: %s\n", plane->name);
}