#include "deque.h"
#include "soldier.h"

#include <stdlib.h>
#include <stdio.h>

void deque_init(Deque * q) {
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;
}

void deque_insert_start(Deque * q, Soldier * s) {
  Node * n = (Node *) malloc(sizeof(Node));
  n->soldier = s;
  n->prev = NULL;
  n->next = q->head;

  if (q->head == NULL) {
    q->tail = n;
  } else {
    q->head->prev = n;
  }

  q->head = n;
  q->size++;
}

void deque_insert_end(Deque * q, Soldier * s) {
  Node * n = (Node *) malloc(sizeof(Node));
  n->soldier = s;
  n->prev = q->tail;
  n->next = NULL;

  if (q->tail == NULL) {
    q->head = n;
  } else {
    q->tail->next = n;
  }

  q->tail = n;
  q->size++;
}

Soldier * deque_remove_start(Deque * q) {
  if (q->size == 0) {
    perror("Deque is empty");
    exit(EXIT_FAILURE);
  }

  Node * n = q->head;
  Soldier * s = n->soldier;

  q->head = n->next;
  q->size--;
  free(n);

  return s;
}

Soldier * deque_remove_end(Deque * q) {
  if (q->size == 0) {
    perror("Deque is empty");
    exit(EXIT_FAILURE);
  }

  Node * n = q->tail;
  Soldier * s = n->soldier;

  q->tail = n->prev;
  q->size--;
  free(n);

  return s;
}

Soldier * deque_remove_pos(Deque * q, int pos) {
  if (q->size == 0) {
    perror("Deque is empty");
    exit(EXIT_FAILURE);
  }

  if (pos < 0 || pos >= q->size) {
    perror("Invalid position");
    exit(EXIT_FAILURE);
  }

  Node * n = q->head;
  for (int i = 0; i < pos; i++) {
    n = n->next;
  }

  Soldier * s = n->soldier;

  if (n == q->head) {
    q->head = n->next;
  } else {
    n->prev->next = n->next;
  }

  if (n == q->tail) {
    q->tail = n->prev;
  } else {
    n->next->prev = n->prev;
  }

  q->size--;
  free(n);

  return s;
}

Soldier * first(Deque * q) {
  if (q->size == 0) {
    perror("Deque is empty");
    exit(EXIT_FAILURE);
  }

  return q->head->soldier;
}

Soldier * last(Deque * q) {
  if (q->size == 0) {
    perror("Deque is empty");
    exit(EXIT_FAILURE);
  }

  return q->tail->soldier;
}

int deque_size(Deque * q) {
  return q->size;
}

int deque_is_empty(Deque * q) {
  return q->size == 0;
}

void destroy(Deque * q) {
  while (q->size > 0) {
    deque_remove_start(q);
  }
}

Soldier * josephus(Deque * q, int n) {
  if (q->size == 0) {
    perror("Deque is empty");
    exit(EXIT_FAILURE);
  }

  int index = n;

  while (deque_size(q) > 1) {
    int pos = index % deque_size(q);

    Soldier * s = deque_remove_pos(q, pos);
    index = pos + 1;

    printf("Soldado %s removido.\n", s->name);
  }

  return q->head->soldier;
}