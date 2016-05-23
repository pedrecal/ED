/*
 * Complexo.cpp
 * Implementa uma classe representando um número complexo
 */

/**
 * @author Hamilton J. Brumatto
 */

#include "complexo.hpp"

Complexo::Complexo() {
  real=0; imag=0;
}

Complexo::Complexo(double real, double imag) {
  this->real = real; this->imag = imag;
}

double Complexo::getReal() { return real; }

double Complexo::getImag() { return imag; }

Complexo Complexo::operator=(Complexo rop) {
  real = rop.real;
  imag = rop.imag;
  return *this;
}

Complexo Complexo::operator+(Complexo sop) {
  Complexo sum;
  sum.real = real + sop.real;
  sum.imag = real + sop.imag;
  return sum;
}

Complexo Complexo::operator-(Complexo sop) {
  Complexo dif;
  dif.real = real - sop.real;
  dif.imag = real - sop.imag;
  return dif;
}

Complexo Complexo::operator*(Complexo sop) {
  Complexo mul;
  mul.real = real*sop.real - imag*sop.imag;
  mul.imag = real*sop.imag + imag*sop.real;
  return mul;
}

Complexo Complexo::operator/(Complexo sop) {
  Complexo comp(sop.real,-sop.imag), div;
  div = *this * comp;
  div.real/= (sop.real*sop.real + sop.imag*sop.imag);
  div.imag/= (sop.real*sop.real + sop.imag*sop.imag);
  return div;
}

double Complexo::modulo() {
  return real*real + imag*imag;
}