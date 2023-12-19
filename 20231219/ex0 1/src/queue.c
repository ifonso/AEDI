#include "queue.h"
#include "plane.h"

#include <stdio.h>
#include <stdlib.h>

Queue * create_queue() {
  Queue * q = (Queue *) malloc(sizeof(Queue));

  if (q == NULL) {
    fprintf(stderr, "Error: could not allocate memory for queue.\n");
    exit(1);
  }

  q->head = NULL;
  q->tail = NULL;
  q->size = 0;

  return q;
}

void destroy_queue(Queue * queue) {
  Node * current = queue->head;
  Node * next = NULL;

  while (current != NULL) {
    next = current->next;
    destroy_plane(current->plane);
    free(current);
    current = next;
  }

  free(queue);
}

void enqueue(Queue * queue, Plane * plane) {
  Node * n = (Node *) malloc(sizeof(Node));
  n->plane = plane;

  if (queue->head == NULL) {
    queue->head = n;
    queue->tail = n;
  } else {
    n->next = queue->tail;
    queue->tail = n;
  }  

  queue->size++;
}

Plane * dequeue(Queue * queue) {
  if (queue->tail == NULL) {
    fprintf(stderr, "Error: queue is empty.\n");
    exit(1);
  }

  Node * current = queue->tail;
  Node * previous = NULL;

  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }

  Plane * plane = current->plane;

  if (previous == NULL) {
    queue->tail = NULL;
  } else {
    previous->next = NULL;
  }

  queue->size--;

  return plane;
}

int queue_size(Queue * queue) {
  return queue->size;
}

void print_first_plane(Queue * queue) {
  if (queue->tail == NULL) {
    fprintf(stderr, "Error: queue is empty.\n");
    exit(1);
  }

  print_plane(queue->head->plane);
}

void print_planes(Queue * queue) {
  Node * current = queue->tail;

  while (current != NULL) {
    print_plane(current->plane);
    current = current->next;
  }
}