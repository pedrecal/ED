#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_MAX_PALAVRA 100

char
  palavra [TAM_MAX_PALAVRA];

struct nodo {
	struct nodo* antes;
	char letra;
	struct nodo* depois;
};

void cadeia2lista (char *cadeia, struct nodo **refPrimeiroNodo, struct nodo **refUltimoNodo) {
  struct nodo
    *novoNodo = NULL;
  while (*cadeia != 0) {
    novoNodo = (struct nodo *) malloc (sizeof (struct nodo));
    if (novoNodo == NULL) {
      printf ("Erro: malloc retornou NULL\n");
      exit (EXIT_FAILURE);
    }
    novoNodo->letra = *(cadeia++);
    novoNodo->depois = NULL;
    if (*refPrimeiroNodo == NULL) {
      *refPrimeiroNodo = *refUltimoNodo = novoNodo;
      (*refPrimeiroNodo)->antes = NULL;
    }
    else {
      (*refUltimoNodo)->depois = novoNodo;
      novoNodo->antes = *refUltimoNodo;
      *refUltimoNodo = novoNodo;
    }
  }
};

void mostraLista (struct nodo *lista) {
  printf ("LISTA:\n");
  printf ("Inicio --> ");
  while (lista != NULL) {
    printf ("%c ", lista->letra);
    lista = lista->depois;
  }
  printf ("<-- Fim\n");
}

void apagaLista (struct nodo **refPrimeiroNodo, struct nodo **refUltimoNodo) {
  struct nodo
    *ptrNodo = *refPrimeiroNodo,
    *ptrProx = NULL;
  while (ptrNodo != NULL) {
    ptrProx = ptrNodo->depois;
    free (ptrNodo);
    ptrNodo = ptrProx;
  }
  *refPrimeiroNodo = *refUltimoNodo = NULL;
}

_Bool ehPalindromo (struct nodo *inicio, struct nodo *fim) {
  if (inicio->letra != fim->letra)
    return (false);
  if (inicio == fim)
    return (true);
  if (inicio->depois == fim)
    return (inicio->letra == fim->letra);
  return (ehPalindromo (inicio->depois, fim->antes));
}

int main()
{
  struct nodo
    *inicioLista = NULL,
    *fimLista = NULL;

  printf ("Digite uma palavra ou 'fim' para sair: ");
  scanf ("%s", palavra);
  while (strcmp (palavra, "fim")) {
    cadeia2lista (palavra, &inicioLista, &fimLista);
    mostraLista (inicioLista);
    printf ("%s %s palindromo\n", palavra, ehPalindromo (inicioLista, fimLista) ? "eh" : "NAO eh");
    apagaLista (&inicioLista, &fimLista);
    printf ("Digite uma palavra ou 'fim' para sair: ");
    scanf ("%s", palavra);
  }
  exit (EXIT_SUCCESS);
}
