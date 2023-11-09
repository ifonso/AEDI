#include "class.h"

#include <stdlib.h>
#include <stdio.h>

Class * create_class(int capacity) {
  Class * class = (Class *) malloc(sizeof(Class));
  class->students = (Student **) malloc(capacity * sizeof(Student));
  class->capacity = capacity;
  class->number_of_students = 0;
  return class;
}

void destroy_class(Class * class) {
  if (class == NULL) return;
  for (int i = 0; i < class->number_of_students; i++) {
    Student * student = class->students[i];
    free(student);
  }
  free(class->students);
  free(class);
}

void insert_student(Class * class, char name[20], int age, float coefficient) {
  if (class->number_of_students == class->capacity || class == NULL) return;
  int code = class->number_of_students + 1;
  Student * student = create_student(code, name, age, coefficient);
  class->students[class->number_of_students] = student;
  class->number_of_students++;
}

void print_students(Class * class) {
  if (class == NULL) return;
  for (int i = 0; i < class->number_of_students; i++) {
    Student * student = class->students[i];
    printf("Student code: %d\n", student->code);
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Coefficient: %.2f\n\n", student->coefficient);
  }
}

Student * find_student(Class * class, int code) {
  if (class == NULL) return NULL;
  for (int i = 0; i < class->number_of_students; i++) {
    Student * student = class->students[i];
    if (student->code == code) return student;
  }
  return NULL;
}