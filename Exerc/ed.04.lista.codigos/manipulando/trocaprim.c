#include <stdio.h>
#include <stdlib.h>

typedef struct st_complexo 
{
  double real;
  double imag;
  struct st_complexo *prox;
} complexo;

int main(int argc, char **args) {
  complexo *lista, *a, *b, *c, *d;

//Criando uma lista  
  lista = malloc(sizeof(complexo));
  a = lista;
  a->real = 1;  a->imag = 2;
  a->prox = malloc(sizeof(complexo));
  
  a = a->prox;
  a->real = 2; a->imag = 3;
  a->prox = malloc(sizeof(complexo));
  
  a = a->prox;
  a->real = 3; a->imag = 4;
  a->prox = malloc(sizeof(complexo));
  
  a = a->prox;
  a->real = 4; a->imag = 5;
  a->prox = NULL;

  a = b = lista;
  
// Troque o comentário das duas próximas linhas para fazer a e b consecutivos  
  b = b->prox->prox;
//  b =  b->prox; 

//Trocando o primeiro elemento com outro 
//a é o primeiro elemento logo diferente de NULL
  if(b != NULL) {// pois usaremos b->prox
    c = a->prox; // preciso saber a sequencia
    d = lista;
    while(d->prox != b) d=d->prox; // preciso saber quem aponta para b
    if(a == lista) {
      lista = b;
      a->prox = b->prox;
      if(b == c)
	b->prox = a;
      else
	b->prox = c;
      if(a != d)
        d->prox = a;
    }
  }

//Percorrendo a lista  
  a = lista;
  while(a != NULL) {
    printf("(%f + i%f)\n",a->real,a->imag); 
    a=a->prox;
  }
  return 0;
}