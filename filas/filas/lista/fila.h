#ifndef FILA_H
#define FILA_H

#include <assert.h>
#include <malloc.h>
typedef int obj_t; // O tipo do objeto é genérico. Neste exemplo usamos int. Basta mudar aqui.

typedef struct fila {  // A fila
   obj_t item;
   struct fila *ant, *prox;
} fila;

void enfileirar(fila **inicio, fila **fim, obj_t obj);  
obj_t desenfileirar(fila **inicio, fila **fim);

void enfileirar(fila **inicio, fila **fim, obj_t obj) {
  fila *np;
  np = malloc(sizeof(fila));
  np->item = obj;
  np->ant = (*fim);
  if(np->ant != NULL) np->ant->prox = np;
  np->prox = NULL;
  (*fim) = np;
  if(*inicio == NULL) (*inicio) = np;
  return;
}

obj_t desenfileirar(fila **inicio, fila **fim) {
  obj_t o;
  fila *d;
  assert((*inicio) != NULL);
  o = (*inicio)->item;
  d = (*inicio);
  if(*inicio == *fim) (*fim = NULL);
  else (*inicio->prox->ant) = NULL);
  (*inicio) = (*inicio)->prox;
  free(d);
  return o;
}

#endif //FILA_H