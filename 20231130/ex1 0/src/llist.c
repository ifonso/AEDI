#include "llist.h"
#include "student.h"

#include <stdlib.h>

LList * create_list() {
  LList * list = malloc(sizeof(LList));
  list->first = -1;
  list->available = 0;

  for (int i = 0; i < MAX - 1; i++) {
    list->nodes[i].next = i + 1;
  }

  list->nodes[MAX - 1].next = -1;
  return list;
}

void destroy_list(LList * list) {
  free(list);
}

int length(LList * list) {
  int length = 0;
  int current = list->first;

  while (current != -1) {
    length++;
    current = list->nodes[current].next;
  }

  return length;
}

int is_full(LList * list) {
  return list->available == -1;
}

int is_empty(LList * list) {
  return list->first == -1;
}

void print_list(LList * list) {
  int current = list->first;

  while (current != -1) {
    print_student(list->nodes[current].student);
    current = list->nodes[current].next;
  }
}

void insert_ordered(LList * list, Student * student) {
  if (is_full(list)) {
    printf("List is full\n");
    return;
  }

  int current = list->first;
  int previous = -1;

  while (current != -1 && student->id > list->nodes[current].student->id) {
    previous = current;
    current = list->nodes[current].next;
  }

  int available = list->available;
  list->available = list->nodes[available].next;

  list->nodes[available].student = student;
  list->nodes[available].next = current;

  if (previous == -1) {
    list->first = available;
  } else {
    list->nodes[previous].next = available;
  }
}

void remove_student(LList * list, int id) {
  int current = list->first;
  int previous = -1;

  while (current != -1 && list->nodes[current].student->id != id) {
    previous = current;
    current = list->nodes[current].next;
  }

  if (current == -1) {
    printf("Student %d not found\n", id);
    return;
  }

  if (previous == -1) {
    list->first = list->nodes[current].next;
  } else {
    list->nodes[previous].next = list->nodes[current].next;
  }

  list->nodes[current].next = list->available;
  list->available = current;
}

void change_student_id(LList * list, int id, int new_id) {
  int current = list->first;

  while (current != -1 && list->nodes[current].student->id != id) {
    current = list->nodes[current].next;
  }

  if (current == -1) {
    printf("Student %d not found\n", id);
    return;
  }

  list->nodes[current].student->id = new_id;
}