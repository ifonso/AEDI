#ifndef CLASS_H_
#define CLASS_H_

#include "student.h"

typedef struct {
  Student ** students;
  int number_of_students;
  int capacity;
} Class;

Class * create_class(int capacity);
void destroy_class(Class * class);

void print_students(Class * class);
void insert_student(Class * class, char name[20], int age, float coefficient);
Student * find_student(Class * class, int code);

#endif // CLASS_H_