/*
 *---------------------------------------------------------------------
 *
 * Name: comum.c
 * Author: Paulo Costa
 * Date: 10/11/07 23:07
 * Description:
 *   Módulo comum.c
 *   Definições básicas e emissão de mensagens de erro.
 *
 *---------------------------------------------------------------------
 */

/*
 *---------------------------------------------------------------------
 *   Inclusão condicional de cabeçalhos
 *---------------------------------------------------------------------
 */

#ifndef MODULO_COMUM
  #include "comum.h"
#endif

/*
 *---------------------------------------------------------------------
 *
 *   INTERFACE (visível por outros módulos)
 *
 *---------------------------------------------------------------------
 */

/*
 *---------------------------------------------------------------------
 *
 *   IMPLEMENTAÇÃO (invisível para outros módulos)
 *
 *---------------------------------------------------------------------
 */

/*
 * Mostra o erro ocorrido na saída padrão e no arquivo de saída
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

