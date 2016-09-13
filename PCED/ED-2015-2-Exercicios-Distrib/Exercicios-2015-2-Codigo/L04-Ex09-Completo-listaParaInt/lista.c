/*
 *--------------------------------------------------------------------------
 *
 * Name: lista.h
 * Author: Paulo Costa
 * Date: 2014-06-18 12:45
 * Description:
 *   Defini��es para o m�dulo lista.c
 *   Implementa uma lista simplesmente encadeada e suas fun��es de acesso.
 *
 *--------------------------------------------------------------------------
 */

/*
 *---------------------------------------------------------------------
 *   Inclus�o condicional de cabe�alhos
 *---------------------------------------------------------------------
 */

#ifndef MODULO_COMUM
  #include "comum.h"
#endif

#ifndef MODULO_PILHA
  #include "lista.h"
#endif

/*
 *---------------------------------------------------------------------
 *
 *   INTERFACE (vis�vel por outros m�dulos)
 *
 *---------------------------------------------------------------------
 */

/*
 *-------------------------------------------------------------------
 * Prot�tipos de fun��es
 *-------------------------------------------------------------------
 */

void poeNoFim (struct nodo **refLista, int dado);
int  tamLista (struct nodo *lista);

/*
 *---------------------------------------------------------------------
 *
 *   IMPLEMENTA��O (invis�vel para outros m�dulos)
 *
 *---------------------------------------------------------------------
 */

/*
 *-------------------------------------------------------------------
 * Prot�tipos de fun��es
 *-------------------------------------------------------------------
 */

/*
 * Cria um novo nodo e adiciona-o no final da lista fornecida
 */

void poeNoFim (struct nodo **refLista, int digito) {
  struct nodo
    *pUltimoNodo = NULL,
    *pNovoNodo = NULL;

  pNovoNodo = (struct nodo *) malloc (sizeof (struct nodo));
  if (pNovoNodo == NULL)
    emiteErro (erroMallocFalhou);
  pNovoNodo->dado = digito;
  pNovoNodo->prox = NULL;

  pUltimoNodo = *refLista;
  while ((pUltimoNodo != NULL) && (pUltimoNodo->prox != NULL))
    pUltimoNodo = pUltimoNodo->prox;
  if (*refLista == NULL)
    *refLista = pNovoNodo;
  else
    pUltimoNodo->prox = pNovoNodo;
  pUltimoNodo = pNovoNodo;
}

/*
 * Retorna o numero de nodos na lista fornecida
 */

int tamLista (struct nodo *lista) {
  int
    tamanho = 0;

  while (lista != NULL) {
    lista = lista->prox;
    tamanho++;
  }
  return (tamanho);
}
