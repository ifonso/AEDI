#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "class.h"

int main() {
  Class * math_class = create_class(3);

  insert_student(math_class, "Afonso", 22, 9.0);
  insert_student(math_class, "Mary", 19, 3.0);
  insert_student(math_class, "John", 20, 7.0);

  print_students(math_class);

  Student * student = find_student(math_class, 1);
  printf("\n%s is on math class, and has a coefficient of %.2f\n", student->name, student->coefficient);

  free(student);
  free(math_class);

  return 0;
}