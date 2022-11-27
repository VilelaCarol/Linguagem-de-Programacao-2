#include "bag.hpp"
#include"item.hpp"
#include <iostream>
#include <vector>
#include "poison.hpp"
#include "heal.hpp"
using namespace std;


Bag::Bag(){
    //cout<< "construindo bag"<< endl;
}
Bag::~Bag(){
    //cout<< "destruindo bag"<< endl;
    for(int i=0; i<this->listaDeVeneno.size(); i++){
        delete this->listaDeVeneno.at(i);
    }
     for(int i=0; i<this->listaDeCura.size(); i++){
        delete this->listaDeCura.at(i);
    }

}

void Bag::printItens(){
    //vou andar pelo vetor de itens e contar quantos itens de cada tipo ele possui
    //então vou printar a quantidade de cada um
    int qtdPoison = this->listaDeVeneno.size();
    int qtdHeal = this->listaDeCura.size();
    cout<< "Quantidade de veneno: "<< qtdPoison<<endl;
    cout<< "Quantidade de cura: "<< qtdHeal<<endl;

}

vector<Item*> Bag::getItens(){
    vector<Item*> listaDeItens;
    for(int i=0; i<this->listaDeVeneno.size(); i++){
        listaDeItens.push_back(this->listaDeVeneno.at(i));
    }
     for(int i=0; i<this->listaDeCura.size(); i++){
        listaDeItens.push_back(this->listaDeCura.at(i));
    }
    return listaDeItens;
}

void Bag::colocarItem(Item* novoItem){
    if(novoItem->tipo == "veneno"){
        this->colocarItem((Poison*)novoItem);
    }
    else if(novoItem->tipo == "cura"){
        this->colocarItem((Heal*)novoItem);
    }
}
void Bag::colocarItem(Poison* novoItem){
    this->listaDeVeneno.push_back(novoItem);
}
void Bag::colocarItem(Heal* novoItem){
    this->listaDeCura.push_back(novoItem);
}
bool Bag::tirarItem(string tipo, int quantidade){
    if( tipo=="veneno"){
        if(this->listaDeVeneno.size()<quantidade){
            return false;
        }
        for (int i=0; i<quantidade; i++){
            delete this->listaDeVeneno.at(this->listaDeVeneno.size()-1);
        this->listaDeVeneno.pop_back();
        }
    }
    if(tipo=="cura"){
        if(this-> listaDeCura.size()<quantidade){
            return false;
        }
        for(int i=0; i<quantidade; i++){
            delete this->listaDeCura.at(this->listaDeCura.size()-1);
        this->listaDeCura.pop_back();
        }
    }
    return true;

    
}
void Bag::operator<<(Item* novoItem){
    this->colocarItem(novoItem);
}
