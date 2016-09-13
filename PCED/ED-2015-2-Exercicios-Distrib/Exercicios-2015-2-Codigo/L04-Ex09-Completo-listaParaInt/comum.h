/*
 *---------------------------------------------------------------------
 *
 * Name: comum.c
 * Author: Paulo Costa
 * Date: 10/11/07 23:07
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

/* Tipos de erro que podem ocorrem */

enum tErro {
  erroMallocFalhou,
  erroListaVazia,
  erroNenhum
};

/*
 *-------------------------------------------------------------------
 * Prot�tipos de fun��es
 *-------------------------------------------------------------------
 */

extern void emiteErro (enum tErro erro);
