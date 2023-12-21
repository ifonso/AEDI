#include "src/stack.h"
#include "src/plane.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  Stack * hangar = create_stack();

  push(hangar, create_plane("Boeing 747"));
  push(hangar, create_plane("Airbus A380"));
  push(hangar, create_plane("Boeing 777"));
  push(hangar, create_plane("Airbus A350"));

  // a) Listar o número de aviões aguardando no hangar
  printf("Número de aviões aguardando no hangar: %d\n", hangar->size);

  // b) Tirar um  avião do hangar
  pop(hangar);

  // c) Adicionar um avião no hangar
  push(hangar, create_plane("Boeing 737"));

  // d) Listar todos os aviões que estão no hangar
  print_planes(hangar);

  // e) Listar as características do primeiro avião do hangar
  print_first_plane(hangar);

  // f) Tirar um avião do hangar pela posição
  pop_by_position(hangar, 2);

  // free memory
  destroy_stack(hangar);

  return 0;
}