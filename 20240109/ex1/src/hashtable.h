#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#define MAX_CAPACITY 100

#include "patient.h"

typedef Patient * HASH_TABLE[MAX_CAPACITY];

void ht_init(HASH_TABLE ht);
int ht_insert(HASH_TABLE ht, Patient p);
Patient * ht_search(HASH_TABLE ht, int code);

#endif // HASHTABLE_H_
