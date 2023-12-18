#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList * create_linked_list() {
  LinkedList * list = malloc(sizeof(LinkedList));
  list->head = NULL;
  list->size = 0;
  return list;
}

void destroy_linked_list(LinkedList * list) {
  Node * current = list->head;

  while (current != NULL) {
    Node * next = current->next;
    free(current);
    current = next;
  }

  free(list);
}

void push(LinkedList * list, int data) {
  Node * node = malloc(sizeof(Node));

  node->data = data;
  node->next = list->head;
  node->prev = NULL;

  if (list->head != NULL) {
    list->head->prev = node;
  }

  list->head = node;
  list->size++;
}

void remove_data(LinkedList * list, int data) {
  Node * current = list->head;

  while (current != NULL) {
    if (current->data == data) {
      if (current->prev != NULL) {
        current->prev->next = current->next;
      } else {
        list->head = current->next;
      }

      if (current->next != NULL) {
        current->next->prev = current->prev;
      }

      free(current);
      list->size--;
      return;
    }

    current = current->next;
  }
}

void print_linked_list(LinkedList * list) {
  Node * current = list->head;

  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("\n");
}



LinkedList * create_ordered_linked_list(LinkedList * list) {
  LinkedList * ordered_list = create_linked_list();  

  while (list->size > 0) {

    Node * current = list->head;
    Node * max = current;

    while (current != NULL) {
      if (current->data > max->data) {
        max = current;
      }
      current = current->next;
    }
    
    remove_node_from_list(list, max);
    push_node_to_list(ordered_list, max);
  }

  return ordered_list;
}

// Helper functions

void push_node_to_list(LinkedList * list, Node * node) {
  node->next = list->head;
  node->prev = NULL;

  if (list->head != NULL) {
    list->head->prev = node;
  }

  list->head = node;
  list->size++;
}

void remove_node_from_list(LinkedList * list, Node * node) {
  if (node->prev != NULL) {
    node->prev->next = node->next;
  } else {
    list->head = node->next;
  }

  if (node->next != NULL) {
    node->next->prev = node->prev;
  }

  list->size--;
}