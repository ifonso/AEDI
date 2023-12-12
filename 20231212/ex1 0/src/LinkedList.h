#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#define NAME_LENGTH 30

typedef struct Node Node;
typedef struct Student Student;

struct Student {
  int id;
  char name[NAME_LENGTH];
  int age;
};

struct Node {
  Student value;
  Node * next;
};

typedef struct {
  Node * first;
} LinkedList;

/* Properties */
LinkedList * create_list();
void destroy_list(LinkedList * l);

int length(LinkedList * l);
int is_empty(LinkedList * l);
void print_list(LinkedList * l);

void insert_ordered(LinkedList * l, int id, char * name, int age);
void remove_by_value(LinkedList * l, int id);

#endif /* LINKED_LIST_H_ */
