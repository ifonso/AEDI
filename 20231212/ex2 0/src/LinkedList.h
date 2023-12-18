#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct Node Node;

struct Node {
  int value;
  Node * next;
};

typedef struct {
  Node * first;
} LinkedList;

/* Properties */
LinkedList * create_list();
LinkedList * create_translated_list(LinkedList * l, int offset);
LinkedList * create_reversed_list(LinkedList * l);

void destroy_list(LinkedList * l);

void print_list(LinkedList * l);

void insert(LinkedList * l, int value);
void remove_by_value(LinkedList * l, int value);

#endif /* LINKED_LIST_H_ */
