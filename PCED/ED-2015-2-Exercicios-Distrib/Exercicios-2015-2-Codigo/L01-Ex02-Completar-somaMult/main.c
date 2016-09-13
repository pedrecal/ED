/*
 *-----------------------------------------------------------------------
 * Arquivo: somaMult.c
 * Autor: COLOQUE SEU NOME AQUI
 * Data: 08/02/2008 23:09
 * Descricao:
 *   Implementa versoes iterativas e recursivas de soma e multiplicação.
 *-----------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Soma iterativa
 */

int somaI (int a, int b)
{
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

/*
 * Soma recursiva
 */

int somaR (int a, int b)
{
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

/*
 * Multiplicação iterativa
 */

int multI (int a, int b)
{
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

/*
 * Multiplicação recursiva
 */

int multR (int a, int b)
{
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

/*
 * Main
 */

int main (int argc, char *argv[])
{
  int 
    a, b, sI, sR, mI, mR;
    
  printf ("Digite dois inteiros, ou nro negativo para terminar: ");
  scanf ("%d %d", &a, &b);
  while (a>=0 && b>=0) {
    sI = somaI (a,b);
    sR = somaR (a,b);
    mI = multI (a,b);
    mR = multR (a,b);
    printf ("somaI: %d + %d = %d  %s\n", a, b, sI, (sI == a+b)? "Ok" : "ERRO");
    printf ("somaR: %d + %d = %d  %s\n", a, b, sR, (sR == a+b)? "Ok" : "ERRO");
    printf ("multI: %d x %d = %d  %s\n", a, b, mI, (mI == a*b)? "Ok" : "ERRO");
    printf ("multR: %d x %d = %d  %s\n", a, b, mR, (mR == a*b)? "Ok" : "ERRO");
    printf ("\nDigite dois inteiros, ou nro negativo para terminar: ");
    scanf ("%d %d", &a, &b);
  }
  return 0;
}
