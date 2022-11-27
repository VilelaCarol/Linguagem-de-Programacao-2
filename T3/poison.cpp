#include "poison.hpp"

Poison::Poison(){
    this->tipo = "veneno";
    this->dano = 20;
}

Poison::~Poison(){

}
int Poison::operator*(int qtd){
    return this->dano*qtd;
}