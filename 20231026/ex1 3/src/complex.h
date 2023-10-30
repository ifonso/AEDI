#ifndef COMPLEX_H_
#define COMPLEX_H_

typedef struct {
  double x; // real
  double y; // imaginary
} Complex;

// Creation
Complex * create_complex(double r, double i);
void destroy_complex(Complex * c);
// Operations
Complex * add_complex(Complex * c1, Complex * c2);
Complex * sub_complex(Complex * c1, Complex * c2);
Complex * mul_complex(Complex * c1, Complex * c2);
Complex * div_complex(Complex * c1, Complex * c2);

#endif // COMPLEX_H_