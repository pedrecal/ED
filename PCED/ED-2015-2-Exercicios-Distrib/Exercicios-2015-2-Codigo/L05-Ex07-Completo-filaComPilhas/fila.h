/*
 *---------------------------------------------------------------------
 *
 * Name: fila.h
 * Author: Paulo Costa
 * Date: 30/01/08 02:13
 * Description:
 *   Definições para o módulo fila.c
 *
 *---------------------------------------------------------------------
 */

#define MODULO_FILA

/*
---------------------------------------------------------------------------------------------
  Inclusão condicional de cabeçalhos
---------------------------------------------------------------------------------------------
*/

#ifndef MODULO_COMUM
  #include "comum.h"
#endif

/*
 *-------------------------------------------------------------------
 * Protótipos de funções
 *-------------------------------------------------------------------
 */

extern void  poeFila    (tDado dado);
extern tDado tiraFila   (void);
extern tDado frenteFila (void);
extern int   tamFila    (void);
extern bool  filaVazia  (void);
extern void  zeraFila   (void);
