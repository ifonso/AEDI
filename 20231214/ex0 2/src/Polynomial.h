#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

typedef struct Polynomial Polynomial;

typedef struct Term Term;

struct Term {
  int coefficient;
  int exponent;
  struct Term * next;
};

struct Polynomial {
  struct Term * head;
  int size;
};

Polynomial * create_polynomial();
void destroy_polynomial(Polynomial * polynomial);

void push_term(Polynomial * polynomial, int coefficient, int exponent);
void remove_term(Polynomial * polynomial, int exponent);

void print_polynomial(Polynomial * polynomial);

// Operations

Polynomial * add_polynomials(Polynomial * p1, Polynomial * p2);

#endif // POLYNOMIAL_H_