#include <stdio.h>
#include <stdlib.h>

typedef struct st_complexo 
{
  double real;
  double imag;
  struct st_complexo *prox;
} complexo;

int main(int argc, char **args) {
  complexo *lista, *p, *a;

//Criando uma lista  
  lista = malloc(sizeof(complexo));
  p = lista;
  p->real = 1;  p->imag = 2;
  p->prox = malloc(sizeof(complexo));
  
  p = p->prox;
  p->real = 2; p->imag = 3;
  p->prox = malloc(sizeof(complexo));
  
  p = p->prox;
  p->real = 3; p->imag = 4;
  p->prox = malloc(sizeof(complexo));
  
  p = p->prox;
  p->real = 4; p->imag = 5;
  p->prox = NULL;

  p = lista;
  p = p->prox->prox;
//Removendo um elemento do meio para frente

  if(p != NULL) {// pois usaremos p->prox
    if(p == lista) {
      lista = p->prox;
    } else {
      a = lista;
      while(a->prox != p) a = a->prox;
      a->prox = p->prox;
    }
  }
  free(p);

//Percorrendo a lista  
  p = lista;
  while(p != NULL) {
    printf("(%f + i%f)\n",p->real,p->imag); 
    p=p->prox;
  }
  return 0;
}