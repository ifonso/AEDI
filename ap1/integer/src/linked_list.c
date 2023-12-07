#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList * new_linked_list() {
  LinkedList * l = (LinkedList *) malloc(sizeof(LinkedList));
  l->first = -1;
  l->available = 0;
  l->nodes[MAX-1].next = -1;
  
  for (int i = 0; i < MAX-1; i++) {
    l->nodes[i].next = i+1;
  }
  return l;
}

void destroy_linked_list(LinkedList * l) {
  free(l);
}

int add_linked_list(LinkedList * l, int i) {
  // List is full
  if (l->available == -1) return -1;

  // List is empty
  if (l->first == -1) {
    l->first = l->available;
    l->available = l->nodes[l->available].next;
    l->nodes[l->first].value = i;
    return 0;
  }

  // List is not empty
  int available = l->available;
  l->available = l->nodes[available].next;
  l->nodes[available].value = i;
  l->nodes[available].next = l->first;
  l->first = available;
  return 0;
}

int add_linked_list_ordered(LinkedList * l, int i) {
  // List is full
  if (l->available == -1) return -1;

  // List is empty
  if (l->first == -1) {
    l->first = l->available;
    l->available = l->nodes[l->available].next;
    l->nodes[l->first].value = i;
    return 0;
  }

  // List is not empty
  int prev = -1;
  int index = l->first;

  while (index != -1 && l->nodes[index].value <= i) {
    prev = index;
    index = l->nodes[index].next;
  }

  int available = l->available;
  l->available = l->nodes[available].next;
  l->nodes[available].value = i;

  // First element is small than new
  if (prev == -1) {
    l->nodes[available].next = l->first;
    l->first = available;
  } else {
    l->nodes[available].next = index;
    l->nodes[prev].next = available;
  }
  return 0;
}

void print_linked_list(LinkedList * l) {
  int index = l->first;
  while (index != -1) {
    printf("%d -> ", l->nodes[index].value);
    index = l->nodes[index].next;
  }
  printf("\n");
}

int remove_linked_list_value(LinkedList * l, int i) {
  // List is empty
  if (l->first == -1) return -1;

  // List is not empty
  int prev = -1;
  int index = l->first;

  while (index != -1 && l->nodes[index].value != i) {
    prev = index;
    index = l->nodes[index].next;
  }

  // Element not found
  if (index == -1) return -1;

  // Element found
  if (prev == -1) {
    l->first = l->nodes[index].next;
  } else {
    l->nodes[prev].next = l->nodes[index].next;
  }

  l->nodes[index].next = l->available;
  l->available = index;
  return 0;
}

int remove_linked_list_position(LinkedList * l, int index) {
  // List is empty
  if (l->first == -1) return -1;

  // List is not empty
  int prev = -1;
  int current = l->first;
  int i = 0;

  while (current != -1 && i < index) {
    prev = current;
    current = l->nodes[current].next;
    i++;
  }

  // Element not found
  if (current == -1) return -1;

  // Element found
  if (prev == -1) {
    l->first = l->nodes[current].next;
  } else {
    l->nodes[prev].next = l->nodes[current].next;
  }

  l->nodes[current].next = l->available;
  l->available = current;
  return 0;
}

int len_linked_list(LinkedList * l) {
  int index = l->first;
  int len = 0;
  while (index != -1) {
    len++;
    index = l->nodes[index].next;
  }
  return len;
}

int search_linked_list(LinkedList * l, int e) {
  int index = l->first;
  while (index != -1 && l->nodes[index].value != e) {
    index = l->nodes[index].next;
  }
  return index;
}