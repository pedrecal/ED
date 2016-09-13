#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_MAX 100

bool ehPalindromo (char *palavra, int tamanho, int pos)
{
  bool
    letrasIguais;

/*
  letrasIguais = (palavra[pos] == palavra[tamanho-pos-1]);
  if (pos >= (int)((tamanho-1)/2))
    return (letrasIguais);
  else
    return (letrasIguais && ehPalindromo (palavra, tamanho, pos+1));
*/

  if (tamanho-2*pos <= 1)
    return (true);
  else
    letrasIguais = (palavra[pos] == palavra[tamanho-pos-1]);
    return (letrasIguais && ehPalindromo (palavra, tamanho, pos+1));
}

int main(int argc, char *argv[])
{
  char
    palavra [TAM_MAX];

  printf ("Digite uma palavra qualquer, ou 'fim' para terminar: ");
  scanf ("%s", palavra);
  while (strcmp (palavra, "fim")) {
    printf ("[%s] ", palavra);
    if (! ehPalindromo(palavra, strlen(palavra), 0))
      printf ("nao ");
    printf ("eh um palindromo\n\n");
    printf ("Digite uma palavra qualquer, ou 'fim' para terminar: ");
    scanf ("%s", palavra);
  }
  return 0;
}
