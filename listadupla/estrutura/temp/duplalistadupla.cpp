#include <iostream>
#include <cstdlib>
#include "../listaDE.hpp"
#include "../../numeros/complexo.hpp"
#include "../../numeros/racional.hpp"

using namespace std;

int main(int argc, char **args) {
  ListaDE<Complexo> *head, *tail, *p, *l;
  ListaDE<Racional> *hd, *tl, *pr;
  Complexo a(2,3), b(3,4), c(4,5);
  Racional r1(7,5), r2(6,4), r3(4,2);

  p = new ListaDE<Complexo>(a);
  head = p;
  tail = p;

  pr = new ListaDE<Racional>(r1);
  hd = pr;
  tl = pr;

  l = head;
  while(l!=NULL) {
    cout << l->getObj().getReal() << " + i" << l->getObj().getImag() << endl;
    l = l->getProx();
  } cout<< endl;

  p->inserirAntes(head,b,tail);
  pr->inserirAntes(hd,r2,tl);

  l = head;
  while(l!=NULL) {
    cout << l->getObj().getReal() << " + i" << l->getObj().getImag() << endl;
    l = l->getProx();
  } cout<< endl;

  p->inserirApos(head,c,tail);
  pr->inserirApos(hd,r3,tl);

  l = head;
  while(l!=NULL) {
    cout << l->getObj().getReal() << " + i" << l->getObj().getImag() << endl;
    l = l->getProx();
  } cout<< endl;

  pr = hd;
  while(pr!=NULL) {
    cout << pr->getObj().getNum() << "/" << pr->getObj().getDen() << endl;
    pr = pr->getProx();
  } cout<< endl;

  p = head;
  p = p->getProx();
  p->inserirAntes(head,c,tail);

  l = head;
  while(l!=NULL) {
    cout << l->getObj().getReal() << " + i" << l->getObj().getImag() << endl;
    l = l->getProx();
  } cout<< endl;

  p=p->getProx();
  p->inserirAntes(head,b,tail);

  l = head;
  while(l!=NULL) {
    cout << l->getObj().getReal() << " + i" << l->getObj().getImag() << endl;
    l = l->getProx();
  } cout<< endl;

  p->inserirApos(head,a,tail);

  l = head;
  while(l!=NULL) {
    cout << l->getObj().getReal() << " + i" << l->getObj().getImag() << endl;
    l = l->getProx();
  } cout << endl;

  p = head;
  p->remover(head,tail);


  l = head;
  while(l!=NULL) {
    cout << l->getObj().getReal() << " + i" << l->getObj().getImag() << endl;
    l = l->getProx();
  }


  return 0;
}
