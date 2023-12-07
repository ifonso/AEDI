#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#define MAX 100

typedef struct {
  int value;
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
int add_linked_list(LinkedList * l, int i);
// Add new item to list keeping ascendent order
int add_linked_list_ordered(LinkedList * l, int i);
// Remove item from list by value
int remove_linked_list_value(LinkedList * l, int i);
// Remove item from list by position
int remove_linked_list_position(LinkedList * l, int index);

// Get list length
int len_linked_list(LinkedList * l);
// Find element by value
int search_linked_list(LinkedList * l, int e);

// Print list values
void print_linked_list(LinkedList * l);

#endif /* LINKED_LIST_H_ */
