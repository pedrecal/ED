#include <stdio.h>
#include <stdlib.h>

int contaDigitos (int n) {
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

int somaDigitos (int n) {
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

int main() {
  int n;
  printf ("Digite um inteiro positivo (ou 0 para sair): ");
  scanf ("%d", &n);
  while (n > 0) {
    printf ("%d possui %d digitos e sua soma eh %d \n\n", n, contaDigitos(n), somaDigitos(n));
    printf ("Digite um inteiro positivo (ou 0 para sair): ");
    scanf ("%d", &n);
  }
  return 0;
}
