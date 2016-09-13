/*
 *---------------------------------------------------------------------
 *
 * Name: fila.c
 * Author: Paulo Costa
 * Date: 30/01/08 02:13
 * Description:
 *   Implementa uma fila através de duas pilhas.
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

#ifndef MODULO_FILA
  #include "fila.h"
#endif

/*
 *---------------------------------------------------------------------
 *
 *   INTERFACE (visível por outros módulos)
 *
 *---------------------------------------------------------------------
 */

/*
 *-------------------------------------------------------------------
 * Protótipos de funções
 *-------------------------------------------------------------------
 */

void  poeFila    (tDado dado);
tDado tiraFila   (void);
tDado frenteFila (void);
int   tamFila    (void);
bool  filaVazia  (void);
void  zeraFila   (void);

/*
 *---------------------------------------------------------------------
 *
 *   IMPLEMENTAÇÃO (invisível para outros módulos)
 *
 *---------------------------------------------------------------------
 */

/*
 * Insere um dado no fim da fila
 *
 */

void poeFila (tDado dado)
{
  if (pilhaVazia (0))
    while (! pilhaVazia (1))
      poePilha (0, tiraPilha (1));
  poePilha (0, dado);
}

/*
 * Remove um dado do início da fila
 *
 */

tDado tiraFila (void)
{
  if (pilhaVazia (1))
    while (! pilhaVazia (0))
      poePilha (1, tiraPilha (0));
  return (tiraPilha (1));
}

/*
 * Retorna o dado na frente da fila sem removê-lo
 *
 */

tDado frenteFila (void)
{
  if (pilhaVazia (1))
    while (! pilhaVazia (0))
      poePilha (1, tiraPilha (0));
  return (topoPilha (1));
}

/*
 * Retorna um booleano indicando se a fila está vazia
 *
 */

bool filaVazia (void)
{
  return (pilhaVazia(0) && pilhaVazia(1));
}

/*
 * Retorna o número de elementos armazenados na fila
 *
 */

int tamFila (void)
{
  return (tamPilha(0) + tamPilha(1));
}

/*
 * Remove todo o conteúdo da fila
 *
 */

void zeraFila (void)
{
  zeraPilha(0);
  zeraPilha(1);
}
