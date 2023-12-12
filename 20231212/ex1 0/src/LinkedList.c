#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList * create_list() {
  LinkedList * l = (LinkedList *) malloc(sizeof(LinkedList));
  l->first = NULL;
  return l;
}

void destroy_list(LinkedList * l) {
  Node * current = l->first;
  while (current != NULL) {
    Node * next = current->next;
    free(current);
    current = next;
  }
  free(l);
}

int length(LinkedList * l) {
  int count = 0;
  Node * current = l->first;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

int is_empty(LinkedList * l) {
  return l->first == NULL;
}

void print_list(LinkedList * l) {
  Node * current = l->first;
  while (current != NULL) {
    printf("\n");
    printf("ID: %d\n", current->value.id);
    printf("NAME: %s\n", current->value.name);
    printf("AGE: %d\n", current->value.age);

    current = current->next;
  }
}

void insert_ordered(LinkedList * l, int id, char * name, int age) {
  Node * new_node = (Node *) malloc(sizeof(Node));

  new_node->value.id = id;
  strcpy(new_node->value.name, name);
  new_node->value.age = age;
  new_node->next = NULL;

  // If list is empty
  if (is_empty(l)) {
    l->first = new_node;
    return;
  }

  Node * current = l->first;
  Node * previous = NULL;

  while (current != NULL && current->value.id < id) {
    previous = current;
    current = current->next;
  }

  if (previous == NULL) {
    new_node->next = l->first;
    l->first = new_node;
  } else {
    previous->next = new_node;
    new_node->next = current;
  }  
}

void remove_by_value(LinkedList * l, int id) {
  if (is_empty(l)) return;
  
  Node * current = l->first;
  Node * previous = NULL;
  
  while (current != NULL && current->value.id != id) {
    previous = current;
    current = current->next;
  }

  if (current != NULL) {
    if (previous == NULL) {
      l->first = current->next;
    } else {
      previous->next = current->next;
    }
    free(current);
  }
}