#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#define MAX_CAPACITY 100

#include "patient.h"
#include <stdbool.h>

typedef struct Ps Ps;
typedef Ps * HASH_TABLE[MAX_CAPACITY];

struct Ps {
  Patient * p;
  bool available;
};

void ht_init(HASH_TABLE ht);
void ht_print(HASH_TABLE ht);
int ht_insert(HASH_TABLE ht, Patient p);
Patient * ht_search(HASH_TABLE ht, int code);
Patient * ht_remove(HASH_TABLE ht, int code);

#endif // HASHTABLE_H_
