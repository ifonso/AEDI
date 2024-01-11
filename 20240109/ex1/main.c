#include "src/patient.h"
#include "src/hashtable.h"

#include <stdio.h>

int main() {
  HASH_TABLE ht;
  ht_init(ht);

  Patient p1 = {
    .code = 1329,
    .name = "Afonso",
    .age = 22,
    .cpf = "12345678910"
  };

  Patient p2 = {
    .code = 2871,
    .name = "Julia",
    .age = 22,
    .cpf = "98765432110"
  };

  Patient p3 = {
    .code = 1623,
    .name = "Jeniffer",
    .age = 23,
    .cpf = "12378945610"
  };

  int i;
  i = ht_insert(ht, p1);
  if (i) {
    printf("%s inserido na tabela.\n", p1.name);
  }

  i = ht_insert(ht, p2);
  if (i) {
    printf("%s inserido na tabela.\n", p2.name);
  }

  i = ht_insert(ht, p3);
  if (i) {
    printf("%s inserido na tabela.\n", p3.name);
  }
  // Find Julia

  Patient * p = ht_search(ht, 2871);
  printf("Paciente %s encontrada na tabela.\n\n", p->name);

  // Removing Julia
  ht_remove(ht, 2871);
  p = ht_search(ht, 2871);

  if (p == NULL) {
    printf("Paciente %s não encontrada na tabela.\n", p3.name);
  }

  return 0;
}
