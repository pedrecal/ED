#include <iostream>

using namespace std;

typedef struct pilha//Strct para pilha de inteiros
{
    int obj;//Obj da pilha
    struct pilha *last = NULL;//Ponteiro para prox elemento
}t_pilha;

void push (int obj, t_pilha *&head)//Função que recebe um inteiro e aponta o ponteiro para a cabeça
{
    t_pilha *p1 =  new t_pilha;//cria elemento da pilha
    p1->obj = obj;//Objeto dessa pilha é igual a obj
    p1->last = head;//ultimo elemento, que é o primeiro, é a cabeça
    head =  p1;
}

int pop (t_pilha *&head)//retira o ultimo empilhado
{
    t_pilha *p2 = head;//novo ponteiro para cabeça
    head = head->last;
    return p2->obj;
}

int main(int argc, char const *argv[])
{
    t_pilha *pilha = new t_pilha;
    t_pilha *topo = pilha;

    pilha->obj = 5;
    push(8, topo);
    push(7, topo);
    push(9, topo);
    //pop(topo);

    while (topo->last != NULL)
    {
        std::cout << topo->obj << std::endl;
        topo = topo->last;
    }

    return 0;
}
