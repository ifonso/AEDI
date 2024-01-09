#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "deque.h"
#include "soldier.h"

int main() {
  Soldier s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;

  // Iniciando os soldados
  soldier_create(&s1, 1, "Caique", CABO);
  soldier_create(&s2, 2, "Carlos", SARGENTO);
  soldier_create(&s3, 3, "Adriano", TENENTE);
  soldier_create(&s4, 4, "Jorge", CAPITAO);
  soldier_create(&s5, 5, "Michael", MAJOR);
  soldier_create(&s6, 6, "Anderson", TENENTE_CORONEL);
  soldier_create(&s7, 7, "Tz", CORONEL);
  soldier_create(&s8, 8, "Angelo", CABO);
  soldier_create(&s9, 9, "Miguel", CABO);
  soldier_create(&s10, 10, "Ricardo", GENERAL);

  // Criando deque
  Deque q;
  deque_init(&q);

  // Inserindo soldados no deque
  deque_insert_start(&q, &s1);
  deque_insert_start(&q, &s2);
  deque_insert_start(&q, &s3);
  deque_insert_start(&q, &s4);
  deque_insert_start(&q, &s5);

  deque_insert_end(&q, &s6);
  deque_insert_end(&q, &s7);
  deque_insert_end(&q, &s8);
  deque_insert_end(&q, &s9);
  deque_insert_end(&q, &s10);

  // Removendo soldados do deque

  Soldier * s1_removed = deque_remove_start(&q);
  printf("Soldado removido do inicio: %s\n", s1_removed->name);

  Soldier * s2_removed = deque_remove_end(&q);
  printf("Soldado removido do fim: %s\n", s2_removed->name);

  printf("Primeiro soldado no deque: %s\n", first(&q)->name);

  printf("Ultimo soldado no deque: %s\n", last(&q)->name);

  if (deque_is_empty(&q)) {
    printf("Deque vazio\n");
  } else {
    printf("Tamanho do deque: %d\n", deque_size(&q));
  }

  // Adicionando soldadoes removidos
  deque_insert_start(&q, s1_removed);
  deque_insert_end(&q, s2_removed);

  // ------------------- Problema de Josephus -------------------  
  printf("\n");
  // Sorteando um número
  srand(time(NULL));
  int n = rand() % 100;
  Soldier * remaning = josephus(&q, n);

  printf("\nO último soldado é o %s\n", remaning->name);

  return 0;
}
