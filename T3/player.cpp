#include "player.hpp"
#include <iostream>

using namespace std;

Player::Player()
{
    cout<< "construtor sem nome" << endl;
    this->hp = 100;
    this->mochila = Bag();
    this->nome = "sem nome";
}

Player::Player(string nome)
{
    cout<< "construtor com nome" << endl;
    this->nome = nome;
    this->hp = 100;
    this->mochila = Bag();
}
Player::~Player(){
    cout<< "Deletando player "<< this->nome<<endl;
}