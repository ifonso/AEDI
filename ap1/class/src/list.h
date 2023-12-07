#ifndef LIST_H_
#define LIST_H_

#include "student.h"

#define MAX 100

typedef struct {
  Student values[MAX];
  int length;
} List;

// List creation with a limit size of 100
List * new_list();
// Free memory allocated for list
void destroy_list(List * l);

// Add new item to list (not ordered)
int add_list(List * l, Student s);
// Add new item to list keeping ascendent order
int add_list_ordered(List * l, Student s);
// Remove item from list by value
int remove_list_value(List * l, Student s);
// Remove item from list by position
int remove_list_position(List * l, int index);

// Get list length
int len_list(List * l);
// Find element by value (return position index) (linear search)
int linear_search_list(List * l, int id);
// Find element by value (return position index) (binary search)
int binary_search_list(List * l, int id);

// Print list values
void print_list(List * l);

#endif /* LIST_H_ */