#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 12
#define NRO_INICIAL 33
#define VALOR_POS_VAZIA -1

int
  A[N],      /* Array de inteiros que implementa as pilhas, sendo que:     */
             /*   A[0]   contém o índice em A do numero no topo da pilha 1 */
             /*   A[N-1] contém o índice em A do numero no topo da pilha 2 */
  nroAtual;  /* Número que será empilhado a seguir                         */

#define TOPO1 (A[0])
#define TOPO2 (A[N-1])

void emiteErro (char *mensagem) {
  printf ("ERRO %s\n", mensagem);
}

int conteudoVetor(int pos) {
  return ((pos > TOPO1) && (pos < TOPO2) ? VALOR_POS_VAZIA : A[pos]);
}

void esvazia (void) {
  int
    iPos;
  for (iPos=0; iPos<N; iPos++)
    A[iPos]=VALOR_POS_VAZIA;
  TOPO1 = 0;
  TOPO2 = N-1;
  nroAtual = NRO_INICIAL;
}

bool vazia (int pilha) {
  switch (pilha) {
    case (1): return (TOPO1==0);
    case (2): return (TOPO2==N-1);
    default :
      emiteErro ("em vazia(): Pilha invalida");
      return (false);
  }
}

int tamanho (int pilha) {
  switch (pilha) {
    case (1): return (TOPO1);
    case (2): return (N-1-TOPO2);
    default :
      emiteErro ("em tamanho(): Pilha invalida");
      return (VALOR_POS_VAZIA);
  }
}

bool cheias (void) {
  return ((TOPO2-TOPO1)==1);
}

void empilha (int pilha, int n) {
  switch (pilha) {
    case (1): {
      if (cheias())
        emiteErro ("em empilha(): Pilhas cheias");
      else
        A[++TOPO1]=n;
      return;
    }
    case (2): {
      if (cheias())
        emiteErro ("em empilha(): Pilhas cheias");
      else
        A[--TOPO2]=n;
      return;
    }
    default:
      emiteErro ("em empilha(): Pilha invalida");
  }
}

int desempilha (int pilha) {
  switch (pilha) {
    case (1): {
      if (vazia(1)) {
        emiteErro ("em desempilha(): Pilha 1 vazia");
        return (VALOR_POS_VAZIA);
      }
      else
        return A[TOPO1--];
    }
    case (2): {
      if (vazia(2)) {
        emiteErro ("em desempilha(): Pilha 2 vazia");
        return (VALOR_POS_VAZIA);
      }
      else
        return A[TOPO2++];
    }
    default:
      emiteErro ("em desempilha(): Pilha invalida");
      return (VALOR_POS_VAZIA);
  }
}

int topo (int pilha) {
  switch (pilha) {
    case (1): {
      if (vazia(1)) {
        emiteErro ("em topo(): Pilha 1 vazia");
        return (VALOR_POS_VAZIA);
      }
      else
        return A[TOPO1];
    }
    case (2): {
      if (vazia(2)) {
        emiteErro ("em topo(): Pilha 2 vazia");
        return (VALOR_POS_VAZIA);
      }
      else
        return A[TOPO2];
    }
    default:
      emiteErro ("em topo(): Pilha invalida");
      return (VALOR_POS_VAZIA);
  }
}

bool opValida (char op) {
  return (                         /* Como o usuário seleciona uma ação:  */
    (op == 'e') || (op == 'E') ||  /*   - Empilhar                        */
    (op == 'd') || (op == 'D') ||  /*   - Desempilhar                     */
    (op == 't') || (op == 'T') ||  /*   - Consultar o topo da pilha       */
    (op == 'm') || (op == 'M') ||  /*   - Obter o tamanho da pilha        */
    (op == 'v') || (op == 'V') ||  /*   - Saber se a pilha está vazia     */
    (op == 'c') || (op == 'C') ||  /*   - Saber se as pilhas estão cheias */
    (op == 'z') || (op == 'Z') ||  /*   - Zerar as pilhas                 */
    (op == 's') || (op == 'S')     /*   - Sair do programa                */
  );
}

int main()
{
  char
    op[10];
  int
    iPos,
    n;
  bool
    podeContinuar = true;

  esvazia();
  while (podeContinuar) {
    iPos = N-1;
    printf("\n");
    printf("   Pilha 2    Operacoes disponiveis:\n");
    printf("   +-----+\n");
    printf("%2d | %3d |    [e] Empilhar %d na pilha 1    [E] Empilhar %d na pilha 2\n", iPos, conteudoVetor(iPos), nroAtual, nroAtual); iPos--;
    printf("%2d | %3d |    [d] Desempilhar da pilha 1    [D] Desempilhar da pilha 2\n", iPos, conteudoVetor(iPos)); iPos--;
    printf("%2d | %3d |    [t] Topo da pilha 1           [T] Topo da pilha 2       \n", iPos, conteudoVetor(iPos)); iPos--;
    printf("%2d | %3d |    [m] Tamanho da pilha 1        [M] Tamanho da pilha 2    \n", iPos, conteudoVetor(iPos)); iPos--;
    printf("%2d | %3d |    [v] Pilha 1 vazia?            [V] Pilha 2 vazia?        \n", iPos, conteudoVetor(iPos)); iPos--;
    printf("%2d | %3d |    [c] Pilhas cheias?            [z] Zerar as pilhas       \n", iPos, conteudoVetor(iPos)); iPos--;
    printf("%2d | %3d |    [s] Sair                                                \n", iPos, conteudoVetor(iPos)); iPos--;
    for ( ; iPos >= 0; ) {
      printf("%2d | %3d |\n", iPos, conteudoVetor(iPos));
      iPos--;
    }
    printf("   +-----+\n");
    printf("   Pilha 1\n");
    printf ("\n");
    strcpy (op, "");
    printf("Qual operacao deseja realizar?\n");
    scanf ("%s", op);
    while (! opValida(op[0])) {
      printf("Operacao invalida.\n");
      printf("Qual operacao deseja realizar?\n");
      scanf ("%s", op);
    }
    switch (op[0]) {
      case 's':
      case 'S':
        podeContinuar = false;
        break;
      case 'e':
        printf ("Tentando empilhar %d na pilha 1\n", nroAtual);
        empilha (1, nroAtual++);
        printf ("Sucesso ao empilhar %d na pilha 1\n", nroAtual-1);
        break;
      case 'E':
        printf ("Tentando empilhar %d na pilha 2\n", nroAtual);
        empilha (2, nroAtual++);
        printf ("Sucesso ao empilhar %d na pilha 2\n", nroAtual-1);
        break;
      case 'd':
        printf ("Tentando desempilhar da pilha 1\n");
        n = desempilha (1);
        if (n == VALOR_POS_VAZIA)
          printf ("Erro ao desempilhar da pilha 1\n");
        else
          printf ("Sucesso ao desempilhar %d da pilha 1\n", n);
        break;
      case 'D':
        printf ("Tentando desempilhar da pilha 2\n");
        n = desempilha (2);
        if (n == VALOR_POS_VAZIA)
          printf ("Erro ao desempilhar da pilha 2\n");
        else
          printf ("Sucesso ao desempilhar %d da pilha 2\n", n);
        break;
      case 't':
        printf ("Tentando consultar o topo da pilha 1\n");
        n = topo (1);
        if (n == VALOR_POS_VAZIA)
          printf ("Erro ao consultar o topo da pilha 1\n");
        else
          printf ("Sucesso na consulta: %d no topo da pilha 1\n", n);
        break;
      case 'T':
        printf ("Tentando consultar o topo da pilha 2\n");
        n = topo (2);
        if (n == VALOR_POS_VAZIA)
          printf ("Erro ao consultar o topo da pilha 2\n");
        else
          printf ("Sucesso na consulta: %d no topo da pilha 2\n", n);
        break;
      case 'm':
        printf ("%d numeros na pilha 1\n", tamanho (1));
        break;
      case 'M':
        printf ("%d numeros na pilha 2\n", tamanho (2));
        break;
      case 'v':
        printf ("Pilha 1 vazia? %s\n", vazia (1) ? "Sim" : "Nao");
        break;
      case 'V':
        printf ("Pilha 2 vazia? %s\n", vazia (2) ? "Sim" : "Nao");
        break;
      case 'c':
      case 'C':
        printf ("Pilhas cheias? %s\n", cheias() ? "Sim" : "Nao");
        break;
      case 'z':
      case 'Z':
        esvazia();
        break;
    }
  }
  return (EXIT_SUCCESS);
}
