#ifndef POTION_HPP
#define POTION_HPP

#include "string"
#include "player.hpp"

using namespace std;
class Potion
{
protected:
    string _name;
    int _power;

public:
    Potion() : _name("heal_Potion"), _power(5) {};
    Potion(string name, int power) : _name(name), _power(power) {};

    string Getname(){return _name;}
    virtual void ShowInfo(int power);
    void PowerUp();
    virtual void UsePotion(Player* player);
};

#endif