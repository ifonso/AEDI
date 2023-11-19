#include <stdio.h>
#include <stdlib.h>

int k_digit_form_number(int n, int p) {
  if (p == 1) return n % 10;
  return k_digit_form_number(n / 10, p - 1);
}

int main() {
  int n = 133795720;
  int p = 5;

  printf("The %dº digit from %d is %d\n", p, n, k_digit_form_number(n, p));

  return 0;
}