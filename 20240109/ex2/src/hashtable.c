#include "hashtable.h"
#include "patient.h"

#include <string.h>
#include <stdlib.h>

int hash(int code) {
  return code % MAX_CAPACITY;
}

void ht_init(HTable ht) {
  memset(ht, 0, sizeof(Node *) * MAX_CAPACITY);
}

void ht_insert(HTable ht, Patient p) {
  int i = hash(p.code);
  Node * node = malloc(sizeof(Node));
  node->next = NULL;
  node->value = malloc(sizeof(Patient));
  *(node->value) = p;

  if (ht[i] == NULL) {
    ht[i] = node;
  } else {
    Node * current = ht[i];
    while(current->next != NULL) {
      current = current->next;
    }
    current->next = node;
  }
}

Patient * ht_search(HTable ht, int code) {
  int i = hash(code);
  Node * node = ht[i];
  while(node != NULL) {
    if (node->value->code == code) return node->value;
    node = node->next;
  }
  return NULL;
}
