#include "./src/linked_list.h"
#include "./src/student.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Linked List -----------------------------------
  LinkedList * linked = new_linked_list();

  Student s1 = new_student(5, "Carlos", 25, 0);
  Student s2 = new_student(2, "Algusto", 36, 2);
  Student s3 = new_student(10, "Anastacia", 27, 0);
  Student s4 = new_student(4, "Afonso", 22, 0);

  add_linked_list(linked, s1);
  add_linked_list(linked, s2);
  add_linked_list(linked, s3);
  add_linked_list(linked, s4);

  print_linked_list(linked);

  remove_linked_list_value(linked, s2);
  remove_linked_list_position(linked, 0);

  print_linked_list(linked);

  destroy_linked_list(linked);
  return 0;
}