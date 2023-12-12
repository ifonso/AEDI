#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Create list
  LinkedList * l = create_list();

  // Insert values
  insert_ordered(l, 1, "Afonso", 20);
  insert_ordered(l, 10, "Bruno", 21);
  insert_ordered(l, 5, "Ana", 22);
  insert_ordered(l, 3, "Jennifer", 23);

  // Print list
  print_list(l);

  // Removing Bruno
  remove_by_value(l, 10);

  // Print list
  print_list(l);

  // Destroy list
  destroy_list(l);
  return 0;
}