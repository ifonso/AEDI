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

void print_elements_iterative(List * l);
void print_elements_recursive(List * l, int position);

int binary_search_recursive(List * l, int target, int low, int high);

int get_highest_element(List * v, int position, int current);
int get_lowest_element(List * v, int position, int current);

int get_sum_recursive(List * l, int position, int cumulator);
int get_product_recursive(List * l, int position, int cumulator);

#endif /* LIST_H_ */