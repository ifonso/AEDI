#ifndef H_TABLE_H_
#define H_TABLE_H_

#define CAPACITY 100

typedef struct Node Node;

struct Node {
  int data;
  void * next;
};

typedef struct {
  Node ** table;
  int capacity;
} H_TABLE;

void ht_init(H_TABLE * t, int c);
void ht_print(H_TABLE * t);

int ht_insert(H_TABLE * t, int v);

#endif // H_TABLE_H_
