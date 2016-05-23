/*
 * Racional.h
 */

/**
 * @author Hamilton J. Brumatto
 */

class Complexo {
  private:
     double real, imag;
     
  public:
     Complexo(); // cria um número complexo 0+0i
     Complexo(double real, double imag); // cria um número complexo real+i.imag
     double getReal(); // retorna o valor da componente real
     double getImag(); // retorna o valor da componente imaginaria
     Complexo operator=(Complexo rop); // operação =, atualiza e retorna o resultado da operação
     Complexo operator+(); // operação unária, retorna este complexo
     Complexo operator-(); // operação unária, retorna o complexo negativado
     Complexo operator+(Complexo sop); // operação +, não atualiza apenas retorna a soma
     Complexo operator-(Complexo sop); // operação -, não atualiza apenas retorna a diferença
     Complexo operator*(Complexo sop); // operação *, não atualiza apenas retorna o produto
     Complexo operator/(Complexo sop); // operação /, não atualiza apenas retorna a divisão
     double modulo(); // operação que retorna o módulo deste complexo.
};
