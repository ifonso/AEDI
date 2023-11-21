#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct {
    float x;
    float y;
    float z;
} Vector;

Vector * create_vector(float x, float y, float z);
void destroy_vector(Vector * v);

Vector * sum_vector(Vector * v1, Vector * v2);
float dot_product(Vector * v1, Vector * v2);

#endif // VECTOR_H_