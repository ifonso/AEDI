#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Student new_student(int id, char * name, int age, int children) {
  Student s;
  s.id = id;
  s.age = age;
  s.children = children;
  strcpy(s.name, name);
  return s;
}

void print_student(Student s) {
  printf("ID: %d\n", s.id);
  printf("Name: %s\n", s.name);
  printf("Age: %d\n", s.age);
  printf("Children: %d\n", s.children);
}