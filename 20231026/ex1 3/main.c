#include "src/complex.h"
#include <stdio.h>

void print_complex(Complex * c) {
  printf("%.2f + %.2fi\n", c->x, c->y);
}

int main() {
  Complex * c1 = create_complex(2, 1);
  Complex * c2 = create_complex(2, 2);

  printf("c1 = "); print_complex(c1);
  printf("c2 = "); print_complex(c2);

  printf("\n");

  printf("c1 + c2 = "); print_complex(add_complex(c1, c2));
  printf("c1 - c2 = "); print_complex(sub_complex(c1, c2));
  printf("c1 * c2 = "); print_complex(mul_complex(c1, c2));
  printf("c1 / c2 = "); print_complex(div_complex(c1, c2));

  // free memory
  destroy_complex(c1);
  destroy_complex(c2);

  return 0;
}