#include <stdio.h>
#include <stdlib.h>

int removePares (int numero) {
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

int removeImpares (int numero) {
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

int zeraPares (int numero) {
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

int zeraImpares (int numero) {
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

int main() {
  int n;
  printf ("Digite um inteiro positivo (ou 0 para sair): ");
  scanf ("%d", &n);
  while (n > 0) {
    printf ("%d com digitos pares   zerados   vira %d \n", n, zeraPares(n));
    printf ("%d com digitos impares zerados   vira %d \n", n, zeraImpares(n));
    printf ("%d com digitos pares   removidos vira %d \n", n, removePares(n));
    printf ("%d com digitos impares removidos vira %d \n\n", n, removeImpares(n));
    printf ("Digite um inteiro positivo (ou 0 para sair): ");
    scanf ("%d", &n);
  }
  return 0;
}
