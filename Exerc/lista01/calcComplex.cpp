#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct complex
{
  int real, img;

} complex_t;

void sum(complex_t fnum, complex_t snum, complex_t *sum)
{
  sum->real = fnum.real + snum.real;
  sum->img = fnum.img + snum.img;
}

void product(complex_t fnum, complex_t snum, complex_t *product)
{
  product->real = ((fnum.real * snum.real) - (fnum.img * snum.img));
  product->img = ((fnum.real * snum.img) + (fnum.img * snum.real));
}

void sqr(complex_t fnum, complex_t *sqr)
{
  *sqr = fnum * fnum;
}
