#ifndef POISON_HPP
#define POISON_HPP
#include "item.hpp"

class Poison : public Item
{

public:
int dano;

public:
    Poison();
    ~Poison();
};

#endif