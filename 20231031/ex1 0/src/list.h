#ifndef LIST_H_
#define LIST_H_

typedef struct {
  int * vector;
  int size;
} List;

List * create_list(int size);
void destroy_list(List * l);

void insert_random_elements(List * l);
void insert_ordered_elements(List * l);
void print_elements(List * l);
int get_sum(List * l);
int get_product(List * l);

int linear_search(List * l, int element);
int ordered_linear_search(List * l, int element);
int binary_search(List * l, int element);
int get_higher_element(List * l);
int get_lower_element(List * l);

#endif /* LIST_H_ */