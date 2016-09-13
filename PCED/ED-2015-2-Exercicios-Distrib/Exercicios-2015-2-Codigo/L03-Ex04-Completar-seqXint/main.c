#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX  8
#define POS_VAZIA   -1

int 
  A [TAM_MAX],
  B [TAM_MAX],
  C [TAM_MAX];

void limpaSeq (int *pSeq) {
  int iPos;
  for (iPos=0; iPos < TAM_MAX; iPos++)
    *(pSeq++) = POS_VAZIA;
}

void mostraSeq (char *nomeSeq, int *pSeq) {
  int iPos;
  printf ("%s = [ ", nomeSeq);
  for (iPos=0; iPos < TAM_MAX; iPos++)
    printf ("%2d ", *(pSeq++));
  printf ("]\n");
}

void num2seq (int numero, int *pSeq) {
	
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
  
}

int seq2num (int *pSeq) {
	
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
  
}

int main (void) {
  int a=0, b=0;
  limpaSeq (A);
  limpaSeq (B);
  limpaSeq (C);
  num2seq (123,  A);
  num2seq (6789, B);
  a = seq2num (A);
  b = seq2num (B);
  num2seq (a+b, C);
  mostraSeq ("A", A);
  mostraSeq ("B", B);
  mostraSeq ("C", C);
  printf ("\n");
  system("PAUSE");	
  return 0;
}
