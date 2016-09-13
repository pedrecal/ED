/*
 *---------------------------------------------------------------------
 *
 * Name: comum.c
 * Author: Paulo Costa
 * Date: 30/01/08 02:13
 * Description:
 *   Módulo comum.c
 *   Emissão de mensagens de erro.
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
    case (erroPilhaVazia)      : printf ("ERRO: Pilha vazia\n");
    case (erroPilhaCheia)      : printf ("ERRO: Pilha cheia\n");
    case (erroPilhaInexistente): printf ("ERRO: Pilha inexistente\n");
    case (erroFilaVazia)       : printf ("ERRO: Fila vazia\n");
    case (erroFilaCheia)       : printf ("ERRO: Fila cheia\n");
  }
  exit (-1);
}

