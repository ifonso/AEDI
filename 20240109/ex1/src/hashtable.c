#include "hashtable.h"
#include "patient.h"

#include <stdlib.h>
#include <string.h>

int hash(int code) {
  return code % MAX_CAPACITY;
}

void ht_init(HASH_TABLE ht) {
  memset(ht, 0, sizeof(Patient *) * MAX_CAPACITY);
}

int ht_insert(HASH_TABLE ht, Patient p) {
  int i = hash(p.code);
  while(ht[i] != NULL) {
    if (ht[i]->code == p.code) return 0;

    if (i+1 < MAX_CAPACITY) {
      i = (i+1) % MAX_CAPACITY;
    } else {
      return 0;
    }
  }

  ht[i] = malloc(sizeof(Patient));
  *(ht[i]) = p;

  return 1;
}

Patient * ht_search(HASH_TABLE ht, int code) {
  int i = hash(code);
  while(ht[i] != NULL) {
    if (ht[i]->code == code) return ht[i];

    if (i+1 < MAX_CAPACITY) {
      i = (i+1) % MAX_CAPACITY;
    } else {
      break;
    }
  }
  return NULL;
}