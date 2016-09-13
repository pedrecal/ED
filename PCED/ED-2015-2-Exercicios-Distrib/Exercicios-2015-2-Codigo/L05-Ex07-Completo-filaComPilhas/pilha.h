/*
 *---------------------------------------------------------------------
 *
 * Name: pilha.h
 * Author: Paulo Costa
 * Date: 30/01/08 02:13
 * Description:
 *   Defini��es para o m�dulo pilha.c
 *
 *---------------------------------------------------------------------
 */

#define MODULO_PILHA

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

extern void  poePilha    (int numPilha, tDado dado);
extern tDado tiraPilha   (int numPilha);

extern tDado topoPilha   (int numPilha);
extern int   tamPilha    (int numPilha);
extern bool  pilhaVazia  (int numPilha);

extern void  zeraPilha   (int numPilha);
extern void  mostraPilha (int numPilha);
