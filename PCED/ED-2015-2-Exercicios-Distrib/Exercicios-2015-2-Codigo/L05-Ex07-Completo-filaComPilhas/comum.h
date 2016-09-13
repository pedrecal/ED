/*
 *---------------------------------------------------------------------
 *
 * Name: comum.c
 * Author: Paulo Costa
 * Date: 30/01/08 02:13
 * Description:
 *   Definições básicas e emissão de mensagens de erro.
 *
 *---------------------------------------------------------------------
 */

#define MODULO_COMUM

/*
---------------------------------------------------------------------------------------------
  Inclusão de cabeçalhos
---------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
---------------------------------------------------------------------------------------------
  Definições básicas
---------------------------------------------------------------------------------------------
*/

/* Definições para implementação das estruturas de dados (pilha, fila e deque) */

#define TAM_MAX    10
#define tDado      char
#define DADO_NULO  '\0'
#define FORMATO    "%c"

#define TOT_PILHAS 3    /* Nro de pilhas disponíveis */

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
 * Protótipos de funções
 *-------------------------------------------------------------------
 */

extern void emiteErro (enum tErro erro);
