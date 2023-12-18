#include "Polynomial.h"

#include <stdio.h>
#include <stdlib.h>

Polynomial * create_polynomial() {
  Polynomial * polynomial = malloc(sizeof(Polynomial));
  polynomial->head = NULL;
  polynomial->size = 0;
  return polynomial;
}

void destroy_polynomial(Polynomial * polynomial) {
  Term * current = polynomial->head;

  while (current != NULL) {
    Term * next = current->next;
    free(current);
    current = next;
  }

  free(polynomial);
}

void push_term(Polynomial * polynomial, int coefficient, int exponent) {
  Term * term = malloc(sizeof(Term));

  term->coefficient = coefficient;
  term->exponent = exponent;

  if (polynomial->head == NULL || polynomial->head->exponent < exponent) {
    term->next = polynomial->head;
    polynomial->head = term;
  } else {
    Term * current = polynomial->head;
    
    while (current->next != NULL && current->next->exponent > exponent) {
      current = current->next;
    }

    term->next = current->next;
    current->next = term;
  }

  polynomial->size++;
}

void remove_term(Polynomial * polynomial, int exponent) {
  Term * current = polynomial->head;
  Term * prev = NULL;

  while (current != NULL) {
    if (current->exponent == exponent) {
      if (prev != NULL) {
        prev->next = current->next;
      } else {
        polynomial->head = current->next;
      }

      free(current);
      polynomial->size--;
      return;
    }

    prev = current;
    current = current->next;
  }
}

void print_polynomial(Polynomial * polynomial) {
  Term * current = polynomial->head;

  while (current != NULL) {
    if (current->coefficient < 0) {
      printf("- ");
      printf("%d", abs(current->coefficient));
    } else {
      printf("%d", current->coefficient);
    }

    printf("%s", current->exponent == 0 ? "" : "x");
    printf("%s", current->exponent == 0 || current->exponent == 1 ? "" : "^");

    if (current->exponent > 1) {
      printf("%d", current->exponent);
    }

    if (current->next != NULL && current->next->coefficient >= 0) {
      printf(" + ");
    } else if (current->next != NULL) {
      printf(" ");
    }

    current = current->next;
  }

  printf("\n");
}

Polynomial * add_polynomials(Polynomial * p1, Polynomial * p2) {
  Polynomial * result = create_polynomial();

  Term * current1 = p1->head;
  Term * current2 = p2->head;

  while (current1 != NULL && current2 != NULL) {
    if (current1->exponent > current2->exponent) {
      push_term(result, current1->coefficient, current1->exponent);
      current1 = current1->next;
    } else if (current1->exponent < current2->exponent) {
      push_term(result, current2->coefficient, current2->exponent);
      current2 = current2->next;
    } else {
      push_term(result, current1->coefficient + current2->coefficient, current1->exponent);
      current1 = current1->next;
      current2 = current2->next;
    }
  }

  while (current1 != NULL) {
    push_term(result, current1->coefficient, current1->exponent);
    current1 = current1->next;
  }

  while (current2 != NULL) {
    push_term(result, current2->coefficient, current2->exponent);
    current2 = current2->next;
  }

  return result;
}