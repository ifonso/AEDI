#ifndef LLIST_H_
#define LLIST_H_

#define MAX 100

// Entitie
typedef struct {
  int id;
  char name[20];
  int age;
} Student;

// Node
typedef struct {
  Student student;
  int next;
} LNode;

// List
typedef struct {
  LNode nodes[MAX];
  int first;
  int available;
} LList;

/*
 * Student methods
**/

Student create_student(int id, char * name, int age);
void print_student(Student student);

/*
 * List methods
**/

LList * create_list();
void destroy_list(LList * list);

void insert_student_ordered(LList * list, int id, char * name, int age);
void remove_student(LList * list, int id);
void change_student_id(LList * list, int id, int new_id);

void print_list(LList * list);

int length(LList * list);
int is_full(LList * list);
int is_empty(LList * list);

#endif /* LLIST_H_ */