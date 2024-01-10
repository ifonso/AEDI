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

  ht_insert(ht, p1);
  ht_insert(ht, p2);
  ht_insert(ht, p3);

  // Find Julia

  Patient * p = ht_search(ht, 2871);

  printf("Paciente %s encontrada na tabela.\n", p->name);

  return 0;
}
