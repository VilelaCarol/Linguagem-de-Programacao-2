#include "player.hpp"
#include <iostream>

using namespace std;

Player::Player()
{
    //cout<< "construtor sem nome" << endl;
    this->hp = 100;
    this->mochila = Bag();
    this->nome = "sem nome";
}

Player::Player(string nome)
{
    //cout<< "construtor com nome" << endl;
    this->nome = nome;
    this->hp = 100;
    this->mochila = Bag();
}
Player::~Player(){
    //cout<< "Deletando player "<< this->nome<<endl;
}
string Player::getNome(){
    return this->nome;
}
void Player::adicionarItem(Item* item_encontrado){
   // this->mochila.colocarItem(item_encontrado);
   this->mochila<<item_encontrado;
}
void Player::listarItensDaMochila(){
    this->mochila.printItens();
}

void Player::operator+(int qtdCura){
    this->curarVida(qtdCura);
}
void Player::operator-(int qtdDano){
    cout << this->getNome() << " recebeu "<< qtdDano << " de dano"<<endl;
    this->receberDano(qtdDano);
}
bool Player::isAlive(){
    return this->hp>0;
}
void Player::curarVida(int cura){
    this->hp += cura;
    if(this->hp>100){
        this->hp = 100;
    }
}
void Player::receberDano(int dano){
    this->hp -= dano;
    if(this->hp<0){
        this->hp = 0;
    }
}
void Player::operator<<(Item* item_encontrado){
    this->adicionarItem(item_encontrado);
}

bool Player::removerItem(int qtdItem, string tipo){
    return (this->mochila.tirarItem(tipo, qtdItem));
}

int Player::getHP(){
    return this->hp;
}