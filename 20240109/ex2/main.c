#include "src/hashtable.h"
#include "src/patient.h"

#include <stdio.h>

int main() {
  HTable ht;
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
    .code = 1291,
    .name = "Jeniffer",
    .age = 23,
    .cpf = "12378945610"
  };

  Patient p4 = {
    .code = 1089,
    .name = "Bruno",
    .age = 23,
    .cpf = "00120145610"
  };

  ht_insert(ht, p1);
  ht_insert(ht, p2);
  ht_insert(ht, p3);
  ht_insert(ht, p4);

  // Find Jennifer
  Patient * p = ht_search(ht, 1291);
  printf("Paciente %s encontrada na tabela.\n", p->name);

  // Find Bruno
  p = ht_search(ht, 1089);
  printf("Paciente %s encontrada na tabela.\n", p->name);

  return 0;
}
