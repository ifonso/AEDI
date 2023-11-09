#include "student.h"

#include <stdlib.h>
#include <string.h>

Student * create_student(int code, char * name, int age, float coefficient) {
  Student * student = (Student *) malloc(sizeof(Student));
  student->code = code;
  student->age = age;
  student->coefficient = coefficient;
  strcpy(student->name, name);
  return student;
}

void destroy_student(Student * student) {
  free(student);
}