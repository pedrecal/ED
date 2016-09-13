/*
 *---------------------------------------------------------------------
 *
 * Name: comum.c
 * Author: Paulo Costa
 * Date: 10/11/07 23:07
 * Description:
 *   M�dulo comum.c
 *   Defini��es b�sicas e emiss�o de mensagens de erro.
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
    case (erroMallocFalhou) : printf ("ERRO: malloc falhou\n");
    case (erroListaVazia)   : printf ("ERRO: list vazia\n");
  }
  exit (-1);
}

