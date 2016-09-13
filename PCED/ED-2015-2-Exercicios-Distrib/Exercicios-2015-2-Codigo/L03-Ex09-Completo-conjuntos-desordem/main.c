#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
  int iPos;
  for (iPos=0; iPos < MAX_A; iPos++)
    A[iPos] = POS_VAZIA;
}

void limpaB (void) {
  int iPos;
  for (iPos=0; iPos < MAX_B; iPos++)
    B[iPos] = POS_VAZIA;
}

void limpaC (void) {
  int iPos;
  for (iPos=0; iPos < MAX_C; iPos++)
    C[iPos] = POS_VAZIA;
}

void imprimeConjunto (char conjunto, char *letra) {
  int iPos, max;
  switch (conjunto) {
    case ('A'): max = MAX_A; break;
    case ('B'): max = MAX_B; break;
    case ('C'): max = MAX_C; break;
    default: exit (-1);
  }
  printf ("%c = { ", conjunto);
  for (iPos=0; iPos < max; iPos++)
    if (*letra)
      printf ("%c ", *letra++);
  printf ("}\n");
}

bool jaExiste (char letra, char *sequencia) {
  while ((*sequencia != letra) && (*sequencia != POS_VAZIA))
    sequencia++;
  return (*sequencia == letra);
}

void uniaoComRep (char *seqOrigem1, char *seqOrigem2, char *seqDestino) {
  char
    *letraOrigem1 = seqOrigem1,
    *letraOrigem2 = seqOrigem2,
    *letraDestino = seqDestino;

  while (*letraOrigem1 != POS_VAZIA)
    *(letraDestino++) = *(letraOrigem1++);
  while (*letraOrigem2 != POS_VAZIA)
    *(letraDestino++) = *(letraOrigem2++);
}

void uniaoSemRep (char *seqOrigem1, char *seqOrigem2, char *seqDestino) {
  char
    *letraOrigem1 = seqOrigem1,
    *letraOrigem2 = seqOrigem2,
    *letraDestino = seqDestino;

  while (*letraOrigem1 != POS_VAZIA) {
    if (! jaExiste (*letraOrigem1, seqDestino))
      *(letraDestino++) = *letraOrigem1;
    letraOrigem1++;
  }
  while (*letraOrigem2 != POS_VAZIA) {
    if (! jaExiste (*letraOrigem2, seqDestino))
      *(letraDestino++) = *letraOrigem2;
    letraOrigem2++;
  }
}

void intersecaoComRep (char *seqOrigem1, char *seqOrigem2, char *seqDestino) {
  int
    posOrigem2;
  char
    *letraOrigem1,
    *letraOrigem2,
    *letraDestino;
  bool
    usadoOrigem2 [MAX_B];

  letraOrigem1 = seqOrigem1;
  letraDestino = seqDestino;
  for (posOrigem2 = 0; posOrigem2 < MAX_B; posOrigem2++)
    usadoOrigem2 [posOrigem2] = false;
  while (*letraOrigem1 != POS_VAZIA) {
    letraOrigem2 = seqOrigem2;
    posOrigem2 = 0;
    while (*letraOrigem2 != POS_VAZIA) {
      if (*letraOrigem2 == *letraOrigem1) {
        if (! usadoOrigem2 [posOrigem2]) {
          *(letraDestino++) = *letraOrigem1;
          usadoOrigem2 [posOrigem2] = true;
          break;
        }
      }
      letraOrigem2++;
      posOrigem2++;
    }
  letraOrigem1++;
  }
}

void intersecaoSemRep (char *seqOrigem1, char *seqOrigem2, char *seqDestino) {
  int
    posOrigem2;
  char
    *letraOrigem1,
    *letraOrigem2,
    *letraDestino;
  bool
    usadoOrigem2 [MAX_B];

  letraOrigem1 = seqOrigem1;
  letraDestino = seqDestino;
  for (posOrigem2 = 0; posOrigem2 < MAX_B; posOrigem2++)
    usadoOrigem2 [posOrigem2] = false;
  while (*letraOrigem1 != POS_VAZIA) {
    if (jaExiste (*letraOrigem1, seqDestino))
      break;
    letraOrigem2 = seqOrigem2;
    posOrigem2 = 0;
    while (*letraOrigem2 != POS_VAZIA) {
      if (*letraOrigem2 == *letraOrigem1) {
        if (! usadoOrigem2 [posOrigem2]) {
          *(letraDestino++) = *letraOrigem1;
          usadoOrigem2 [posOrigem2] = true;
          break;
        }
      }
      letraOrigem2++;
      posOrigem2++;
    }
  letraOrigem1++;
  }
}

int main (int argc, char *argv[])
{
  limpaA();
  limpaB();

  /*
  strcpy (A, "giiimrtzz");
  strcpy (B, "dggiikoot");
  */
  strcpy (A, "gzritmzii");
  strcpy (B, "oogtigkid");

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
