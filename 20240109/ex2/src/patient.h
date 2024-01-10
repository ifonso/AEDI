#ifndef PATIENT_H_
#define PATIENT_H_

#define MAX_NAME_LENGTH 256
#define CPF_SIZE 12

typedef struct {
  int code;
  char name[MAX_NAME_LENGTH];
  char cpf[CPF_SIZE];
  unsigned int age;
} Patient;

#endif // PATIENT_H_
