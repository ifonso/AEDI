#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "list.h"

int main() {
  // Linked List --------------------------------------------------------------
  printf("\nLinked List\n");
  LinkedList * list = new_linked_list();

  add_linked_list_ordered(list, 5);
  add_linked_list_ordered(list, 5);
  add_linked_list_ordered(list, 10);
  add_linked_list_ordered(list, 4);
  add_linked_list_ordered(list, 17);

  print_linked_list(list);

  remove_linked_list_value(list, 5);
  remove_linked_list_value(list, 17);
  remove_linked_list_position(list, 1);

  print_linked_list(list);

  free(list);

  // List ---------------------------------------------------------------------
  printf("\nList\n");
  List * list2 = new_list();

  add_list_ordered(list2, 5);
  add_list_ordered(list2, 5);
  add_list_ordered(list2, 10);
  add_list_ordered(list2, 4);
  add_list_ordered(list2, 17);

  print_list(list2);

  printf("Element 4 is in position %d\n", binary_search_list(list2, 4));

  remove_list_value(list2, 5);
  remove_list_value(list2, 17);
  remove_list_position(list2, 1);

  print_list(list2);


  free(list2);

  return 0;
}