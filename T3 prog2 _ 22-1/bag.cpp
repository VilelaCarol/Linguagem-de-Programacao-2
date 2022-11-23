#include "bag.hpp"

void Bag::ShowInventory()
{
    cout << "Name: " << _player->GetName() << "itens: " << sizeof(_slot) << endl;
    for (int i = 0; i < sizeof(_slot); i++)
    {
        cout << i << " - Item Name: " << _slot.at(i)->Getname() << endl;
    }
}

void Bag::GetItem(Potion *value)
{
    _slot.push_back(value);
}

bool Bag::DropItem(Potion *value)
{
    for (int i = 0; i < sizeof(_slot); i++)
    {
        if (&value == &_slot.at(i))
        {
            _slot.erase(_slot.begin() + i);
            return true;
        }
    }
    return false;
}

void Bag::GiveItem(Potion *value, Bag *wichPlayer)
{
    if (DropItem(value))
    {
        wichPlayer->GetItem(value);
    }
}

void Bag::UseItem(int slot)
{
    _slot.at(slot)->UsePotion(_player);
}

void Bag::UseItem(int slot, Player *player)
{
    _slot.at(slot)->UsePotion(player);
}

void Bag::PowerUpPotion(int slot)
{
    _slot.at(slot)->PowerUp();
}