#include <iostream>

using namespace std;

typedef struct pilha
{
    int obj;
    struct pilha *last = NULL;
}t_pilha;

void push (int obj, t_pilha *&head)
{
    t_pilha *p1 =  new t_pilha;
    p1->obj = obj;
    p1->last = head;
    head =  p1;
}

int pop (t_pilha *&head)
{
    t_pilha *p2 = head;
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
    pop(topo);

    while (topo->last != NULL)
    {
        std::cout << topo->obj << std::endl;
        topo = topo->last;
    }

    return 0;
}
