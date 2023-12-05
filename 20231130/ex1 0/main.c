#include "llist.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
  LList * list = create_list();

  insert_student_ordered(list, 1, "Afonso", 22);
  insert_student_ordered(list, 5, "Bruno", 23);
  insert_student_ordered(list, 10, "Carlos", 24);
  insert_student_ordered(list, 3, "Jennifer", 23);
  insert_student_ordered(list, 11, "Julia", 21);

  // Basic operations
  printf("List is empty? %s\n", is_empty(list) ? "Yes" : "No");
  printf("List is full? %s\n", is_full(list) ? "Yes" : "No");
  printf("List length: %d\n\n", length(list));
  
  // Print list
  print_list(list);

  printf("\nRemoving student:\n");
  
  remove_student(list, 5);
  print_list(list);

  printf("\nChange student id:\n");

  change_student_id(list, 11, 2);
  print_list(list);

  return 0;
}