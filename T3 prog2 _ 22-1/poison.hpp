#ifndef POISON_HPP
#define POISON_HPP

#include "potion.hpp"
#include "player.hpp"

class Poison : public Potion
{
private:
    string _namePoison = "poison";
    int _powerPoison = 4;

public:
    Poison() : Potion(_namePoison , _powerPoison) {};

    void ShowInfo(int power);
    void UsePotion(Player *playerTarget);
};

#endif