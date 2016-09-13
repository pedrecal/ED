/*
 *--------------------------------------------------------------------------
 *
 * Name: lista.h
 * Author: Paulo Costa
 * Date: 2014-06-18 12:45
 * Description:
 *   Definições para o módulo lista.c
 *   Implementa uma lista simplesmente encadeada e suas funções de acesso.
 *
 *--------------------------------------------------------------------------
 */

#define MODULO_LISTA

/*
---------------------------------------------------------------------------------------------
  Inclusão condicional de cabeçalhos
---------------------------------------------------------------------------------------------
*/

#ifndef MODULO_COMUM
  #include "comum.h"
#endif

struct nodo {
  int dado;
  struct nodo *prox;
};

/*
 *-------------------------------------------------------------------
 * Protótipos de funções
 *-------------------------------------------------------------------
 */

extern void poeNoFim (struct nodo **refLista, int dado);
extern int  tamLista (struct nodo *lista);
