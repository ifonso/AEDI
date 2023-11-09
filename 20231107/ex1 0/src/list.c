#include "list.h"

#include <stdlib.h>
#include <stdio.h>

List * create_list(int size) {
  List * l = malloc(sizeof(List));
  l->size = size;
  l->vector = calloc(size, sizeof(int));
  return l;
}

void destroy_list(List * l) {
  free(l->vector);
  free(l);
}

void insert_random_elements(List * l) {
  for (int i = 0; i < l->size; i++) {
    l->vector[i] = rand() % 20;
  }
}

void insert_ordered_elements(List * l) {
  for (int i = 0; i < l->size; i++) {
    l->vector[i] = i + 1;
  }
}

void print_elements_iterative(List * l) {
  printf("\nElements on list:\n");
  for (int i = 0; i < l->size; i++) {
    printf("%d ", l->vector[i]);
  }
  printf("\n");
}

void print_elements_recursive(List * l, int position) {
  if (position == l->size) {
    printf("\n");
    return;
  }

  printf("%d ", l->vector[position]);
  print_elements_recursive(l, position+1);
}

int binary_search_recursive(List * l, int target, int low, int high) {
  if (low > high) return -1;

  int middle = (low + high) / 2;

  if (l->vector[middle] == target) return middle;
  if (l->vector[middle] > target) return binary_search_recursive(l, target, low, middle-1);

  return binary_search_recursive(l, target, middle+1, high);
}

int get_highest_element(List * v, int position, int current) {
  if (position == v->size) return current;

  return get_highest_element(
    v, position+1, v->vector[position] > current ? v->vector[position] : current
  );
}

int get_lowest_element(List * v, int position, int current) {
  if (position == v->size) return current;

  return get_lowest_element(
    v, position+1, v->vector[position] < current ? v->vector[position] : current
  );
}

int get_sum_recursive(List * l, int position, int cumulator) {
  return position >= l->size ? cumulator : get_sum_recursive(l, position+1, cumulator + l->vector[position]);
}

int get_product_recursive(List * l, int position, int cumulator) {
  return position >= l->size ? cumulator : get_product_recursive(l, position+1, cumulator * l->vector[position]);
}