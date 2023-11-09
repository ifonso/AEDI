#include <stdio.h>
#include <stdlib.h>

// defining Vector type
typedef struct {
  int * data;
  int size;
} Vector;

// fill vector with random numbers
void fill(Vector * v) {
  for (int i = 0; i < v->size; i++) {
    v->data[i] = rand() % 10 + 1;
  }
}

void print_elements(Vector * v) {
  printf("Vector elements: ");
  for (int i = 0; i < v->size; i++) {
    printf("%d ", v->data[i]);
  }
  printf("\n");
}

int get_highest_elemet(Vector * v, int size) {
  if (size == 1) return v->data[0];
  int x = get_highest_elemet(v, size-1);
  return x > v->data[size-1] ? x : v->data[size-1];
}

int get_lowest_element(Vector * v, int size) {
  if (size == 1) return v->data[0];
  int x = get_lowest_element(v, size-1);
  return x < v->data[size-1] ? x : v->data[size-1];
}

int get_vector_sum(Vector * v, int size) {
  if (size == 1) return v->data[0];
  return v->data[size-1] + get_vector_sum(v, size-1);
}

int get_vector_product(Vector * v, int size) {
  if (size == 1) return v->data[0];
  return v->data[size-1] * get_vector_product(v, size-1);
}

int main() {
  Vector a;
  a.data = (int *) malloc(a.size * sizeof(int));
  a.size = 7;

  fill(&a);
  print_elements(&a);

  printf("\nThe highest element from vector is: %d\n", get_highest_elemet(&a, a.size));
  printf("The lowest element from vector is: %d\n", get_lowest_element(&a, a.size));
  
  printf("\nThe sum of the elements from vector is: %d\n", get_vector_sum(&a, a.size));
  printf("The product of the elements from vector is: %d\n", get_vector_product(&a, a.size));

  free(a.data);

  return 0;
}