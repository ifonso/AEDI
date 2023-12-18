#include "LinkedList.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
  LinkedList * l = create_list();

  insert(l, 1);
  insert(l, 2);
  insert(l, 3);
  insert(l, 4);
  insert(l, 5);

  printf("\nOriginal list:\n");
  print_list(l);

  LinkedList * l2 = create_translated_list(l, 1);

  printf("\nTranslated list:\n");
  print_list(l2);

  LinkedList * l3 = create_reversed_list(l);

  printf("\nReversed list:\n");
  print_list(l3);

  // Free the memory
  // destroy_list(l);
  // destroy_list(l2);
  // destroy_list(l3);

  return 0;
}