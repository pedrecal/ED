#ifndef FILA_H
#define FILA_H
#define TAMANHOFILA 100

#include <assert.h>
typedef int obj_t; // O tipo do objeto é genérico. Neste exemplo usamos int. Basta mudar aqui.
typedef int boolean; // Verdadeiro ou Falso, conforme o enum abaixo.
enum{falso, verdade};

typedef struct fila {  // A fila
   obj_t itens[TAMANHOFILA];
   int inicio, fim;  
   boolean cheia, vazia;
} fila;

boolean enfileirar(fila *p, obj_t obj);  
obj_t desenfileirar(fila *p);
boolean ehvazia(fila p);

boolean enfileirar(fila *p, obj_t obj) {
  boolean ret = falso;
  if(!p->cheia) {
    p->itens[p->fim++ -1]=obj;
    if(p->fim > TAMANHOFILA) p->fim=1;
    if(p->inicio == p->fim) p->cheia=verdade;
    p->vazia=falso;
    ret = verdade;
  }
  return ret;
}

obj_t desenfileirar(fila *p) {
  obj_t o;
  assert(!p->vazia);
  o = p->itens[p->inicio++ -1];
  if(p->inicio> TAMANHOFILA) p->inicio=1;
  if(p->inicio == p->fim) p->vazia=verdade;
  p->cheia=falso;
  return o;
}

boolean ehvazia(fila p) {
  return (p.vazia);
}
  

#endif //FILA_H