#ifndef PILHA_H
#define PILHA_H

#include <assert.h>
#include <malloc.h>
typedef int obj_t; // O tipo do objeto é genérico. Neste exemplo usamos int. Basta mudar aqui.

typedef struct pilha {  // A pilha
   obj_t item;
   struct pilha *prox;
} pilha;

void empilhar(pilha **p, obj_t obj);  
obj_t desempilhar(pilha **p);

void empilhar(pilha **p, obj_t obj) {
  pilha *np;
  np = malloc(sizeof(pilha));
  np->prox = (*p);
  np->item = obj;
  (*p) = np;
}

obj_t desempilhar(pilha **p) {
  obj_t o;
  pilha *d;
  assert((*p) != NULL);
  o = (*p)->item;
  d = (*p);
  (*p) = (*p)->prox;
  o = d->item;
  free(d);
  return o;
}

#endif //PILHA_H