#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

typedef struct {
  int * data;
  int length;
  int capacity;
} List;

List * create_list(int capacity);
void destroy_list(List * list);

bool append(List * list, int value);
bool insert(List * list, int index, int value);

int remove_at(List * list, int index);
void print_list(List list);

#endif  // LIST_H_