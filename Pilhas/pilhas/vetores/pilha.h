#ifndef PILHA_H
#define PILHA_H
#define TAMANHOPILHA 100

#include <assert.h>
typedef int obj_t; // O tipo do objeto é genérico. Neste exemplo usamos int. Basta mudar aqui.
typedef int boolean; // Verdadeiro ou Falso, conforme o enum abaixo.
enum{falso, verdade};

typedef struct pilha {  // A pilha
   obj_t itens[TAMANHOPILHA];
   int topo;  // 0 é pilha vazia TAMANHOPILHA é pilha cheia.
} pilha;

boolean empilhar(pilha *p, obj_t obj);  
obj_t desempilhar(pilha *p);
boolean ehvazia(pilha p);

boolean empilhar(pilha *p, obj_t obj) {
  boolean ret = falso;
  if(p->topo < TAMANHOPILHA) {
    p->itens[p->topo++]=obj;
    ret = verdade;
  }
  return ret;
}

obj_t desempilhar(pilha *p) {
  assert(p->topo > 0);
  return p->itens[--p->topo];
}

boolean ehvazia(pilha p) {
  return (p.topo ? falso : verdade);
}
  

#endif //PILHA_H