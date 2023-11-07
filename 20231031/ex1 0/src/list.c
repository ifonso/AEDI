#include "list.h"

#include <stdlib.h>
#include <stdio.h>

/* Life cycle */
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

int get_sum(List * l) {
  int sum = 0;

  for (int i = 0; i < l->size; i++) {
    sum += l->vector[i];
  }
  return sum;
}

int get_product(List * l) {
  int product = 1;

  for (int i = 0; i < l->size; i++) {
    product *= l->vector[i];
  }
  return product;
}

/* Utility */
void insert_random_elements(List * l) {
  for (int i = 0; i < l->size; i++) {
    l->vector[i] = rand() % 100;
  }
}

void insert_ordered_elements(List * l) {
  for (int i = 0; i < l->size; i++) {
    l->vector[i] = i;
  }
}

void print_elements(List * l) {
  printf("\nElements on vector:\n");

  for (int i = 0; i < l->size; i++) {
    printf("[%d] -> %d    ", i, l->vector[i]);
  }
  printf("\n");
}

/* Search */
int linear_search(List * l, int element) {
  int iterations = 0;

  for (int i = 0; i < l->size; i++) {
    iterations += 1;

    if (l->vector[i] == element) {
      printf("\nTotal iterations of linear search: %d\n", iterations);
      return i;
    }
  }
  printf("\nTotal iterations of linear search: %d\n", iterations);
  return -1;
}

int ordered_linear_search(List * l, int element) {
  int iterations = 0;

  for (int i = 0; i < l->size; i++) {
    iterations += 1;

    if (l->vector[i] == element) {
      printf("\nTotal iterations of ordered linear search: %d\n", iterations);
      return i;
    }

    if (l->vector[i] > element) {
      printf("\nTotal iterations of ordered linear search: %d\n", iterations);
      return -1;
    }
  }
  printf("\nTotal iterations of ordered linear search: %d\n", iterations);
  return -1;
}

int binary_search(List * l, int element) {
  int iterations = 0;
  int lo = 0;
  int hi = l->size - 1;
  int middle;

  while (hi >= lo) {
    iterations += 1;
    middle = (lo + hi) / 2;

    if (l->vector[middle] == element) {
      printf("\nTotal iterations of binary search: %d\n", iterations);
      return middle;
    }

    if (l->vector[middle] < element) {
      lo = middle + 1;
    } else {
      hi = middle - 1;
    }
  }
  printf("\nTotal iterations of binary search: %d\n", iterations);
  return -1;
}

int get_higher_element(List * l) {
  int higher = l->vector[0];

  for (int i = 1; i < l->size; i++) {
    if (l->vector[i] > higher) {
      higher = l->vector[i];
    }
  }
  return higher;
}

int get_lower_element(List * l) {
  int lower = l->vector[0];

  for (int i = 1; i < l->size; i++) {
    if (l->vector[i] < lower) {
      lower = l->vector[i];
    }
  }
  return lower;
}