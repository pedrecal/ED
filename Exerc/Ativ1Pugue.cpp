// g++ Slide1-atv1.cpp -o Slide1-atv1.o
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct complexo
{
    int real, imag;

    complexo& operator=(const complexo& num)
    {
        real = num.real;
        imag = num.imag;
        return *this;
    }

    complexo operator+(const complexo& num)
    {
        complexo sum;
        sum.real = real + num.real;
        sum.imag = imag + num.imag;

        return sum;
    }

    complexo operator*(const complexo& num)
    {
        complexo multi;
        multi.real = ((real * num.real) - (imag * num.imag));
        multi.imag = ((real * num.imag) + (imag * num.real));

        return multi;
    }

} complexo_t;

void soma(complexo_t num1, complexo_t num2, complexo_t *soma)
{
    soma->real = num1.real + num2.real;
    soma->imag = num1.imag + num2.imag;
}

double escalar(complexo_t num1, complexo_t num2)
{
    return (num1.real * num2.real) + (num1.imag * num2.imag);
}

double modulo(complexo_t num)
{
    return sqrt(pow(2, num.real) + pow(2, num.imag));
}

// Lista 1 - Q 2
void produto(complexo_t num1, complexo_t num2, complexo_t *produto)
{
    produto->real = ((num1.real * num2.real) - (num1.imag * num2.imag));
    produto->imag = ((num1.real * num2.imag) + (num1.imag * num2.real));
}

void quadrado(complexo_t num, complexo_t *quadrado)
{
    *quadrado = num * num;
    //produto(num, num, quadrado);
}

// 0 -> n1 == n2
// -1 -> n1 > n2
// 1 -> n1 < n2
// Slide 2
int compare(const void * num1, const void * num2)
{
    double n1 = modulo(*(complexo_t*)num1);
    double n2 = modulo(*(complexo_t*)num2);

    return n1 - n2;
}

int main(int argc, char const *argv[]) {

    int opt, tam;
    double escal, mod;
    complexo_t num1, num2, s, prod, quad, *vComplexo;

    do {
        system("clear");
        cout << "Calculadora de Numeros Complexos" << endl;
        cout << "<1> Soma" << endl << "<2> Escalar" << endl << "<3> Modulo" << endl;
        cout << "<4> Produto" << endl << "<5> Quadrado" << endl << "<6> Ordenar" << endl << "<0> Sair" << endl;
        cout << endl << "Escolha uma opcao: ";
        cin >> opt;
        switch (opt) {
            case 0: break;

            case 1: system("clear");
                    cout << "Digite o Num Complexo 1: " << endl << "real: ";
                    cin >> num1.real;
                    cout << "imag: ";
                    cin >> num1.imag;
                    cout << "Digite o Num Complexo 2: " << endl << "real: ";
                    cin >> num2.real;
                    cout << "imag: ";
                    cin >> num2.imag;

                    soma(num1, num2, &s);

                    cout << endl << "Resultado: " << s.real << " + " << s.imag << "i" << endl << endl;

                    cin.ignore(1024, '\n');
                    cout << "Pressione ENTER para voltar ao menu...";
                    cin.get();
                    break;

            case 2: system("clear");
                    cout << "Digite o Num Complexo 1: " << endl << "real: ";
                    cin >> num1.real;
                    cout << "imag: ";
                    cin >> num1.imag;
                    cout << "Digite o Num Complexo 2: " << endl << "real: ";
                    cin >> num2.real;
                    cout << "imag: ";
                    cin >> num2.imag;

                    escal = escalar(num1, num2);

                    cout << endl << "Resultado: " << escal << endl << endl;

                    cin.ignore(1024, '\n');
                    cout << "Pressione ENTER para voltar ao menu...";
                    cin.get();
                    break;

            case 3: system("clear");
                    cout << "Digite o Num Complexo: " << endl << "real: ";
                    cin >> num1.real;
                    cout << "imag: ";
                    cin >> num1.imag;

                    mod = modulo(num1);

                    cout << endl << "Resultado: " << mod << endl << endl;

                    cin.ignore(1024, '\n');
                    cout << "Pressione ENTER para voltar ao menu...";
                    cin.get();
                    break;

            case 4: system("clear");
                    cout << "Digite o Num Complexo 1: " << endl << "real: ";
                    cin >> num1.real;
                    cout << "imag: ";
                    cin >> num1.imag;
                    cout << "Digite o Num Complexo 2: " << endl << "real: ";
                    cin >> num2.real;
                    cout << "imag: ";
                    cin >> num2.imag;

                    //produto(num1, num2, &prod);
                    prod = num1 * num2;

                    cout << endl << "Resultado: " << prod.real << " + " << prod.imag << "i" << endl << endl;

                    cin.ignore(1024, '\n');
                    cout << "Pressione ENTER para voltar ao menu...";
                    cin.get();
                    break;

            case 5: system("clear");
                    cout << "Digite o Num Complexo: " << endl << "real: ";
                    cin >> num1.real;
                    cout << "imag: ";
                    cin >> num1.imag;

                    quadrado(num1, &quad);

                    cout << endl << "Resultado: " << quad.real << " + " << quad.imag << "i" << endl << endl;

                    cin.ignore(1024, '\n');
                    cout << "Pressione ENTER para voltar ao menu...";
                    cin.get();
                    break;

            case 6: system("clear");
                    cout << "Digite o numero de elementos do vetor de Num Complexo: ";
                    cin >> tam;
                    vComplexo = new complexo_t[tam];
                    for(int i = 0; i < tam; i++)
                    {
                        cout << endl << "Posicao " << i+1 << ":" << endl << "real: ";
                        cin >> vComplexo[i].real;
                        cout << "imag: ";
                        cin >> vComplexo[i].imag;
                    }
                    qsort(vComplexo, tam, sizeof(complexo_t), compare);

                    for(int i = 0; i < tam; i++)
                        cout << vComplexo[i].real << " " << vComplexo[i].imag << "i ";

                    cin.ignore(1024, '\n');
                    cout << endl << "Pressione ENTER para voltar ao menu...";
                    cin.get();
                    break;

            default: cout << "Opcao Invalida!!" << endl;
        }
    } while(opt != 0);
    return 0;
}
