#include <stdio.h>
#include <stdlib.h>

typedef struct st_complexo 
{
  double real;
  double imag;
  struct st_complexo *prox;
} complexo;

int main(int argc, char **args) {
  complexo *lista, *p, *n, *a;

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
  
// Troque o comentário das duas linhas abaixo para inserir no final  
  p = p->prox->prox;
//  p = NULL;
  
//Inserindo do meio da lista para o fim

  n = malloc(sizeof(complexo));
  n->real = 5; n->imag = 6; n->prox = NULL;
  
  n->prox = p;
  if(p == lista) {
    lista = n;
  } else {
    a = lista;
    while(a->prox != p) a = a->prox;
    a->prox = n;
  }

//Percorrendo a lista  
  p = lista;
  while(p != NULL) {
    printf("(%f + i%f)\n",p->real,p->imag); 
    p=p->prox;
  }
  return 0;
}