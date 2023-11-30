#include "linear_list.h"
#include "student.h"

#include <stdio.h>
#include <stdlib.h>

LinearList * create_linear_list() {
  LinearList * list = malloc(sizeof(LinearList));
  list->size = 0;
  list->capacity = MAX_CAPACITY;
  return list;
}

void destroy_linear_list(LinearList * list) {
  free(list);
}

int length(LinearList * list) {
  return list->size;
}

int is_empty(LinearList * list) {
  return list->size == 0;
}

int is_full(LinearList * list) {
  return list->size == list->capacity;
}

void print_list_elements(LinearList * list) {
  int i;
  for (i = 0; i < list->size; i++) {
    print_student(&list->students[i]);
  }
}

int insert_ordered(LinearList * list, Student * student) {
  if (is_full(list)) {
    return 0;
  }

  int i;
  for (i = 0; i < list->size; i++) {
    if (student->id < list->students[i].id) {
      break;
    }
  }

  int j;
  for (j = list->size; j > i; j--) {
    list->students[j] = list->students[j - 1];
  }

  list->students[i] = *student;
  list->size++;

  return 1;
}

int remove_element(LinearList * list, int id) {
  if (is_empty(list)) {
    return 0;
  }

  int i;
  for (i = 0; i < list->size; i++) {
    if (list->students[i].id == id) {
      break;
    }
  }

  if (i == list->size) {
    return 0;
  }

  int j;
  for (j = i; j < list->size - 1; j++) {
    list->students[j] = list->students[j + 1];
  }

  list->size--;

  return 1;
}

int change_element_id(LinearList * list, int old_id, int new_id) {
  if (is_empty(list)) {
    return 0;
  }

  int i, j;
  for (i = 0; i < list->size; i++) {
    if (list->students[i].id == old_id) {
      break;
    }
  }

  if (i == list->size) {
    return 0;
  }

  list->students[i].id = new_id;

  for (j = i; j > 0 && list->students[j-1].id > new_id; j--) {
    Student temp = list->students[j];
    list->students[j] = list->students[j-1];
    list->students[j-1] = temp;
  }

  for (j = i; j < list->size-1 && list->students[j+1].id < new_id; j++) {
    Student temp = list->students[j];
    list->students[j] = list->students[j+1];
    list->students[j+1] = temp;
  }

  return 1;
}

