#include <h_table.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int hash(int size, int v) {
  return (2*v + 5) % size;
}

void ht_init(H_TABLE * t, int c) {
  t->capacity = c;
  t->table = malloc(sizeof(Node *) * c);

  for (int i = 0; i < c; i++) {
    t->table[i] = NULL;
  }
}

void ht_print(H_TABLE * t) {
  for (int i = 0; i < t->capacity; i++) {
    Node * n = t->table[i];
    printf("[%d] ", i);
    while(n != NULL) {
      printf("%d -> ", n->data);
      n = n->next;
    }
    printf("\n");
  }
}

int ht_insert(H_TABLE * t, int v) {
  int i = hash(t->capacity, v);
  Node * n = t->table[i];
  Node * new_node = malloc(sizeof(Node));
  new_node->data = v;
  new_node->next = NULL;

  if (n == NULL) {
    t->table[i] = new_node;
    return 1;
  }

  while (n->next != NULL) {
    if (n->data == v) return 0;
    n = n->next;
  }
  
  n->next = new_node;
  return 1;
}