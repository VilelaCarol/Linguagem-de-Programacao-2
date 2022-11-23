#include "banco.hpp"
#include <iostream>
#include <string>

using namespace std;

Usuario::Usuario(){
    this->saldo=0;
}

Usuario::Usuario(string nome, string numero, float saldo){
    this->nome = nome;
    this->numeroDaConta = numero;
    this->saldo = saldo;
}
float Usuario::getSaldo(){
    return this->saldo;
}
void Usuario::deposito(float valor){
    this->saldo = this->saldo+valor;
}
string Usuario::getNumeroDaConta(){
    return this->numeroDaConta;
}
void Usuario::setNumeroDaConta(string numero){
    this->numeroDaConta = numero;
}
bool Usuario::saque(float valor){
    if (valor<= this->saldo){
        this->saldo = this->saldo - valor;
        return true; 
    }
    return false;
}