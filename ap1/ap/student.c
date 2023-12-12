#include "student.h"

#include <string.h>

Student new_student(int code, char * name, int age, int children) {
  Student s;
  s.code = code;
  s.age = age;
  s.children = children;
  strcpy(s.name, name);
  return s;
}