/*
 * Racional.h
 */

/**
 * @author Hamilton J. Brumatto
 */

class Racional {
  private:
     int num, den;
     void reduz(); // reduz a fração a um conjunto num,den sem divisores em comum;
     
  public:
     Racional(); // cria um número racional 0/1]
     Racional(int num, int den); // cria um número racional num/den
     int getNum(); // retorna o valor do numerador 
     int getDen(); // retorna o valor do denominador
     Racional operator=(Racional rop); // operação =, atualiza e retorna o resultado da operação
     Racional operator+(); // operação unária +, retorna este número.
     Racional operator-(); // operação unária -, retorna o negativo
     Racional operator+(Racional sop); // operação +, não atualiza apenas retorna a soma
     Racional operator-(Racional sop); // operação -, não atualiza apenas retorna a diferença
     Racional operator*(Racional sop); // operação *, não atualiza apenas retorna o produto
     Racional operator/(Racional sop); // operação /, não atualiza apenas retorna a divisão
     bool operator>(Racional sop); // retorna se este é maior que sop
     bool operator>=(Racional sop); // retorna se este é maior que ou igual a sop
     bool operator<(Racional sop); // retorna se este é menor que sop
     bool operator<=(Racional sop); // retorna se este é menor que ou igual a sop
     bool operator==(Racional sop); // retorna se este é igual a sop
     bool operator!=(Racional sop); // retorna se este é diferente de sop
};
