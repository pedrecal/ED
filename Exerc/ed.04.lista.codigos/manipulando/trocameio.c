#include <stdio.h>
#include <stdlib.h>

typedef struct st_complexo 
{
  double real;
  double imag;
  struct st_complexo *prox;
} complexo;

int main(int argc, char **args) {
  complexo *lista, *a, *b, *c, *d, *e;

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
  a = a->prox;
// Troque o comentário das duas próximas linhas para fazer a e b consecutivos  
  b = b->prox->prox->prox;
//  b =  b->prox->prox; 

//Trocando dois elmentos a e b.
//a antecede b, portanto não é nulo.
  
  if(b != NULL) {// pois usaremos b->prox
    d = a->prox; // preciso saber a sequencia
    e = lista;
    while(e->prox != b) e=e->prox; // preciso saber quem aponta para b
    if(a == lista)
      lista = b;
    else {
      c = lista;
      while(c->prox != a) c = c->prox;
      c->prox = b;
    }
    a->prox = b->prox;
    if(b == d)
      b->prox = a;
    else
      b->prox = d;
    if(a != e)
      e->prox = a;
  }

//Percorrendo a lista  
  a = lista;
  while(a != NULL) {
    printf("(%f + i%f)\n",a->real,a->imag); 
    a=a->prox;
  }
  return 0;
}