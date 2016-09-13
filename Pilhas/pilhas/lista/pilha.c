#include <stdio.h>
#include "pilha.h"

void status(pilha *p) {
  while(p != NULL) {
    printf("%d ",p->item); 
    p=p->prox;
  }
  printf(".\n");
  return;
}

int main(int argc, char **args) {
  
  pilha *p;
  p = NULL;
  obj_t o;
  
  empilhar(&p,5); status(p);
  empilhar(&p,3); status(p);
  empilhar(&p,2); status(p);
  o = desempilhar(&p); printf("%d --> ",o); status(p); 
  empilhar(&p,4); status(p);
  o = desempilhar(&p); printf("%d --> ",o); status(p);
  o = desempilhar(&p); printf("%d --> ",o); status(p);
  empilhar(&p,8); status(p);
  while(p!=NULL) desempilhar(&p); status(p);
  return 0;
}