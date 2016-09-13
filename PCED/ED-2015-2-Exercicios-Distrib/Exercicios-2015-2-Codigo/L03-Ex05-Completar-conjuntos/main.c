#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX    15
#define POS_VAZIA   0

#define MAX_A   TAM_MAX
#define MAX_B   TAM_MAX
#define MAX_C   (TAM_MAX * 2)

char 
  A [MAX_A],
  B [MAX_B],
  C [MAX_C];

void limpaA (void) {
  int i;
  for (i=0; i < MAX_A; i++)
    A[i] = POS_VAZIA;
}

void limpaB (void) {
  int i;
  for (i=0; i < MAX_B; i++)
    B[i] = POS_VAZIA;
}

void limpaC (void) {
  int i;
  for (i=0; i < MAX_C; i++)
    C[i] = POS_VAZIA;
}

void imprimeConjunto (char conjunto, char *letra) {
  int i, max;
  switch (conjunto) {
    case ('A'): max = MAX_A; break;
    case ('B'): max = MAX_B; break;
    case ('C'): max = MAX_C; break;
    default: exit (-1);
  }  
  printf ("%c = { ", conjunto);
  for (i=0; i < max; i++)
    if (*letra)
      printf ("%c ", *letra++);
  printf ("}\n");
}

void uniaoComRep (char *letraA, char *letraB, char *letraC) {
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

void uniaoSemRep (char *letraA, char *letraB, char *letraC) {
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

void intersecaoComRep (char *letraA, char *letraB, char *letraC) {
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

void intersecaoSemRep (char *letraA, char *letraB, char *letraC) {
  /* +-------------------------+ */
  /* | ESCREVA AQUI SEU CODIGO | */
  /* +-------------------------+ */
}

int main (int argc, char *argv[])
{
  limpaA();
  limpaB();
    
  strcpy (A, "giiimrtzz");
  strcpy (B, "dggiikoot");

  imprimeConjunto ('A', A);
  imprimeConjunto ('B', B);
  
  printf ("\nUNIAO COM REPETICAO:\n");
  limpaC();
  uniaoComRep (A, B, C);
  imprimeConjunto ('C', C);
  
  printf ("\nUNIAO SEM REPETICAO:\n");    
  limpaC();
  uniaoSemRep (A, B, C);
  imprimeConjunto ('C', C);
    
  printf ("\nINTERSECAO COM REPETICAO:\n");
  limpaC();
  intersecaoComRep (A, B, C);
  imprimeConjunto ('C', C);
    
  printf ("\nINTERSECAO SEM REPETICAO:\n");
  limpaC();
  intersecaoSemRep (A, B, C);
  imprimeConjunto ('C', C);
    
  printf ("\n");
  system("PAUSE");	
  return 0;
}
