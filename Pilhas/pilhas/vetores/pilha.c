#include <stdio.h>
#include "pilha.h"

void status(pilha p) {
  int i=0; 
  printf("%d : ",p.topo);
  for(i=0; i<p.topo; i++) printf("%d ",p.itens[i]); 
  printf("\n");
  return;
}

int main(int argc, char **args) {
  
  pilha p;
  p.topo = 0;
  obj_t o;
  
  empilhar(&p,5); status(p);
  empilhar(&p,3); status(p);
  empilhar(&p,2); status(p);
  o = desempilhar(&p); printf("%d --> ",o); status(p); 
  empilhar(&p,4); status(p);
  o = desempilhar(&p); printf("%d --> ",o); status(p);
  o = desempilhar(&p); printf("%d --> ",o); status(p);
  empilhar(&p,8); status(p);
  while(!ehvazia(p)) desempilhar(&p); status(p);
  return 0;
}