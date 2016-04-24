#include <iostream>

using namespace std;

typedef struct tipo
{
  int num;
  struct tipo *prox;

}tipo_t;

void first(tipo_t * a, tipo_t * head)
{
  a = head;
}

void last(tipo_t * a)
{
  while ((a -> prox) != NULL)
  {
    a = a -> prox;
  }
}

void ant(tipo_t * head, tipo_t * a)
{
  tipo_t * p;
  p = head;
  while ((p -> prox) != a)
  {
    p = p -> prox;
  }

  a = p;

  delete p;
}

void succ(tipo_t * a)
{
  a = a -> prox;
}

int main(int argc, char const *argv[])
{
  tipo_t *first;

  first = new tipo_t;




  return 0;
}
