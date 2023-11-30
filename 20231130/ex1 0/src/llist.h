#ifndef LLIST_H_
#define LLIST_H_

#define MAX 100

#include "student.h"

typedef struct {
  Student * student;
  int next;
} LNode;

typedef struct {
  LNode nodes[MAX];
  int first;
  int available;
} LList;

LList * create_list();
void destroy_list(LList * list);

int length(LList * list);
int is_full(LList * list);
int is_empty(LList * list);

void print_list(LList * list);
void insert_ordered(LList * list, Student * student);

void remove_student(LList * list, int id);
void change_student_id(LList * list, int id, int new_id);

#endif /* LLIST_H_ */