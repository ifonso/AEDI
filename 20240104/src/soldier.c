#include "soldier.h"

#include <string.h>
#include <stdio.h>

char * rank_to_string(Rank rank) {
  switch (rank) {
    case CABO:
      return "Cabo";
    case SARGENTO:
      return "Sargento";
    case TENENTE:
      return "Tenente";
    case CAPITAO:
      return "Capitao";
    case MAJOR:
      return "Major";
    case TENENTE_CORONEL:
      return "Tenente Coronel";
    case CORONEL:
      return "Coronel";
    case GENERAL:
      return "General";
  }
}

void soldier_create(Soldier * s, int code, char * name, Rank rank) {
  s->code = code;
  s->rank = rank;
  strcpy(s->name, name);
}

void soldier_print(Soldier * s) {
  printf("Soldier %d: %s (%s)\n", s->code, s->name, rank_to_string(s->rank));
}