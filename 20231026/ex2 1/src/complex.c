#include "complex.h"

#include <stdlib.h>

Complex * create_complex(double r, double i) {
  Complex * c = malloc(sizeof(Complex));
  c->x = r;
  c->y = i;
  return c;
}

void destroy_complex(Complex * c) {
  free(c);
}

Complex * add_complex(Complex * c1, Complex * c2) {
  return create_complex(c1->x + c2->x, c1->y + c2->y);
}

Complex * sub_complex(Complex * c1, Complex * c2) {
  return create_complex(c1->x - c2->x, c1->y - c2->y);
}

// (x1 + y1i)(x2 + y2i) = x1x2 - y1y2 + (x1y2 + y1x2)i

Complex * mul_complex(Complex * c1, Complex * c2) {
  return create_complex(c1->x * c2->x - c1->y * c2->y,
                        c1->x * c2->y + c1->y * c2->x);
}

// (x1 + y1i)/(x2 + y2i) = (x1x2 + y1y2)/(x2^2 + y2^2) + (y1x2 - x1y2)/(x2^2 + y2^2)i

Complex * div_complex(Complex * c1, Complex * c2) {
  double denom = c2->x * c2->x + c2->y * c2->y;
  return create_complex((c1->x * c2->x + c1->y * c2->y) / denom,
                        (c1->y * c2->x - c1->x * c2->y) / denom);
}