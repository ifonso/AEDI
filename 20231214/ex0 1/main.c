#include "src/LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  LinkedList * list = create_linked_list();

  push(list, 7);
  push(list, 1);
  push(list, 6);
  push(list, 2);
  push(list, 8);
  push(list, 3);
  push(list, 5);
  push(list, 4);

  printf("Unordered list:\n");
  print_linked_list(list);
  printf("\n");

  // Creating an ordered list from the unordered one

  LinkedList * ordered_list = create_ordered_linked_list(list);

  printf("Ordered list:\n");
  print_linked_list(ordered_list);
  printf("\n");

  // free the memory
  destroy_linked_list(list);
  destroy_linked_list(ordered_list);

  return 0;
}