/*
 *---------------------------------------------------------------------
 *
 * Name: comum.c
 * Author: Paulo Costa
 * Date: 30/01/08 02:13
 * Description:
 *   M�dulo comum.c
 *   Emiss�o de mensagens de erro.
 *
 *---------------------------------------------------------------------
 */

/*
 *---------------------------------------------------------------------
 *   Inclus�o condicional de cabe�alhos
 *---------------------------------------------------------------------
 */

#ifndef MODULO_COMUM
  #include "comum.h"
#endif

/*
 *---------------------------------------------------------------------
 *
 *   INTERFACE (vis�vel por outros m�dulos)
 *
 *---------------------------------------------------------------------
 */

/*
 *---------------------------------------------------------------------
 *
 *   IMPLEMENTA��O (invis�vel para outros m�dulos)
 *
 *---------------------------------------------------------------------
 */

/*
 * Mostra o erro ocorrido na sa�da padr�o e no arquivo de sa�da
 *
 */

void emiteErro (enum tErro erro)
{
  switch (erro) {
    case (erroPilhaVazia)      : printf ("ERRO: Pilha vazia\n");
    case (erroPilhaCheia)      : printf ("ERRO: Pilha cheia\n");
    case (erroPilhaInexistente): printf ("ERRO: Pilha inexistente\n");
    case (erroFilaVazia)       : printf ("ERRO: Fila vazia\n");
    case (erroFilaCheia)       : printf ("ERRO: Fila cheia\n");
  }
  exit (-1);
}

