#include "./src/h_table.h"

#include <stdio.h>

int main() {
  H_TABLE table;
  ht_init(&table, 9);

  // Inserindo valores
  ht_insert(&table, 12);
  ht_insert(&table, 44);
  ht_insert(&table, 13);
  ht_insert(&table, 88);
  ht_insert(&table, 23);
  ht_insert(&table, 94);
  ht_insert(&table, 11);
  ht_insert(&table, 39);
  ht_insert(&table, 20);
  ht_insert(&table, 16);
  ht_insert(&table, 5);

  // Imprimindo primeira tabela
  printf("Primeira tabela: \n");
  ht_print(&table);

  // --------- Segunda tabela ----------

  H_TABLE table2;
  ht_init(&table2, 11);

  // Inserindo valores
  ht_insert(&table2, 12);
  ht_insert(&table2, 44);
  ht_insert(&table2, 13);
  ht_insert(&table2, 88);
  ht_insert(&table2, 23);
  ht_insert(&table2, 94);
  ht_insert(&table2, 11);
  ht_insert(&table2, 39);
  ht_insert(&table2, 20);
  ht_insert(&table2, 16);
  ht_insert(&table2, 5);

  // Imprimindo tabela
  printf("\nSegunda tabela: \n");
  ht_print(&table2);

  return 0;
}