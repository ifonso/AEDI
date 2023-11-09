#include "src/list.h"
#include <stdio.h>

int main() {
  int first_size;
  List * first_list;

  // 1. Get list size from user
  printf("Enter list size: ");
  scanf("%d", &first_size);

  first_list = create_list(first_size);
  insert_random_elements(first_list);
  // 2. print list elements
  print_elements(first_list);

  int selected_number, selected_position;

  // 3. Ask user for an element
  printf("Which element are you looking for? ");
  scanf("%d", &selected_number);

  selected_position = linear_search(first_list, selected_number);

  if (selected_position == -1) {
    printf("Element not found\n");
  } else {
    printf("Element found at position %d\n", selected_position);
  }

  // 4. Create a second list with ordered elements
  List * second_list = create_list(30);
  insert_ordered_elements(second_list);
  // 5. Print second list elements
  print_elements(second_list);

  // 6. Ask user for an element and search using the three methods
  printf("\nWhich element are you looking for on second list? ");
  scanf("%d", &selected_number);

  printf("linear search result: %d\n", linear_search(second_list, selected_number));
  printf("ordered linear search result: %d\n", ordered_linear_search(second_list, selected_number));
  printf("binary search result: %d\n", binary_search(second_list, selected_number));

  // 7. Code changes on list.c ...

  // 8. Print the highest element on the first list
  printf("\nHighest element on first list: %d\n", get_higher_element(first_list));
  // 9. Print the lowest element on the first list
  printf("Lowest element on first list: %d\n", get_lower_element(first_list));
  // 10. Print the sum of all elements on the first list
  printf("Sum of all elements on first list: %d\n", get_sum(first_list));
  // 11. Print the product of all elements on the first list
  printf("Product of all elements on first list: %d\n", get_product(first_list));
  
  // free the memory
  destroy_list(first_list);
  destroy_list(second_list);
  
  return 0;
}