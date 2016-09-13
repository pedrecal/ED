#include <stdio.h>
#include "fila.h"

void status(fila f) {
  int i=0; 
  printf("%d : ",f.inicio);
  i=f.inicio-1;
  if(!ehvazia(f)) {
    do {
      printf("%d ",f.itens[i]);
      i++;
      if(i==TAMANHOFILA) i=0;
    } while(i!=f.fim-1);
  }
  printf(": %d\n",f.fim);
  return;
}

int main(int argc, char **args) {
  
  fila f;
  f.inicio = f.fim = 1;
  f.cheia=falso;
  f.vazia=verdade;
  obj_t o;
  
  enfileirar(&f,5); status(f);
  enfileirar(&f,3); status(f);
  enfileirar(&f,2); status(f);
  o = desenfileirar(&f); printf("%d --> ",o); status(f); 
  enfileirar(&f,4); status(f);
  o = desenfileirar(&f); printf("%d --> ",o); status(f);
  o = desenfileirar(&f); printf("%d --> ",o); status(f);
  enfileirar(&f,8); status(f);
  while(!ehvazia(f)) desenfileirar(&f); status(f);
  return 0;
}