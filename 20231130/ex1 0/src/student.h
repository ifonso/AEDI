#ifndef STUDENT_H_
#define STUDENT_H_

typedef struct {
  int id;
  char name[20];
  int age;
} Student;

Student * create_student(int id, char * name, int age);
void destroy_student(Student * student);
void print_student(Student * student);
void change_student_id(Student * student, int id);

#endif /* STUDENT_H_ */