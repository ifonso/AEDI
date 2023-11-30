#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Student * create_student(int id, char * name) {
  Student * student = malloc(sizeof(Student));
  student->id = id;
  strcpy(student->name, name);
  return student;
}

void destroy_student(Student * student) {
  free(student);
}

void print_student(Student * student) {
  printf("Student %d: %s\n", student->id, student->name);
}

void change_student_id(Student * student, int new_id) {
  student->id = new_id;
}
