/*
 *-----------------------------------------------------------------------
 * Arquivo: MDC.c
 * Autor: Paulo Costa
 * Data: 29/08/08 13:01
 * Descricao:
 *   Implementa versoes iterativas e recursivas de cálculo do MDC
 *   (máximo divisor comum) entre dois inteiros.
 *-----------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * MDC iterativo
 */

int mdcI (int x, int y)
{
  int t;
  if (x<y) {         // Importante garantir que x >= y
    t=y; y=x; x=t;   // Troque x e y se necessário
  }
  while ((x%y)!=0) {
    t=x%y; x=y; y=t;
  }
  return (y);
}

/*
 * MDC recursivo
 */

int mdcR (int x, int y)
{
  if ((y<=x) && ((x%y)==0)) 
    return (y);
  if (x<y)
    return (mdcR (y, x));
  return (mdcR (y, x%y));
}

/*
 * Main
 */

int main (int argc, char *argv[])
{
  int x, y;
    
  printf ("Digite dois inteiros positivos (ou nro <=0 para terminar): ");
  scanf ("%d %d", &x, &y);
  while (x>0 && y>0) {
    printf ("Versao iterativa: mdc(%d,%d) = %d\n", x, y, mdcI(x,y));
    printf ("Versao recursiva: mdc(%d,%d) = %d\n", x, y, mdcR(x,y));
    printf ("\nDigite dois inteiros positivos (ou nro negativo para terminar): ");
    scanf ("%d %d", &x, &y);
  }
  return 0;
}
