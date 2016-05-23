/*
 * Racional.cpp
 * Implementa uma classe representando um número racional
 */

/**
 * @author Hamilton J. Brumatto
 */

#include <stdlib.h>
#include "racional.hpp"

Racional::Racional() {
  num = 0; den = 1;
}

Racional::Racional(int num, int den) {
  this->num = num; this->den = den;
}

void Racional::reduz() {
  int max, min, res;
  
  max = abs(num) > abs(den) ? abs(num) : abs(den);
  min = abs(num) < abs(den) ? abs(num) : abs(den);
  do {
    res = max % min;
    if(res > 0) {
      max = min;
      min = res;
    }
  } while(res > 0);
  num /= min;
  den /= min;
  if(den < 0) {
    num = -num;
    den = -den;
  }
  return;
}  

int Racional::getNum() {return num;}

int Racional::getDen() {return den;}

Racional Racional::operator=(Racional rop) {
  num = rop.num;
  den = rop.den;
  reduz();
  return *this;
}

Racional Racional::operator+() {
  return *this;
}

Racional Racional::operator-() {
  Racional neg(-num,den);
  return neg;
}

Racional Racional::operator+(Racional sop) {
  Racional sum;
  sum.den = den*sop.den;
  sum.num = num*sop.den + den*sop.num;
  sum.reduz();
  return sum;
}
  
Racional Racional::operator-(Racional sop) {
  Racional dif;
  dif.den = den*sop.den;
  dif.num = num*sop.den - den*sop.num;
  dif.reduz();
  return dif;
}

Racional Racional::operator*(Racional sop) {
  Racional mul;
  mul.den = den*sop.den;
  mul.num = num*sop.num;
  mul.reduz();
  return mul;
}

Racional Racional::operator/(Racional sop) {
  Racional div;
  div.den = den*sop.num;
  div.num = num*sop.den;
  div.reduz();
  return div;
}

bool Racional::operator>(Racional sop) {
  return (num*sop.den > den*sop.num);
}

bool Racional::operator>=(Racional sop) {
  return (num*sop.den >= den*sop.num);
}

bool Racional::operator<(Racional sop) {
  return (num*sop.den < den*sop.num);
}

bool Racional::operator<=(Racional sop) {
  return (num*sop.den <= den*sop.num);
}

bool Racional::operator==(Racional sop) {
  return (num*sop.den == den*sop.num);
}

bool Racional::operator!=(Racional sop) {
  return (num*sop.den != den*sop.num);
}


