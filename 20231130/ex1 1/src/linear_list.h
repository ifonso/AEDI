#ifndef LINEAR_LIST_H_
#define LINEAR_LIST_H_

#include "student.h"

#define MAX_CAPACITY 100

typedef struct {
  Student students[MAX_CAPACITY];
  int size;
  int capacity;
} LinearList;

LinearList * create_linear_list();
void destroy_linear_list(LinearList * list);

int length(LinearList * list);
int is_empty(LinearList * list);
int is_full(LinearList * list);

void print_list_elements(LinearList * list);

int insert_ordered(LinearList * list, Student * student);
int remove_element(LinearList * list, int id);

int change_element_id(LinearList * list, int old_id, int new_id);

#endif /* LINEAR_LIST_H_ */