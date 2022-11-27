#include "heal.hpp"

Heal::Heal(){
    this->tipo = "cura";
    this-> cura = 30;
}
Heal::~Heal(){

}

int Heal::operator*(int qtd){
    return this->cura*qtd;
}