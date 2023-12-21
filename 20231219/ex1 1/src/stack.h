#ifndef STACK_H_
#define STACK_H_

#include "plane.h"

typedef struct Node Node;
typedef struct Stack Stack;

struct Node {
  Plane * value;
  struct Node * next;
};

struct Stack {
  Node * top;
  int size;
};

Stack * create_stack();
void destroy_stack(Stack * s);

void push(Stack * s, Plane * plane);
Plane * pop(Stack * s);
Plane * pop_by_position(Stack * s, int position);

void print_planes(Stack * s);
void print_first_plane(Stack * s);


#endif // STACK_H_
