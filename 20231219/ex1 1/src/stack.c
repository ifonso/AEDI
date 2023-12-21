#include "stack.h"
#include "plane.h"

#include <stdio.h>
#include <stdlib.h>

Stack * create_stack() {
  Stack * stack = malloc(sizeof(Stack));

  if (stack == NULL) {
    fprintf(stderr, "Error: could not allocate memory for stack.\n");
    exit(1);
  }

  stack->top = NULL;
  stack->size = 0;
  return stack;
}

void destroy_stack(Stack * s) {
  Node * current = s->top;
  Node * temp = NULL;

  while (current != NULL) {
    temp = current;
    current = current->next;
    destroy_plane(temp->value);
    free(temp);
  }

  free(s);
}

void push(Stack * s, Plane * plane) {
  Node * node = malloc(sizeof(Node));
  node->value = plane;
  node->next = s->top;
  s->top = node;
  s->size++;
}

Plane * pop(Stack * s) {
  if (s->size == 0) return NULL;

  Node * temp = s->top;
  Plane * plane = temp->value;
  s->top = temp->next;
  s->size--;
  free(temp);
  return plane;
}

Plane * pop_by_position(Stack * s, int position) {
  if (position > s->size) {
    fprintf(stderr, "Error: position %d is out of bounds.\n", position);
    exit(1);
  }

  Stack * temp_stack = create_stack();
  Node * target = NULL;
  Plane * plane = NULL;

  for (int i = 0; i < position; i++) {
    if (i == position - 1) {
      target = s->top;
      plane = target->value;
    } else {
      push(temp_stack, pop(s));
    }
  }

  pop(s);

  while (temp_stack->size > 0) {
    push(s, pop(temp_stack));
  }

  destroy_stack(temp_stack);

  return plane;
}

void print_planes(Stack * s) {
  Node * current = s->top;

  while (current != NULL) {
    print_plane(current->value);
    current = current->next;
  }
}

void print_first_plane(Stack * s) {
  if (s->size == 0) {
    fprintf(stderr, "Error: stack is empty.\n");
    exit(1);
  }

  print_plane(s->top->value);
}