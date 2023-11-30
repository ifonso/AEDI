#include "list.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  List * list = create_list(5);

  // Adding elements
  append(list, 1);
  append(list, 2);
  append(list, 3);

  print_list(*list);

  // Inserting at specific position
  insert(list, 1, 4);
  insert(list, 2, 5);

  print_list(*list);

  // Removing at specific position
  remove_at(list, 0);

  print_list(*list);

  // Free memory
  destroy_list(list);
}