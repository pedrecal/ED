/*
 *---------------------------------------------------------------------
 *
 * Name: fila.h
 * Author: Paulo Costa
 * Date: 30/01/08 02:13
 * Description:
 *   Defini��es para o m�dulo fila.c
 *
 *---------------------------------------------------------------------
 */

#define MODULO_FILA

/*
---------------------------------------------------------------------------------------------
  Inclus�o condicional de cabe�alhos
---------------------------------------------------------------------------------------------
*/

#ifndef MODULO_COMUM
  #include "comum.h"
#endif

/*
 *-------------------------------------------------------------------
 * Prot�tipos de fun��es
 *-------------------------------------------------------------------
 */

extern void  poeFila    (tDado dado);
extern tDado tiraFila   (void);
extern tDado frenteFila (void);
extern int   tamFila    (void);
extern bool  filaVazia  (void);
extern void  zeraFila   (void);
