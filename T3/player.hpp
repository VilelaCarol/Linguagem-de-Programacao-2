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

  public:
    Player();
    Player(string nome);
    ~Player();

   //int getId();
   string getNome();

   void adicionarItem(Item* item_encontrado); //coloca o item dentro da mochila
   void receberDano(int dano);
   void usarPocaoDeCura();// pergunta quantas poções de vida ele quer usar e as usa (chamando o curarVida)
   void listarItensDaMochila(); // escreve na tela todos os itens que estão na mochila
};

#endif