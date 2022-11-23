#include "potion.hpp"

using namespace std;
void Potion::ShowInfo(int power){
    cout << "This potion heals: " << _power << endl;
}

void Potion::PowerUp(){
    _power += 1;
}

void Potion::UsePotion(Player* player){
    player->SetHp(_power);
    if (_power > 0)
    {
        _power -= 1;
    }
}