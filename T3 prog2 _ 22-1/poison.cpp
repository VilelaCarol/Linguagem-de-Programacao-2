#include "poison.hpp"
#include "player.hpp"

void Poison::ShowInfo(int power){
    cout << "This potion damages: " << _power << endl;
}

void Poison::UsePotion(Player* playerTarget){
    playerTarget->SetHp(-_power);
    if (_power > 0)
    {
        _power -= 1;
    }
}