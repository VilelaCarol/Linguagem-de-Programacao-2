#ifndef BAG_HPP
#define BAG_HPP
#include "item.hpp"
#include <vector>
#include "poison.hpp"
#include "heal.hpp"
class Bag
{

private:
    vector<Poison*> listaDeVeneno ;
    vector<Heal*> listaDeCura;
public:
    Bag();
    ~Bag();

    void printItens();//printa na tela a lista de todos os itens 
    vector<Item*> getItens();
    void colocarItem(Item* novoItem);
    void colocarItem(Poison* novoItem);
    void colocarItem(Heal* novoItem);
    void tirarItem(string tipo, int quantidade);
};

#endif