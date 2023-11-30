#ifndef STUDENT_H_
#define STUDENT_H_

typedef struct {
  int id;
  char name[20];
} Student;

Student * create_student(int id, char * name);
void destroy_student(Student * student);

void print_student(Student * student);
void change_student_id(Student * student, int new_id);

#endif /* STUDENT_H_ */