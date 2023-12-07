#ifndef STUDENT_H_
#define STUDENT_H_

#define NAME_SIZE 40

typedef struct {
  int id;
  char name[NAME_SIZE];
  int age;
  int children;
} Student;

/* Student operations */

// Create new student
Student new_student(int id, char * name, int age, int children);

// Print student values
void print_student(Student s);

#endif /* STUDENT_H_ */