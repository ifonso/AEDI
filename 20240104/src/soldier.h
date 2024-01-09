#ifndef SOLDIER_H_
#define SOLDIER_H_

#define MAX_NAME_LENGTH 256

typedef enum {
  CABO,
  SARGENTO,
  TENENTE,
  CAPITAO,
  MAJOR,
  TENENTE_CORONEL,
  CORONEL,
  GENERAL
} Rank;

typedef struct {
  int code;
  char name[MAX_NAME_LENGTH];
  Rank rank;
} Soldier;

void soldier_create(Soldier * s, int code, char * name, Rank rank);
void soldier_print(Soldier * s);

#endif // SOLDIER_H_
