#ifndef STUDENT_H_
#define STUDENT_H_

typedef struct {
  int code;
  char name[20];
  int age;
  float coefficient;
} Student;

Student * create_student(int code, char * name, int age, float coefficient);
void destroy_student(Student * student);

#endif /* STUDENT_H_ */