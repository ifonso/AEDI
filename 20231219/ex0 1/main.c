#include "src/queue.h"
#include "src/plane.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  Queue * runway = create_queue();

  Plane * p1 = create_plane("Gol");
  Plane * p2 = create_plane("Boeing");
  Plane * p3 = create_plane("Airbus");

  enqueue(runway, p1);
  enqueue(runway, p2);
  enqueue(runway, p3);

  // a) Listar o número de aviões aguardando na fila de decolagem
  printf("Número de aviões aguardando na fila de decolagem: %d\n", queue_size(runway));

  // b) Autorizar a decolagem do primeiro avião da fila;
  dequeue(runway);

  // c) Adicionar um avião à fila de espera;
  Plane * p4 = create_plane("AH-2 SABRE");
  enqueue(runway, p4);

  // d) Listar todos os aviões na fila de espera;
  printf("Aviões na fila de espera:\n");
  print_planes(runway);

  // e) Listar as características do primeiro avião da fila.
  printf("Primeiro avião da fila:\n");
  print_first_plane(runway);

  // free the memory
  destroy_queue(runway);

  return 0;
}