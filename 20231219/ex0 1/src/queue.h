#ifndef QUEUE_H_
#define QUEUE_H_

#include "plane.h"

typedef struct Node Node;

struct Node {
  Plane * plane;
  struct Node * next;
};

typedef struct {
  Node * head;
  Node * tail;
  int size;
} Queue;

Queue * create_queue();
void destroy_queue(Queue * queue);

void enqueue(Queue * queue, Plane * plane);
Plane * dequeue(Queue * queue);

int queue_size(Queue * queue);

void print_first_plane(Queue * queue);
void print_planes(Queue * queue);

#endif /* QUEUE_H_ */