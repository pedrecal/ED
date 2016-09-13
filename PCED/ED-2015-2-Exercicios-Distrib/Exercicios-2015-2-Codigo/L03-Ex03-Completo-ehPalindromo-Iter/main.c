#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_MAX 100

bool ehPalindromo (char *palavra, int tamanho)
{
  int
    pos;

  for (pos = 0; pos < (int)((tamanho+1)/2); pos++)
    if (palavra[pos] != palavra[tamanho-pos-1])
      return (false);
  return (true);
}

int main(int argc, char *argv[])
{
  char
    palavra [TAM_MAX];

  printf ("Digite uma palavra qualquer, ou 'fim' para terminar: ");
  scanf ("%s", palavra);
  while (strcmp (palavra, "fim")) {
    printf ("[%s] ", palavra);
    if (! ehPalindromo(palavra, strlen(palavra)))
      printf ("nao ");
    printf ("eh um palindromo\n\n");
    printf ("Digite uma palavra qualquer, ou 'fim' para terminar: ");
    scanf ("%s", palavra);
  }
  return 0;
}
