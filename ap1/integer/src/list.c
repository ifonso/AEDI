#include "list.h"

#include <stdio.h>
#include <stdlib.h>

List * new_list() {
  List * l = (List *) malloc(sizeof(List));
  l->length = 0;
  return l;
}

void destroy_list(List * l) {
  free(l->values);
  free(l);
}

int add_list(List * l, int i) {
  if (l->length == MAX) return -1;
  l->values[l->length] = i;
  l->length++;
  return 0;
}

int add_list_ordered(List * l, int i) {
  if (l->length == MAX) return -1;
  int index = 0;
  while (index < l->length && l->values[index] < i) {
    index++;
  }
  for (int j = l->length; j > index; j--) {
    l->values[j] = l->values[j-1];
  }
  l->values[index] = i;
  l->length++;
  return 0;
}

int remove_list_value(List * l, int i) {
  int index = 0;
  while (index < l->length && l->values[index] != i) {
    index++;
  }
  if (index == l->length) return -1;
  for (int j = index; j < l->length-1; j++) {
    l->values[j] = l->values[j+1];
  }
  l->length--;
  return 0;
}

int remove_list_position(List * l, int index) {
  if (index >= l->length) return -1;
  for (int j = index; j < l->length-1; j++) {
    l->values[j] = l->values[j+1];
  }
  l->length--;
  return 0;
}

int len_list(List * l) {
  return l->length;
}

int linear_search_list(List * l, int e) {
  for (int i = 0; i < l->length; i++) {
    if (l->values[i] == e) return i;
  }
  return -1;
}

int binary_search_list(List * l, int e) {
  int left = 0;
  int right = l->length-1;
  while (left <= right) {
    int middle = (left + right) / 2;
    if (l->values[middle] == e) return middle;
    if (l->values[middle] < e) left = middle + 1;
    else right = middle - 1;
  }
  return -1;
}

void print_list(List * l) {
  printf("[");
  for (int i = 0; i < l->length; i++) {
    printf("%d", l->values[i]);
    if (i < l->length-1) printf(", ");
  }
  printf("]\n");
}