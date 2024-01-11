#include "hashtable.h"
#include "patient.h"

#include <stdio.h>
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
    if (ht[i]->available) break;
    if (ht[i]->p->code == p.code) return 0;

    if (i+1 < MAX_CAPACITY) {
      i = (i+1) % MAX_CAPACITY;
    } else {
      return 0;
    }
  }

  Ps * ps = malloc(sizeof(Ps));
  ps->available = false;
  ps->p = malloc(sizeof(Patient));
  *(ps->p) = p;
  ht[i] = ps;

  return 1;
}

Patient * ht_search(HASH_TABLE ht, int code) {
  int i = hash(code);
  while(ht[i] != NULL) {
    if (!ht[i]->available) {
      if (ht[i]->p->code == code) return ht[i]->p;
    }
    
    if (i+1 < MAX_CAPACITY) {
      i = (i+1) % MAX_CAPACITY;
    } else {
      break;
    }
  }
  return NULL;
}

Patient * ht_remove(HASH_TABLE ht, int code) {
  Patient * p = NULL;
  int i = hash(code);
  while(ht[i] != NULL) {
    if (!ht[i]->available) {
      if (ht[i]->p->code == code) {
        p = ht[i]->p;
        ht[i]->available = true;
        ht[i]->p = NULL;
        break;
      }
    }
    
    if (i+1 < MAX_CAPACITY) {
      i = (i+1) % MAX_CAPACITY;
    } else {
      break;
    }
  }
  return p;
}

void ht_print(HASH_TABLE ht) {
 for (int i = 0; i < MAX_CAPACITY; i++) {
    if (ht[i] == NULL || ht[i]->available) continue;
    printf("TABLE[%d] -> %s\n", i, ht[i]->p->name);
  }
}
