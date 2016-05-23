/*
 * listaDE.hpp
 * Cria um lista duplamente encadeada
 * O elemento da estrutura está em aberto.
 */

/**
 * @author Hamilton J. Brumatto
 */

template<class T>
class ListaDE {
  private:
    T obj;
    ListaDE *prox, *ant;

  public:
    ListaDE(T obj); // Cria uma lista com um único objeto, inicialmente sem vizinhos.
    bool inserirAntes(ListaDE *&head, T obj, ListaDE *&tail); //Insere um elemento obj à esquerda deste.
    bool inserirApos(ListaDE *&head, T obj, ListaDE *&tail); //Insere um elemento obj à direita deste.
    bool remover(ListaDE *&head, ListaDE *&tail); //Remove este obj da lista.
    bool troca(ListaDE *&head, ListaDE *obj, ListaDE *&tail); // Troca a posição deste objeto com outro na lista.
    T getObj(); // Retorna o objeto inserido na lista
    ListaDE *getProx(); // Retorna o próximo objeto na lista
    ListaDE *getAnt(); // Retorna o objeto anterior na lista
};

// Implementação da classe. Precisa estar no .hpp por conta do template.


template<class T>
ListaDE<T>::ListaDE(T obj) {
  this->obj = obj;
  prox = NULL;
  ant = NULL;
}

template<class T>
bool ListaDE<T>::inserirAntes(ListaDE *&head, T obj, ListaDE *&tail) {
  bool ret = false;
  ListaDE *novo = new ListaDE(obj);
  if(novo != NULL) {
    novo->prox = this;
    if(this==head) {
      head = novo;
    } else {
      this->ant->prox = novo;
      novo->ant = this->ant;
    }
    this->ant = novo;
    ret = true;
  }
  return ret;
}

template<class T>
bool ListaDE<T>::inserirApos(ListaDE *&head, T obj, ListaDE *&tail) {
  bool ret = false;
  ListaDE *novo = new ListaDE(obj);
  if(novo != NULL) {
    novo->ant = this;
    if(this==tail) {
      tail = novo;
    } else {
      this->prox->ant = novo;
      novo->prox = this->prox;
    }
    this->prox = novo;
    ret = true;
  }
  return ret;
}


template<class T>
bool ListaDE<T>::remover(ListaDE *&head, ListaDE *&tail) {
  bool ret = false;
  if(head == this && tail == this {
    head = NULL;
    tail = NULL;
  } else {
    if(head == this) {
      head = this->prox;
      this->prox->ant = NULL;
    } else {
      this->ant->prox = this->prox;
      this->prox->ant = this->ant;
    }
    if(tail == this) {
      tail = this->ant;
      this->ant->prox = NULL;
    } else {
      this->prox->ant = this->ant;
      this->ant->prox = this->prox;
    }
  }
  ret = true;
  delete this;
  return ret;
}

template<class T>
bool ListaDE<T>::troca(ListaDE *&head, ListaDE *obj, ListaDE *&tail) {
  bool ret = false;

  // Esta é a tarefa para vocês: implementar um método que fará a troca de dois elementos quaisquer

  return ret;
}

template<class T>
ListaDE<T> *ListaDE<T>::getProx() {
  return prox;
}

template<class T>
ListaDE<T> *ListaDE<T>::getAnt() {
  return ant;
}

template<class T>
T ListaDE<T>::getObj() {
  return obj;
}
