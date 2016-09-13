#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_MAX 30

int
  totNum = 0,
  numeros [TAM_MAX];

bool ehImpar (int numero) {
  return ((numero % 2) == 1);
}

void obtemNumeros (void) {
  int
    iNum;
  printf ("Quantos numeros? ");
  scanf ("%d", &totNum);
  while (totNum > TAM_MAX) {
    printf ("Quantidade de numeros deve ser menor que %d\n", TAM_MAX);
    printf ("Quantos numeros? ");
    scanf ("%d", &totNum);
  }
  printf ("\n");
  for (iNum = 0; iNum < totNum; iNum++) {
    printf ("Numero %2d? ", iNum+1);
    scanf ("%d", &numeros[iNum]);
  }
  printf ("\n");
}

int comparaInteiros (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

void ordenaNumeros (void) {
  qsort (numeros, totNum, sizeof (int), comparaInteiros);
}

float calculaMedia (void) {
  int
    iNum,
    soma;
  for (iNum = soma = 0; iNum < totNum; iNum++)
    soma += numeros[iNum];
  return ((float) soma / totNum);
}

int main (void) {
  int
    iNum,
    freqMax,
    posFreqMax,
    repetFreqMax,
    moda,
    totDistintos,
    distintos   [TAM_MAX],
    frequencias [TAM_MAX];
  float
    media   = 0.0,
    mediana = 0.0;
  bool
    bModaDefinida = false;

  /* Leitura dos numeros */

  obtemNumeros();

  /* Calculo da media */

  media = calculaMedia();
  printf ("Media: %.2f \n", media);

  /* Calculo da mediana */

  ordenaNumeros();
  if (ehImpar (totNum))
    mediana = (float) numeros [(totNum-1) / 2];
  else
    mediana = (float) (numeros [(totNum/2) - 1] + numeros [totNum/2]) / 2;
  printf ("Mediana: %.2f \n", mediana);

  /* Calculo da moda */

  distintos[0] = numeros[0];
  frequencias[0] = 1;
  totDistintos = 1;
  for (iNum = 1; iNum < TAM_MAX; iNum++)
    distintos[iNum] = frequencias[iNum] = -1;

  for (iNum = 1; iNum < totNum; iNum++) {
    if (distintos[totDistintos-1] == numeros[iNum])
      frequencias[totDistintos-1]++;
    else {
      totDistintos++;
      distintos[totDistintos-1] = numeros[iNum];
      frequencias[totDistintos-1] = 1;
    }
  }

  freqMax = posFreqMax = -1;
  for (iNum = 0; iNum < totDistintos; iNum++)
    if (frequencias[iNum] > freqMax) {
      freqMax = frequencias[iNum];
      posFreqMax = iNum;
    }

  for (iNum = repetFreqMax = 0; iNum < totDistintos; iNum++)
    if (frequencias[iNum] == freqMax)
      repetFreqMax++;

  bModaDefinida = (repetFreqMax == 1);

  if (bModaDefinida) {
    moda = distintos [posFreqMax];
    printf ("Moda: %d \n", moda);
  }
  else
    printf ("Moda indefinida \n");

  printf ("\n");
  system ("PAUSE");
  return 0;
}
