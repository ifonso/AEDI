#ifndef LIST_H_
#define LIST_H_

#include "student.h"

#define MAX 100

typedef struct {
  Student values[MAX];
  int length;
} List;

// List creation with a limit size of 100
List * new_list();
// Free memory allocated for list
void destroy_list(List * l);

// Add new item to list (not ordered)
int add_list(List * l, Student s);
// Average class age
float get_average_students_age(List * l);

// Print list values
void print_list(List * l);

#endif /* LIST_H_ */