#include <iostream>

using namespace std;

#define TAM 100

class fila
{
private:
  int A[TAM];
  int inicio, fim;

public:
  fila()
  {
    inicio = -1;
    fim = -1;
  }

  bool ehvazia()
  {
    return (inicio == -1 && fim == -1);
  }

  bool ehcheia()
  {
    return (fim + 1)%TAM == inicio ? true : false;
  }

  void enfileirar(int x)
  {
    std::cout << "Enfileirando" << x << std::endl;
    if (ehcheia())
    {
      std::cout << "ERRO. FILA CHEIA" << std::endl;
    }
    if (ehvazia())
    {
      inicio = fim = 0;
    }
    else
    {
      fim = (fim + 1) % TAM;
    }
    A[fim] = x;
  }

  void desenfileirar()
  {
    std::cout << "Desenfileirando" << std::endl;
    if (ehvazia())
    {
      std::cout << "ERRO, FILA VAZIA" << std::endl;
      return;
    }
    else if(inicio == fim)
    {
      inicio = fim = -1;
    }
    else
    {
      inicio = (inicio + 1) % TAM;
    }
  }

  int Inicio()
  {
    if(inicio == -1)
    {
      std::cout << "Fila Vazia" << std::endl;
      return -1;
    }
    return A[inicio];
  }

  //TESTAR
  void print()
  {
    int count = (fim + TAM - inicio) % TAM + 1;
    std::cout << "FIla:";
    for (int i = 0; i < count; i++)
    {
      int index = (inicio + i) % TAM;
      cout <<A[index]<< " ";
    }
     cout << "\n\n";
  }
};




int main(int argc, char const *argv[])
{
  fila f;
  f.enfileirar(2);
  f.print();
  f.enfileirar(5);
  f.print();
  f.enfileirar(6);
  f.print();
  f.desenfileirar();
  f.print();
  return 0;
}
