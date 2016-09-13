#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_MAX 100

bool ehLetra (char c)
{
  return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}

char proximaLetra (char c) {
  c++;
  if (c=='z'+1) c = 'a';
  if (c=='Z'+1) c = 'A';
  return (c);
}

void criptografar (char *origem, char *destino) {
  int
    iPos, tamOrigem, trocar;
  char
    c;
  tamOrigem = strlen (origem);
  trocar = (tamOrigem < TAM_MAX ? tamOrigem : TAM_MAX);
  for (iPos=0; iPos<trocar; iPos++) {
  	c = origem[iPos];
    destino[iPos]= (ehLetra(c) ? proximaLetra(c) : c);
  }
}

int main (void)
{
  char
    mensagemOriginal      [TAM_MAX],
	mensagemCriptografada [TAM_MAX];

  printf ("Digite uma mensagem qualquer, ou 'fim' para terminar: ");
  scanf ("%s", mensagemOriginal);
  while (strcmp (mensagemOriginal, "fim")) {
    printf ("Mensagem original      = \"%s\"\n", mensagemOriginal);
    criptografar (mensagemOriginal, mensagemCriptografada);
    printf ("Mensagem criptografada = \"%s\"\n\n", mensagemCriptografada);
    printf ("Digite uma mensagem qualquer, ou 'fim' para terminar: ");
    scanf ("%s", mensagemOriginal);
  }
  return 0;
}
