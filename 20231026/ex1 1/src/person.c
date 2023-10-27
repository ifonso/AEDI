#include "person.h"
#include "date.h"

#include <string.h>
#include <stdio.h>

int set_person_data(Person * p, char * name, Date birth_date, char * cpf) {
    if (p == NULL) return 0;

    p->birth_date = birth_date;    
    strcpy(p->name, name);
    strcpy(p->cpf, cpf);
    
    return 1;
}

void print_person_data(Person * p) {
    if (p == NULL) return;

    printf("Name: %s\n", p->name);
    printf("Birth date: %02d/%02d/%04d\n", p->birth_date.day, p->birth_date.month, p->birth_date.year);
    printf("CPF: %s\n", p->cpf);
}