#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include "bag.hpp"
#include "item.hpp"

using namespace std;

class Player{
  private:
   //int id; 
   string nome;
   int hp;// tem 100 de vida maxima
   Bag mochila;

   
  private:
   void curarVida(int cura);
   void receberDano(int dano);
   void adicionarItem(Item* item_encontrado); //coloca o item dentro da mochila
   void usarPocaoDeCura();// pergunta quantas poções de vida ele quer usar e as usa (chamando o curarVida)
  public:
    Player();
    Player(string nome);
    ~Player();

  
   //int getId();
   string getNome();
   void operator+(int qtdCura);
   void operator-(int qtdDano);
   void listarItensDaMochila(); // escreve na tela todos os itens que estão na mochila
   bool isAlive();
   void operator<<(Item* item_encontrado);
   bool removerItem(int qtdItem, string tipo);
   int getHP();
};

#endif