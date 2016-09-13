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

#define MODULO_LISTA

/*
---------------------------------------------------------------------------------------------
  Inclus�o condicional de cabe�alhos
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
 * Prot�tipos de fun��es
 *-------------------------------------------------------------------
 */

extern void poeNoFim (struct nodo **refLista, int dado);
extern int  tamLista (struct nodo *lista);
