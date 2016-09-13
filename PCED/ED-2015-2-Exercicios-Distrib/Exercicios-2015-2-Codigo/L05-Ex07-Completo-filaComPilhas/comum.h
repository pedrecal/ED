/*
 *---------------------------------------------------------------------
 *
 * Name: comum.c
 * Author: Paulo Costa
 * Date: 30/01/08 02:13
 * Description:
 *   Defini��es b�sicas e emiss�o de mensagens de erro.
 *
 *---------------------------------------------------------------------
 */

#define MODULO_COMUM

/*
---------------------------------------------------------------------------------------------
  Inclus�o de cabe�alhos
---------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
---------------------------------------------------------------------------------------------
  Defini��es b�sicas
---------------------------------------------------------------------------------------------
*/

/* Defini��es para implementa��o das estruturas de dados (pilha, fila e deque) */

#define TAM_MAX    10
#define tDado      char
#define DADO_NULO  '\0'
#define FORMATO    "%c"

#define TOT_PILHAS 3    /* Nro de pilhas dispon�veis */

/* Tipos de erro que podem ocorrem ao acessar qualquer estrutura de dados */

enum tErro {
  erroPilhaVazia,
  erroPilhaCheia,
  erroPilhaInexistente,
  erroFilaVazia,
  erroFilaCheia,
  erroNenhum
};

/*
 *-------------------------------------------------------------------
 * Prot�tipos de fun��es
 *-------------------------------------------------------------------
 */

extern void emiteErro (enum tErro erro);
