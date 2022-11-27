#ifndef BAG_HPP
#define BAG_HPP
#include "item.hpp"
#include <vector>
#include "poison.hpp"
#include "heal.hpp"
class Bag
{

private:
    vector<Poison *> listaDeVeneno;
    vector<Heal *> listaDeCura;

private:
    void colocarItem(Item *novoItem);
    void colocarItem(Poison *novoItem);
    void colocarItem(Heal *novoItem);

public:
    Bag();
    ~Bag();

    void printItens(); // printa na tela a lista de todos os itens
    vector<Item *> getItens();
    bool tirarItem(string tipo, int quantidade);
    void operator<<(Item *novoItem); // adiciona item na mochila
};

#endif