#include <stdio.h>
#include <stdlib.h>

int menorDigito (int n) {
  if (n<=9) return (n);
  return ((n%10) <= menorDigito (n/10) ? (n%10) : menorDigito (n/10));
}

int maiorDigito (int n) {
  if (n==0) return (0);
  return ((n%10) >= maiorDigito (n/10) ? (n%10) : maiorDigito (n/10));
}

int main() {
  int n;
  printf ("Digite um inteiro positivo (ou 0 para sair): ");
  scanf ("%d", &n);
  while (n > 0) {
    printf ("O menor digito de %d eh %d \n", n, menorDigito(n));
    printf ("O maior digito de %d eh %d \n\n", n, maiorDigito(n));
    printf ("Digite um inteiro positivo (ou 0 para sair): ");
    scanf ("%d", &n);
  }
  return 0;
}
