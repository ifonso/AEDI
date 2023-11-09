#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main() {
  List * list = create_list(10);
  
  insert_ordered_elements(list);
  print_elements_recursive(list, 0);

  int target = 4;
  int position = binary_search_recursive(list, target, 0, list->size);

  if (position == -1) {
    printf("The target %d was not found on the list\n", target);
  } else {
    printf("The target %d was found on the list at position [%d]\n", target, position);
  }

  printf("The highest element on the list is %d\n", get_highest_element(list, 0, list->vector[0]));
  printf("The lowest element on the list is %d\n", get_lowest_element(list, 0, list->vector[0]));

  printf("The sum of all elements on the list is %d\n", get_sum_recursive(list, 0, 0));
  printf("The product of all elements on the list is %d\n", get_product_recursive(list, 0, 1));

  destroy_list(list);

  return 0;
}