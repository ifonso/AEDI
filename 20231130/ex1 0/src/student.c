#include "student.h"

#include <string.h>
#include <stdlib.h>

Student * create_student(int id, char * name, int age) {
  Student * student = malloc(sizeof(Student));
  student->id = id;
  student->age = age;
  strcpy(student->name, name);
  return student;
}

void destroy_student(Student * student) {
  free(student);
}

void print_student(Student * student) {
  printf("Student %d: %s (age %d)\n", student->id, student->name, student->age);
}

void change_student_id(Student * student, int id) {
  student->id = id;
}