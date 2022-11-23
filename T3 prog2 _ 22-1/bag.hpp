#ifndef BAG_HPP
#define BAG_HPP

#include "player.hpp"
#include "potion.hpp"
#include <vector>

class Bag
{
protected:
    Player *_player;
    vector<Potion*> _slot;

public:
    Bag() : _player(NULL) {};

    Bag(Player *player) : _player(player) {};

    void ShowInventory();

    void GetItem(Potion *value);

    bool DropItem(Potion* value);

    void GiveItem(Potion *value, Bag *wichPlayer);

    void UseItem(int slot);
    void UseItem(int slot, Player *player);

    void PowerUpPotion(int slot);
};

#endif