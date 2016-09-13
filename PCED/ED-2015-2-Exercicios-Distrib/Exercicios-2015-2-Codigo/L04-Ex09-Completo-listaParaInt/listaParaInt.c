/*
---------------------------------------------------------------------------------------------
  Inclusão condicional de cabeçalhos
---------------------------------------------------------------------------------------------
*/

#ifndef MODULO_COMUM
  #include "comum.h"
#endif

#ifndef MODULO_LISTA
  #include "lista.h"
#endif

/*
 *---------------------------------------------------------------------
 *
 *   IMPLEMENTAÇÃO
 *
 *---------------------------------------------------------------------
 */

/*
---------------------------------------------------------------------------------------------
  Percorre uma lista de dígitos decimais e converte-os num inteiro
---------------------------------------------------------------------------------------------
*/

int listaParaInt (struct nodo *lista) {
  int
    numero = 0;
  while (lista != NULL) {
    numero = numero*10 + lista->dado;
    lista = lista->prox;
  }
  return (numero);
}

/*
---------------------------------------------------------------------------------------------
  main
---------------------------------------------------------------------------------------------
*/

int main (int argc, char *argv[])
{
  int
    totDigitos = 0,
    digito,
    numero;
  struct nodo
    *lista = NULL;

  printf ("Forneca o %do. digito, ou -1 para terminar: ", totDigitos+1);
  scanf ("%d", &digito);
  while (digito>=0) {
    if (digito > 9)
      printf ("Digito invalido, somente entre 0 e 9\n");
    else {
      poeNoFim (&lista, digito);
      totDigitos++;
    }
    printf ("Forneca o %do. digito, ou -1 para terminar: ", totDigitos+1);
    scanf ("%d", &digito);
  }
  numero = listaParaInt (lista);
  printf ("Numero = %d\n", numero);
  system("PAUSE");
  return 0;
}
