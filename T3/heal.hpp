#ifndef HEAL_HPP
#define HEAL_HPP
#include "item.hpp"

class Heal : public Item
{
    public:
    int cura;

public:
    Heal();
    ~Heal();
};

#endif