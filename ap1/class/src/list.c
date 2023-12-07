#include "list.h"
#include "student.h"

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
  if (l->length == MAX) return -1;
  
  l->values[l->length] = s;
  l->length++;

  return 1;
}

int add_list_ordered(List * l, Student s) {
  if (l->length == MAX) return -1;

  int i = 0;
  while (i < l->length && compare_student(l->values[i], s) < 0) {
    i++;
  }

  for (int j = l->length; j > i; j--) {
    l->values[j] = l->values[j-1];
  }

  l->values[i] = s;
  l->length++;

  return 1;
}

int remove_list_value(List * l, Student s) {
  int i = 0;
  while (i < l->length && compare_student(l->values[i], s) != 0) {
    i++;
  }

  if (i == l->length) return -1;

  for (int j = i; j < l->length-1; j++) {
    l->values[j] = l->values[j+1];
  }

  l->length--;

  return 1;
}

int remove_list_position(List * l, int index) {
  if (index < 0 || index >= l->length) return -1;

  for (int j = index; j < l->length-1; j++) {
    l->values[j] = l->values[j+1];
  }

  l->length--;

  return 1;
}

int len_list(List * l) {
  return l->length;
}

int linear_search_list(List * l, int id) {
  for (int i = 0; i < l->length; i++) {
    if (l->values[i].id == id) return i;
  }

  return -1;
}

int binary_search_list(List * l, int id) {
  int left = 0;
  int right = l->length-1;

  while (left <= right) {
    int middle = (left + right) / 2;

    if (l->values[middle].id == id) return middle;

    if (l->values[middle].id < id) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  return -1;
}

void print_list(List * l) {
  for (int i = 0; i < l->length; i++) {
    printf("\n");
    print_student(l->values[i]);
  }
}
