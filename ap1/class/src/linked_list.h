#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "student.h"

#define MAX 100

typedef struct {
  Student value;
  int next;
 } Node;

typedef struct {
  Node nodes[MAX];
  int first;
  int available;
} LinkedList;

// List creation with a limit size of 100
LinkedList * new_linked_list();
// Free memory allocated for list
void destroy_linked_list(LinkedList * l);

// Add new item to list (not ordered)
int add_linked_list(LinkedList * l, Student s);
// Add new item to list keeping ascendent order
int add_linked_list_ordered(LinkedList * l, Student s);
// Remove item from list by value
int remove_linked_list_value(LinkedList * l, Student s);
// Remove item from list by position
int remove_linked_list_position(LinkedList * l, int index);

// Get list length
int len_linked_list(LinkedList * l);
// Find element by value (return position index)
int search_linked_list(LinkedList * l, int id);

// Print list values
void print_linked_list(LinkedList * l);

#endif /* LINKED_LIST_H_ */
