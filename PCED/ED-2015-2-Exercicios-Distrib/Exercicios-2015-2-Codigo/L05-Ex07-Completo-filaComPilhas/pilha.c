/*
 *---------------------------------------------------------------------
 *
 * Name: pilha.c
 * Author: Paulo Costa
 * Date: 30/01/08 02:13
 * Description:
 *   Implementa pilhas atrav�s de arrays circulares.
 *   Essas pilhas ser�o utilizadas na implementa��o da fila.
 *
 *---------------------------------------------------------------------
 */

/*
 *---------------------------------------------------------------------
 *   Inclus�o condicional de cabe�alhos
 *---------------------------------------------------------------------
 */

#ifndef MODULO_COMUM
  #include "comum.h"
#endif

#ifndef MODULO_PILHA
  #include "pilha.h"
#endif

/*
 *---------------------------------------------------------------------
 *
 *   INTERFACE (vis�vel por outros m�dulos)
 *
 *---------------------------------------------------------------------
 */

/*
 *-------------------------------------------------------------------
 * Prot�tipos de fun��es
 *-------------------------------------------------------------------
 */

void  poePilha    (int numPilha, tDado dado);
tDado tiraPilha   (int numPilha);

tDado topoPilha   (int numPilha);
int   tamPilha    (int numPilha);
bool  pilhaVazia  (int numPilha);

void  zeraPilha   (int numPilha);
void  mostraPilha (int numPilha);

/*
 *---------------------------------------------------------------------
 *
 *   IMPLEMENTA��O (invis�vel para outros m�dulos)
 *
 *---------------------------------------------------------------------
 */

static tDado
  arrayPilha [TOT_PILHAS][TAM_MAX];

/* Onde, no arrayPilha, a pilha come�a e termina */

static int
  inicio_pilha [TOT_PILHAS],  /* Posi��es em arrayPilha dos in�cios das pilhas */
  fim_pilha    [TOT_PILHAS],  /* Posi��es em arrayPilha dos finais das pilhas  */
  tam_pilha    [TOT_PILHAS];  /* N�meros de elementos nas pilhas               */

/* Controle de underflow e overflow */

static bool
  bPilhaVazia [TOT_PILHAS],  /* Indicam se as pilhas est�o vazias */
  bPilhaCheia [TOT_PILHAS];  /* Indicam se as pilhas est�o cheias */

/*
 *-------------------------------------------------------------------
 * Prot�tipos de fun��es
 *-------------------------------------------------------------------
 */

static void limpaArrayPilha  (int numPilha, tDado dadoNulo);
static void mostraArrayPilha (int numPilha);

/*
 * Inicializa arrayPilha com valor especial que n�o representa dado real
 *
 */

static void limpaArrayPilha (int numPilha, tDado dadoNulo)
{
  int
    pos;

  if ((numPilha < 0) || (numPilha >= TOT_PILHAS))
    emiteErro (erroPilhaInexistente);
  for (pos = 0; pos < TAM_MAX; pos++)
    arrayPilha[numPilha][pos] = DADO_NULO;
}

/*
 * Mostra o conte�do do arrayPilha na sa�da padr�o e no arquivo de sa�da
 *
 */

static void mostraArrayPilha (int numPilha)
{
  int
    pos;

  if ((numPilha < 0) || (numPilha >= TOT_PILHAS))
    emiteErro (erroPilhaInexistente);
  printf ("  arrayPilha[%d]:  [ ", numPilha);
  for (pos = 0; pos < TAM_MAX; pos++) {
    printf (FORMATO, arrayPilha[numPilha][pos]);
    printf (" ");
  }
  printf ("]\n\n");
}

/*
 * Mostra o conte�do da pilha na sa�da padr�o e no arquivo de sa�da
 *
 */

void mostraPilha (int numPilha)
{
  int
    posArrayPilha,
    posPilha;

  if ((numPilha < 0) || (numPilha >= TOT_PILHAS))
    emiteErro (erroPilhaInexistente);
  printf ("\n  Pilha %d de tamanho %2d\n", numPilha, tam_pilha[numPilha]);
  printf ("  inicio -> ");
  for (posPilha = 1, posArrayPilha = inicio_pilha[numPilha]; posPilha <= tam_pilha[numPilha]; posPilha++, posArrayPilha++) {
    if (posArrayPilha == TAM_MAX)
      posArrayPilha = 0;
    printf (FORMATO, arrayPilha[numPilha][posArrayPilha]);
    printf (" ");
  }
  printf ("<- fim\n");
  mostraArrayPilha (numPilha);
}

/*
 * Insere um dado no topo da pilha
 *
 */

void poePilha (int numPilha, tDado dado)
{
  if ((numPilha < 0) || (numPilha >= TOT_PILHAS))
    emiteErro (erroPilhaInexistente);
  if (bPilhaCheia[numPilha])
    emiteErro (erroPilhaCheia);
  if (bPilhaVazia[numPilha]) {
    inicio_pilha[numPilha] = 0;
    fim_pilha[numPilha] = -1;
    bPilhaVazia[numPilha] = false;
  }
  else if (fim_pilha[numPilha] == TAM_MAX - 1)
    fim_pilha[numPilha] = -1;
  arrayPilha[numPilha][++fim_pilha[numPilha]] = dado;
  tam_pilha[numPilha]++;
  bPilhaVazia[numPilha] = (tam_pilha[numPilha] == 0);
  bPilhaCheia[numPilha] = (tam_pilha[numPilha] == TAM_MAX);

/* Para depura��o apenas

  printf("Pilha %d: inicio=%d, fim=%d, tam=%d, vazia=%d, cheia=%d\n",
    numPilha,
    inicio_pilha[numPilha],
    fim_pilha[numPilha],
    tam_pilha[numPilha],
    bPilhaVazia[numPilha],
    bPilhaCheia[numPilha]);
*/
}

/*
 * Remove um dado do topo da pilha
 *
 */

tDado tiraPilha (int numPilha)
{
  tDado
    dado;

  if ((numPilha < 0) || (numPilha >= TOT_PILHAS))
    emiteErro (erroPilhaInexistente);
  if (bPilhaVazia[numPilha])
    emiteErro (erroPilhaVazia);
  dado = arrayPilha[numPilha][fim_pilha[numPilha]];
  arrayPilha[numPilha][fim_pilha[numPilha]--] = DADO_NULO;
  if (fim_pilha[numPilha] == (inicio_pilha[numPilha] - 1)) {
    inicio_pilha[numPilha] = fim_pilha[numPilha] = -1;
    bPilhaVazia[numPilha] = true;
  }
  else if (fim_pilha[numPilha] == -1)
    fim_pilha[numPilha] = TAM_MAX - 1;
  tam_pilha[numPilha]--;
  bPilhaVazia[numPilha] = (tam_pilha[numPilha] == 0);
  bPilhaCheia[numPilha] = (tam_pilha[numPilha] == TAM_MAX);
  return (dado);
}

/*
 * Retorna o dado no topo da pilha sem remov�-lo
 *
 */

tDado topoPilha (int numPilha)
{
  if ((numPilha < 0) || (numPilha >= TOT_PILHAS))
    emiteErro (erroPilhaInexistente);
  if (bPilhaVazia[numPilha])
    emiteErro (erroPilhaVazia);
  return (arrayPilha[numPilha][fim_pilha[numPilha]]);
}

/*
 * Retorna um booleano indicando se a pilha est� vazia
 *
 */

bool pilhaVazia (int numPilha)
{
  if ((numPilha < 0) || (numPilha >= TOT_PILHAS))
    emiteErro (erroPilhaInexistente);
  return (bPilhaVazia[numPilha]);
}

/*
 * Retorna o n�mero de elementos armazenados na pilha
 *
 */

int tamPilha (int numPilha)
{
  if ((numPilha < 0) || (numPilha >= TOT_PILHAS))
    emiteErro (erroPilhaInexistente);
  return (tam_pilha[numPilha]);
}

/*
 * Remove todo o conte�do de uma pilha e inicializa todo o array com dado nulo
 *
 */

void zeraPilha (int numPilha)
{
  if ((numPilha < 0) || (numPilha >= TOT_PILHAS))
    emiteErro (erroPilhaInexistente);
  limpaArrayPilha (numPilha, DADO_NULO);
  inicio_pilha[numPilha] = -1;    /* Posi��o no arrayPilha do in�cio da pilha */
  fim_pilha[numPilha]    = -1;    /* Posi��o no arrayPilha do fim da pilha    */
  tam_pilha[numPilha]    =  0;    /* N�mero de elementos na pilha             */
  bPilhaVazia[numPilha]  = true;  /* Indica se a pilha est� vazia */
  bPilhaCheia[numPilha]  = false; /* Indica se a pilha est� cheia */
}
