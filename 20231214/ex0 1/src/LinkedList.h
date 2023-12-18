#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct LinkedList LinkedList;

typedef struct Node Node;

struct Node {
  int data;
  struct Node * next;
  struct Node * prev;
};

struct LinkedList {
  struct Node * head;
  int size;
};

LinkedList * create_linked_list();
void destroy_linked_list(LinkedList * list);

LinkedList * create_ordered_linked_list(LinkedList * list);

void push(LinkedList * list, int data);
void remove_data(LinkedList * list, int data);

void print_linked_list(LinkedList * list);

void push_node_to_list(LinkedList * list, Node * node);
void remove_node_from_list(LinkedList * list, Node * node);

#endif // LINKED_LIST_H_