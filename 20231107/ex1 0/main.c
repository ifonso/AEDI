#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int * vector;
  int size;
} Vector;

int get_highest_element(Vector * v, int position, int current) {
  if (position == v->size) {
    return current;
  }

  return get_highest_element(
    v, position+1, v->vector[position] > current ? v->vector[position] : current
  );
}

int get_lowest_element(Vector * v, int position, int current) {
  if (position == v->size) {
    return current;
  }

  return get_lowest_element(
    v, position+1, v->vector[position] < current ? v->vector[position] : current
  );
}

int get_sum(Vector * v, int position, int accumulator) {
  return position >= v->size ? accumulator : get_sum(v, position+1, accumulator + v->vector[position]);
}

int main() {
  int data[] = {10, 1, 14, 2, 54, 18};

  Vector v;
  v.size = 6;
  v.vector = data;

  printf("The higest element from this vector is: %d\n", get_highest_element(&v, 0, v.vector[0]));
  printf("The lowest element from this vector is: %d\n", get_lowest_element(&v, 0, v.vector[0]));
  printf("The sum of elemets of the vector is: %d\n", get_sum(&v, 0, 0));

  return 0;
}