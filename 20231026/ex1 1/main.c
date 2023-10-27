#include <stdio.h>
#include "src/person.h"
#include "src/date.h"

int main() {
    Person p1, p2;

    // Person data
    Date d1 = {1, 1, 2000};
    Date d2 = {20, 7, 2001};
    
    set_person_data(&p1, "John", d1, "123.456.789-00");
    set_person_data(&p2, "Afonso", d2, "987.654.321-00");
    
    // Print person data
    print_person_data(&p1);
    printf("\n");
    print_person_data(&p2);

    return 0;
}