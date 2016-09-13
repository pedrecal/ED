#include <stdio.h>
#include "fila.h"

void status(fila *f) {
  while(f != NULL) {
    printf("%d ",f->item); 
    f=f->prox;
  }
  printf(".\n");
  return;
}

int main(int argc, char **args) {
  
  fila *inicio, *fim;
  inicio = fim = NULL;
  obj_t o;
  
  enfileirar(&inicio,&fim,5); status(inicio);
  enfileirar(&inicio,&fim,3); status(inicio);
  enfileirar(&inicio,&fim,2); status(inicio);
  o = desenfileirar(&inicio,&fim); printf("%d --> ",o); status(inicio); 
  enfileirar(&inicio,&fim,4); status(inicio);
  o = desenfileirar(&inicio,&fim); printf("%d --> ",o); status(inicio);
  o = desenfileirar(&inicio,&fim); printf("%d --> ",o); status(inicio);
  enfileirar(&inicio,&fim,8); status(inicio);
  while(inicio!=NULL) desenfileirar(&inicio,&fim); status(inicio);
  return 0;
}