#include "src/linear_list.h"
#include "src/student.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  LinearList * list = create_linear_list();

  Student * s1 = create_student(10, "Afonso");
  Student * s2 = create_student(32, "Duda");
  Student * s3 = create_student(21, "Eduardo");
  Student * s4 = create_student(40, "Clara");
  Student * s5 = create_student(7, "Arnaldo");

  insert_ordered(list, s1);
  insert_ordered(list, s2);
  insert_ordered(list, s3);
  insert_ordered(list, s4);
  insert_ordered(list, s5);

  print_list_elements(list);

  printf("\nRemoving elements keeping orrder:\n\n");

  remove_element(list, 7);
  print_list_elements(list);

  printf("\nChanging element id:\n\n");

  change_element_id(list, 10, 22);
  print_list_elements(list);

  // Free the memory
  destroy_linear_list(list);

  destroy_student(s1);
  destroy_student(s2);
  destroy_student(s3);
  destroy_student(s4);
  destroy_student(s5);

  return 0;
}