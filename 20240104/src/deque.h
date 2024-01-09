#ifndef DEQUE_H_
#define DEQUE_H_

#include "soldier.h"

typedef struct Node Node;

struct Node {
  Soldier * soldier;
  struct Node * prev;
  struct Node * next;
};

typedef struct {
  Node * head;
  Node * tail;
  int size;
} Deque;

void deque_init(Deque * queue);

void deque_insert_start(Deque * q, Soldier * s);
void deque_insert_end(Deque * q, Soldier * s);

Soldier * deque_remove_start(Deque * q);
Soldier * deque_remove_end(Deque * q);
Soldier * deque_remove_pos(Deque * q, int pos);

Soldier * first(Deque * q);
Soldier * last(Deque * q);

int deque_size(Deque * q);
int deque_is_empty(Deque * q);

void destroy(Deque * q);

Soldier * josephus(Deque * q, int n);

#endif // DEQUE_H_
