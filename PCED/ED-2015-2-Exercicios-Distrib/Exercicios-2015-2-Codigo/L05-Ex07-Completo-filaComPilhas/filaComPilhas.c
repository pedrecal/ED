/*
 *---------------------------------------------------------------------
 *
 * Name: main.c
 * Author: Paulo Costa
 * Date: 30/01/08 02:13
 * Description:
 *   Determina se uma palavra digitada pelo usuário é um palíndromo.
 *   Esse programa serve para testar a funcionalidade da fila, que
 *   deverá ser implementada através de duas pilhas.
 *
 *---------------------------------------------------------------------
 */

/*
---------------------------------------------------------------------------------------------
  Inclusão condicional de cabeçalhos
---------------------------------------------------------------------------------------------
*/

#ifndef MODULO_COMUM
  #include "comum.h"
#endif

#ifndef MODULO_FILA
  #include "fila.h"
#endif

#ifndef MODULO_PILHA
  #include "pilha.h"
#endif

/*
 *---------------------------------------------------------------------
 *
 *   IMPLEMENTAÇÃO
 *
 *---------------------------------------------------------------------
 */

#include <string.h>

char
  palavra [TAM_MAX];

int
  tamPalavra,
  letrasUsadas;

/*
---------------------------------------------------------------------------------------------
  Retorna um booleano indicando se todas as letras da palavra foram  lidas
---------------------------------------------------------------------------------------------
*/

bool acabaramAsLetras (void)
{
  return (letrasUsadas == tamPalavra);
}

/*
---------------------------------------------------------------------------------------------
  Retorna uma letra da palavra de cada vez
---------------------------------------------------------------------------------------------
*/

char obtemLetra (void)
{
  if (! acabaramAsLetras())
    return (palavra[letrasUsadas++]);
}

/*
---------------------------------------------------------------------------------------------
  Retorna um booleano indicando se a palavra é um palíndromo
---------------------------------------------------------------------------------------------
*/

bool ehPalindromo (void)
{
  /*
  // Solução 2: Usando uma pilha e uma fila
  // As pilhas 0 e 1 são reservadas (usadas na implementação da fila);
  // a pilha 2 está disponível para ser usada livremente.
  */

  char
    letra;

  while (! acabaramAsLetras()) {
    letra = obtemLetra();
    poePilha (2, letra);
    poeFila  (letra);
  }
  while (! pilhaVazia(2))
    if (tiraPilha(2) != tiraFila())
      return (false);
  return (true);
}

/*
---------------------------------------------------------------------------------------------
  main
---------------------------------------------------------------------------------------------
*/

int main (int argc, char *argv[])
{
  printf ("Digite uma palavra qualquer, ou 'fim' para terminar: ");
  scanf ("%s", palavra);
  while (strcmp (palavra, "fim")) {
    printf ("[%s] ", palavra);
    tamPalavra = strlen (palavra);
    letrasUsadas = 0;
    zeraPilha(2);
    zeraFila();
    if (! ehPalindromo())
      printf ("nao ");
    printf ("eh um palindromo\n\n");
    printf ("Digite uma palavra qualquer, ou 'fim' para terminar: ");
    scanf ("%s", palavra);
  }
  return 0;
}
