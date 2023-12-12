#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"
#include "student.h"

int main() {
  printf("\nAluno: AFONSO LUCAS\n\n");

  // Creating students list
  List * students = new_list();

  // Creating students
  Student s1 = new_student(1, "Daniel", 21, 0);
  Student s2 = new_student(2, "Suza", 19, 0);
  Student s3 = new_student(3, "Danilo", 24, 1);
  Student s4 = new_student(4, "Camila", 18, 0);
  Student s5 = new_student(5, "Carlos", 22, 1);

  add_list(students, s1);
  add_list(students, s2);
  add_list(students, s3);
  add_list(students, s4);
  add_list(students, s5);

  printf("Students:\n");
  print_list(students);

  printf("The age average is %.2f\n\n", get_average_students_age(students));

  // Free memory allocated
  destroy_list(students);

  time_t now;
  time(&now);
  printf("Data e hora de entrega %s", ctime(&now));
}