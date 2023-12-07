#include "linked_list.h"
#include "student.h"

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

int compare_student(Student s1, Student s2) {
  if (s1.id < s2.id) return -1;
  if (s1.id > s2.id) return 1;
  return 0;
}

int add_linked_list(LinkedList * l, Student s) {
  // List is full
  if (l->available == -1) return 0;

  int new = l->available;
  l->available = l->nodes[l->available].next;
  l->nodes[new].value = s;
  l->nodes[new].next = l->first;
  l->first = new;
  return 1;
}

int add_linked_list_ordered(LinkedList * l, Student s) {
  // List is full
  if (l->available == -1) return 0;

  // List is empty
  if (l->first == -1) {
    l->first = l->available;
    l->available = l->nodes[l->available].next;
    l->nodes[l->first].value = s;
    return 1;
  }

  // List is not empty
  int prev = -1;
  int index = l->first;

  while (index != -1 && compare_student(l->nodes[index].value, s) <= 0) {
    prev = index;
    index = l->nodes[index].next;
  }

  if (prev == -1) {
    int new = l->available;
    l->available = l->nodes[l->available].next;
    l->nodes[new].value = s;
    l->nodes[new].next = l->first;
    l->first = new;
    return 1;
  }

  int new = l->available;
  l->available = l->nodes[l->available].next;
  l->nodes[new].value = s;
  l->nodes[new].next = l->nodes[prev].next;
  l->nodes[prev].next = new;
  return 1;
}

int remove_linked_list_value(LinkedList * l, Student s) {
  // List is empty
  if (l->first == -1) return 0;

  // List is not empty
  int prev = -1;
  int index = l->first;

  while (index != -1 && compare_student(l->nodes[index].value, s) != 0) {
    prev = index;
    index = l->nodes[index].next;
  }

  // Value not found
  if (index == -1) return 0;

  // Value found
  if (prev == -1) {
    l->first = l->nodes[index].next;
  } else {
    l->nodes[prev].next = l->nodes[index].next;
  }

  l->nodes[index].next = l->available;
  l->available = index;
  return 1;
}

int remove_linked_list_position(LinkedList * l, int index) {
  // List is empty
  if (l->first == -1) return 0;

  // List is not empty
  int prev = -1;
  int current = l->first;
  int i = 0;

  while (current != -1 && i < index) {
    prev = current;
    current = l->nodes[current].next;
    i++;
  }

  // Value not found
  if (current == -1) return 0;

  // Value found
  if (prev == -1) {
    l->first = l->nodes[current].next;
  } else {
    l->nodes[prev].next = l->nodes[current].next;
  }

  l->nodes[current].next = l->available;
  l->available = current;
  return 1;
}

int len_linked_list(LinkedList * l) {
  int len = 0;
  int index = l->first;

  while (index != -1) {
    len++;
    index = l->nodes[index].next;
  }

  return len;
}

int search_linked_list(LinkedList * l, int id) {
  int index = l->first;

  while (index != -1 && l->nodes[index].value.id != id) {
    index = l->nodes[index].next;
  }

  return index;
}

void print_linked_list(LinkedList * l) {
  int index = l->first;

  while (index != -1) {
    printf("\n");
    print_student(l->nodes[index].value);
    index = l->nodes[index].next;
  }
}