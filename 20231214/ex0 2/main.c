#include "src/Polynomial.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  Polynomial * p1 = create_polynomial();

  push_term(p1, 4, 2);
  push_term(p1, -5, 0);
  push_term(p1, -10, 1);

  printf("first polynomial (p1):\n");
  print_polynomial(p1);

  Polynomial * p2 = create_polynomial();

  push_term(p2, 6, 1);
  push_term(p2, 12, 0);

  printf("second polynomial (p2):\n");
  print_polynomial(p2);

  Polynomial * p3 = add_polynomials(p1, p2);

  printf("\n");
  printf("sum of p1 and p2:\n");
  print_polynomial(p3);


  // free the memory
  destroy_polynomial(p1);
  destroy_polynomial(p2);
  destroy_polynomial(p3);

  return 0;
}