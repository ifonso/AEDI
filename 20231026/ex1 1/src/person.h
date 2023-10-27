#ifndef PERSON_H_
#define PERSON_H_

#include "date.h"

typedef struct {
    char name[255];
    Date birth_date;
    char cpf[14];    // 123.456.789-00
} Person;

int set_person_data(Person * p, char * name, Date d, char * cpf);
void print_person_data(Person * p);

#endif