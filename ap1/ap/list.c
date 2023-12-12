#include "list.h"

#include <stdlib.h>
#include <stdio.h>

List * new_list() {
  List * l = (List *) malloc(sizeof(List));
  l->length = 0;
  return l;
}

void destroy_list(List * l) {
  free(l);
}

int add_list(List * l, Student s) {
  // List is full
  if (l->length == MAX) return -1;

  l->values[l->length] = s;
  l->length++;

  return 1;
}

float get_average_students_age(List * l) {
  int average = 0;
  for (int i = 0; i < l->length; i++) {
    average += l->values[i].age;
  }
  return ((float)average)/((float)l->length);
}

void print_list(List * l) {
  printf("\n");
  for (int i = 0; i<l->length; i++) {
    printf("Student (%d) : %s -> %dy\n", l->values[i].code, l->values[i].name, l->values[i].age);
  }
  printf("\n");
}