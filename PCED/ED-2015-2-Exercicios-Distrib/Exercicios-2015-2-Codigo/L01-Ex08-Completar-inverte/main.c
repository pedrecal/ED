#include <stdio.h>
#include <stdlib.h>

int inverteRec (int numero, int inverso) {
  if (numero == 0)
    return (inverso);
  return (  /*** ESCREVA AQUI SEU CODIGO ***/  );
}

int inverte (int numero){
  return (inverteRec (numero, 0));
}

int main()
{
  int numero;
  printf ("Digite um inteiro positivo (ou 0 para sair): ");
  scanf ("%d", &numero);
  while (numero > 0) {
    printf ("O inverso de %d eh %d \n\n", numero, inverte(numero));
    printf ("Digite um inteiro positivo (ou 0 para sair): ");
    scanf ("%d", &numero);
  }
  return 0;
}

  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
