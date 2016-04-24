#include <stdio.h>
#include <stdlib.h>

typedef struct st_complexo 
{
  double real;
  double imag;
  struct st_complexo *prox;
} complexo;

int main(int argc, char **args) {
  complexo *lista, *p;
  
  lista = malloc(sizeof(complexo));
  p = lista;
  p->real = 2;  p->imag = 3;
  p->prox = malloc(sizeof(complexo));
  
  p = p->prox;
  p->real = 3; p->imag = 4;
  p->prox = malloc(sizeof(complexo));
  
  p = p->prox;
  p->real = 4; p->imag = 5; p->prox = NULL;
  
  p = lista;
  while(p != NULL) {
    printf("(%f + i%f)..",p->real,p->imag); p=p->prox;
  }
  printf("\n");
    
  p = lista;  
  printf("(%f + i%f)\n",p->prox->real, p->prox->prox->imag);
  return 0;
}