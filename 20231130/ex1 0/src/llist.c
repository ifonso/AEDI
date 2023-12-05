#include "llist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student -------------------------

Student create_student(int id, char * name, int age) {
  Student student;
  student.id = id;
  strcpy(student.name, name);
  student.age = age;
  return student;
}

void print_student(Student student) {
  printf("Student (%d): %s -> %dy\n", student.id, student.name, student.age);
}

// List ----------------------------

LList * create_list() {
  LList * list = (LList *) malloc(sizeof(LList));
  list->first = -1;
  list->available = 0;

  for (int i = 0; i < MAX - 1; i++) {
    list->nodes[i].next = i + 1;
  }

  list->nodes[MAX - 1].next = -1;
  return list;
}

void destroy_list(LList * list) {
  free(list->nodes);
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

void insert_student_ordered(LList * list, int id, char * name, int age) {
  // List is full
  if (is_full(list)) return;

  int previous = -1;
  int current = list->first;

  while (current != -1 && list->nodes[current].student.id < id) {
    previous = current;
    current = list->nodes[current].next;
  }

  // Student already exists
  if (current != -1 && list->nodes[current].student.id == id) return;

  int available = list->available;
  list->available = list->nodes[available].next;

  list->nodes[available].student = create_student(id, name, age);

  if (previous == -1) {
    list->nodes[available].next = list->first;
    list->first = available;
  } else {
    list->nodes[available].next = list->nodes[previous].next;
    list->nodes[previous].next = available;
  }
}

void remove_student(LList * list, int id) {
  // List is empty
  if (is_empty(list)) return;

  int previous = -1;
  int current = list->first;

  while (current != -1 && list->nodes[current].student.id < id) {
    previous = current;
    current = list->nodes[current].next;
  }

  // Student doesn't exist
  if (current == -1 || list->nodes[current].student.id != id) return;

  if (previous == -1) {
    list->first = list->nodes[current].next;
  } else {
    list->nodes[previous].next = list->nodes[current].next;
  }

  list->nodes[current].next = list->available;
  list->available = current;
}

void change_student_id(LList * list, int id, int new_id) {
  // List is empty
  if (is_empty(list)) return;

  int current = list->first;

  while (current != -1 && list->nodes[current].student.id < id) {
    current = list->nodes[current].next;
  }

  // Student doesn't exist
  if (current == -1 || list->nodes[current].student.id != id) return;

  Student student = list->nodes[current].student;

  remove_student(list, id);
  insert_student_ordered(list, new_id, student.name, student.age);
}

void print_list(LList * list) {
  int current = list->first;

  printf("\nList of students:\n\n");

  while (current != -1) {
    print_student(list->nodes[current].student);
    current = list->nodes[current].next;
  }
}