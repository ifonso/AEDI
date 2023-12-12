#ifndef STUDENT_H_
#define STUDENT_H_

#define NAME_SIZE 20

typedef struct {
  int code;
  char name[NAME_SIZE];
  int age;
  int children;
} Student;

// Create new student
Student new_student(int code, char * name, int age, int children);

#endif /* STUDENT_H_ */