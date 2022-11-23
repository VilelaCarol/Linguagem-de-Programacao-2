#ifndef _banco_
#define _banco_
#include <string>
using namespace std;


class Usuario{
    //atributos
    public: 
        string nome;
    private:
        string numeroDaConta;
        float saldo;


    //metodos
    public:
        Usuario();
        Usuario(string nome, string numero, float saldo);
        float getSaldo();
        void deposito(float valor);
        bool saque(float valor);
        string getNumeroDaConta();
        void setNumeroDaConta(string numero);
};


#endif
