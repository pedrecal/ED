/*
TreeList.c

C code version of the great Tree-List recursion problem.
See http://cslibrary.stanford.edu/109/ for the full
discussion and the Java solution.

This code is free for any purpose.
Feb 22, 2000 - Nick Parlante nick.parlante@cs.stanford.edu
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/* Nodos usados para construir a árvore e a lista encadeada */

struct nodo {
  int dado;
  struct nodo* menor;
  struct nodo* maior;
};

typedef struct nodo* tNodo;

/* Une dois nodos de modo que o 2o. segue após o 1o. Equivale a ajustar */
/* o ponteiro "proximo" do 1o. nodo e o ponteiro "anterior" do 2o.      */

void uneNodos (tNodo nodo1, tNodo nodo2) {
  nodo1->maior = nodo2;
  nodo2->menor = nodo1;
}

/* Une duas listas circulares duplamente encadeadas e     */
/* retorna um ponteiro para o início da lista resultante. */

tNodo uneListas (tNodo lista1, tNodo lista2) {
  tNodo 
    ultimoLista1, 
    ultimoLista2;
    
  if (lista1 == NULL) 
  	return (lista2);
  if (lista2 == NULL) 
  	return (lista1);
  ultimoLista1 = lista1->menor;
  ultimoLista2 = lista2->menor;
  uneNodos (ultimoLista1, lista2);
  uneNodos (ultimoLista2, lista1);
  return (lista1);
}

/* Dada uma árvore binária ordenada, transforma-a recursivamente numa        */
/* lista circular duplamente encadeada e retorna um ponteiro para seu início */

tNodo arvoreParaLista (tNodo raiz) {
  tNodo 
    lista1, 
	lista2;
    
  if (raiz == NULL) return (NULL);

  /* Chamadas recursivas para transformar as duas sub-árvores */
  
  lista1 = arvoreParaLista (raiz->menor);
  lista2 = arvoreParaLista (raiz->maior);

  /* Crie com a raiz da árvore uma lista de um único nodo */
  
  raiz->menor = raiz;
  raiz->maior = raiz;

  /* Junte as três listas parciais em ordem crescente */
  
  lista1 = uneListas (lista1, raiz);
  lista1 = uneListas (lista1, lista2);
  return (lista1);
}

/* Cria um novo nodo */

tNodo novoNodo (int dado) {
  tNodo 
    nodo = (tNodo) malloc (sizeof(struct nodo));
    
  nodo->dado  = dado;
  nodo->menor = NULL;
  nodo->maior = NULL;
  return (nodo);
}

/* Insere um nodo existente na árvore */

void insereNaArvore (tNodo* ptrRaiz, int dado) {
  tNodo 
    raiz = *ptrRaiz;
    
  if (raiz == NULL) 
  	*ptrRaiz = novoNodo(dado);
  else {
    if (dado <= raiz->dado) 
    	insereNaArvore (&(raiz->menor), dado);
    else 
    	insereNaArvore (&(raiz->maior), dado);
  }
}

/* Percorre a lista imprimindo os dados armazenados nos nodos */

void imprimeLista (tNodo inicio) {
  tNodo current = inicio;
    
  while (current != NULL) {
    printf ("%d ", current->dado);
    current = current->maior;
    if (current == inicio) 
    	break;
  }
  printf ("\n");
}

/* Função main para demonstrar que a conversão de árvore para lista funciona */

int main (int argc, char *argv[]) {
  tNodo 
    raiz = NULL,
    inicio;

  insereNaArvore (&raiz, 4);
  insereNaArvore (&raiz, 2);
  insereNaArvore (&raiz, 1);
  insereNaArvore (&raiz, 3);
  insereNaArvore (&raiz, 5);
  inicio = arvoreParaLista (raiz);
  imprimeLista (inicio);  /* Deve imprimir: 1 2 3 4 5 */
  system ("PAUSE");
  return (0);
}

