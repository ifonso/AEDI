#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

List * create_list(int capacity) {
  List * list = malloc(sizeof(List));
  list->data = calloc(capacity, sizeof(int));
  list->length = 0;
  list->capacity = capacity;
  return list;
}

void destroy_list(List * list) {
  free(list->data);
  free(list);
}

bool append(List * list, int value) {
  if (list == NULL || list->length == list->capacity)
  return false;

  list->data[list->length] = value;
  list->length++;
  return true;
}

bool insert(List * list, int index, int value) {
  if (list == NULL || list->length == list->capacity)
  return false;

  for (int i = list->length; i > index; i--) {
    list->data[i] = list->data[i - 1];
  }
  list->data[index] = value;
  list->length++;
  return true;
}

int remove_at(List * list, int index) {
  if (list == NULL || index < 0 || index >= list->length)
  return 0;

  int value = list->data[index];
  for (int i = index; i < list->length - 1; i++) {
    list->data[i] = list->data[i + 1];
  }
  list->length--;
  return value;
}

void print_list(List list) {
  printf("[");
  for (int i = 0; i < list.length; i++) {
    printf("%d", list.data[i]);
    if (i < list.length - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}