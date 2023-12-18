#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList * create_list() {
  LinkedList * l = malloc(sizeof(LinkedList));
  l->first = NULL;
  return l;
}

LinkedList * create_translated_list(LinkedList * l, int offset) {
  LinkedList * new_list = create_list();

  Node * current = l->first;
  Node * prev = NULL;
  int count = 0;

  while (current != NULL && count < offset) {
    prev = current;
    current = current->next;
    count++;
  }

  if (prev != NULL) {
    prev->next = NULL;
  }

  Node * first_part = l->first;
  l->first = current;

  while (current != NULL && current->next != NULL) {
    current = current->next;
  }

  if (current != NULL) {
    current->next = first_part;
  }

  new_list->first = l->first;

  return new_list;
}

LinkedList* create_reversed_list(LinkedList* l) {
  LinkedList* new_list = create_list();
  Node* current = l->first;

  while (current != NULL) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = current->value;
    new_node->next = new_list->first;
    new_list->first = new_node;
    current = current->next;
  }

  return new_list;
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

void print_list(LinkedList * l) {
  Node * current = l->first;

  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }

  printf("\n");
}

void insert(LinkedList * l, int value) {
  Node * new_node = malloc(sizeof(Node));
  
  new_node->value = value;
  new_node->next = NULL;

  if (l->first == NULL) {
    l->first = new_node;
  } else {
    Node * current = l->first;

    while (current->next != NULL) {
      current = current->next;
    }

    current->next = new_node;
  }
}

void remove_by_value(LinkedList * l, int value) {
  Node * current = l->first;
  Node * previous = NULL;

  while (current != NULL) {
    if (current->value == value) {
      if (previous == NULL) {
        l->first = current->next;
      } else {
        previous->next = current->next;
      }

      free(current);
      return;
    }

    previous = current;
    current = current->next;
  }
}