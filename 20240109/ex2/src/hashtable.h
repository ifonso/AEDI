#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#define MAX_CAPACITY 101

#include "patient.h"

typedef struct {
  Patient * value;
  void * next;
} Node;

typedef Node * HTable[MAX_CAPACITY];

void ht_init(HTable ht);
void ht_insert(HTable ht, Patient p);
void ht_print(HTable ht);
Patient * ht_search(HTable ht, int code);
Patient * ht_remove(HTable ht, int code);

#endif // HASHTABLE_H_
