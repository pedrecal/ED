#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Tamanho máximo do array de inteiros */

#define TAM_MAX  10000

int A[TAM_MAX];

/* Arrays grandes consumiriam muitas linhas da tela ao serem impressos,   */
/* então vamos imprimir apenas alguns números do início e do fim do array */

#define NROS_INICIAIS 3
#define NROS_FINAIS   3

/* Nro esperado de operações por linha de código, em função de n, no melhor caso */

int T1melhor (int n) {return (2*n+3);}
int T2melhor (int n) {return (n*n+3*n);}
int T3melhor (int n) {return (4*(n*(n-1)/2));}
int T4melhor (int n) {return (0);}
int T5melhor (int n) {return (0);}
int T6melhor (int n) {return (0);}
int TTmelhor (int n) {return (3*n*n+3*n+3);}

/* Nro esperado de operações por linha de código, em função de n, no pior caso */

int T1pior (int n) {return (2*n+3);}
int T2pior (int n) {return (n*n+3*n);}
int T3pior (int n) {return (4*(n*(n-1)/2));}
int T4pior (int n) {return (3*(n*(n-1)/2));}
int T5pior (int n) {return (4*(n*(n-1)/2));}
int T6pior (int n) {return (2*(n*(n-1)/2));}
int TTpior (int n) {return ((15*n*n-3*n+6)/2);}

/* Expressões para o nro esperado de operações por linha de código, em função de n, no melhor caso */

#define T1melhorStr  "2n+3          "
#define T2melhorStr  "n^2+3n        "
#define T3melhorStr  "4n(n-1)/2     "
#define T4melhorStr  "0             "
#define T5melhorStr  "0             "
#define T6melhorStr  "0             "
#define TTmelhorStr  "3n^2+3n+3     "

/* Expressões para o nro esperado de operações por linha de código, em função de n, no pior caso */

#define T1piorStr    "2n+3          "
#define T2piorStr    "n^2+3n        "
#define T3piorStr    "4n(n-1)/2     "
#define T4piorStr    "3n(n-1)/2     "
#define T5piorStr    "4n(n-1)/2     "
#define T6piorStr    "2n(n-1)/2     "
#define TTpiorStr    "(15n^2-3n+6)/2"

/* Total de operações executadas por linha do programa */

long int
  op1, op2, op3, op4, op5, op6;

/* Inicialização dos contadores de operações */

void zeraContadores (void)
{
  op1 = op2 = op3 = op4 = op5 = op6 = 0;
}

/* Inicialização do array em ordem crescente */

void fazArrayCrescente (int A[], int n)
{
  int i;
  for (i=1; i<=n; i++)
    A[i-1] = i;
}

/* Inicialização do array em ordem decrescente */

void fazArrayDecrescente (int A[], int n)
{
  int i;
  for (i=1; i<=n; i++)
    A[i-1] = n-i+1;
}

/* Função que efetua o bubbleSort */

void bubbleSort (int A[], int n)
{
  int
    i, j, temp;

  zeraContadores();

  // op1 = nro de operacoes no laço
  // valor inicial = 3 (1 para i=1, 1 para n-1, 1 para o teste de fim do laço)
  // a cada repeticao do laço, conte mais 2 operacoes (incremento de i e teste)

  for (i=0, op1+=3; i<=n-1; i++, op1+=2) {
    for (j=n-1, op2+=4; j>=i+1; j--, op2+=2) {
      op3+=4;
      if (A[j-1]>A[j]) {
        op4+=3; temp = A[j-1];
        op5+=4; A[j-1] = A[j];
        op6+=2; A[j] = temp;
      }
    }
  }
}

void mostraArray (int A[], int n, char *texto)
{
  int i;
  bool etc = false;

  printf ("%s A = [ ", texto);
  for (i=1; i<=n; i++) {
    if ((i<=NROS_INICIAIS) || ((n-i)<NROS_FINAIS))
      printf ("%d ", A[i-1]);
    else if (! etc) {
      printf ("... ");
      etc = true;
    }
  }
  printf ("]\n");
}

void mostraOperacoes (int n, bool melhorCaso)
{
  int opTot = op1+op2+op3+op4+op5+op6;
  if (melhorCaso) {
    printf ("\n");
    printf ("-----  ------------------------------  --------------  ----- OPERACOES ------ \n");
    printf ("Linha  Codigo                          T(n)            Esperadas   Realizadas \n");
    printf ("-----  ------------------------------  --------------  ----------  ---------- \n");
    printf ("  1    for (i=0; i<=n-1; i++) {        %s  %10d  %10d \n", T1melhorStr, T1melhor(n), op1);
    printf ("  2      for (j=n-1; j>=i+1; j--) {    %s  %10d  %10d \n", T2melhorStr, T2melhor(n), op2);
    printf ("  3        if (A[j-1] > A[j]) {        %s  %10d  %10d \n", T3melhorStr, T3melhor(n), op3);
    printf ("  4          temp = A[j-1];            %s  %10d  %10d \n", T4melhorStr, T4melhor(n), op4);
    printf ("  5          A[j-1] = A[j];            %s  %10d  %10d \n", T5melhorStr, T5melhor(n), op5);
    printf ("  6          A[j] = temp; }}}          %s  %10d  %10d \n", T6melhorStr, T6melhor(n), op6);
    printf ("-----  ------------------------------  --------------  ----------  ---------- \n");
    printf ("                                TOTAL  %s  %10d  %10d \n\n", TTmelhorStr, TTmelhor(n), opTot);
  }
  else {
    printf ("\n");
    printf ("-----  ------------------------------  --------------  ----- OPERACOES ------ \n");
    printf ("Linha  Codigo                          T(n)            Esperadas   Realizadas \n");
    printf ("-----  ------------------------------  --------------  ----------  ---------- \n");
    printf ("  1    for (i=0; i<=n-1; i++) {        %s  %10d  %10d \n", T1piorStr, T1pior(n), op1);
    printf ("  2      for (j=n-1; j>=i+1; j--) {    %s  %10d  %10d \n", T2piorStr, T2pior(n), op2);
    printf ("  3        if (A[j-1] > A[j]) {        %s  %10d  %10d \n", T3piorStr, T3pior(n), op3);
    printf ("  4          temp = A[j-1];            %s  %10d  %10d \n", T4piorStr, T4pior(n), op4);
    printf ("  5          A[j-1] = A[j];            %s  %10d  %10d \n", T5piorStr, T5pior(n), op5);
    printf ("  6          A[j] = temp; }}}          %s  %10d  %10d \n", T6piorStr, T6pior(n), op6);
    printf ("-----  ------------------------------  --------------  ----------  ---------- \n");
    printf ("                                TOTAL  %s  %10d  %10d \n\n", TTpiorStr, TTpior(n), opTot);
  }
}

int main(int argc, char *argv[])
{
  int  n;
  char ordem;
  bool melhorCaso;

  printf ("BUBBLE SORT \n\n");
  printf ("Tamanho do array [1 a %d | 0 para sair]: ", TAM_MAX);
  scanf (" %d", &n);
  while ((n >= 1) && (n <= TAM_MAX)) {
    printf ("\nInicializar em ordem crescente ou decrescente [c|d|s=sair]? ");
    scanf (" %c", &ordem);
    while (! (ordem == 'c' || ordem == 'd' || ordem == 's')) {
      printf ("Opcao invalida \n");
      printf ("\nInicializar em ordem crescente ou decrescente [c|d|s=sair]? ");
      scanf (" %c", &ordem);
    }
    if (ordem == 's')
      break;
    if (ordem == 'c') {
	  melhorCaso = true;
      printf ("\n\nMELHOR CASO: Array em ordem crescente \n");
      fazArrayCrescente (A, n);
    } else {
	  melhorCaso = false;
      printf ("\n\nPIOR CASO: Array em ordem decrescente \n");
      fazArrayDecrescente (A, n);
    }
    mostraArray (A, n, " Antes da ordenacao: ");
    bubbleSort  (A, n);
    mostraArray (A, n, "Depois da ordenacao: ");
    mostraOperacoes (n, melhorCaso);

  printf ("Tamanho do array [1 a %d | 0 para sair]: ", TAM_MAX);
    scanf (" %d", &n);
  }
  //system("PAUSE");
  return 0;
}
