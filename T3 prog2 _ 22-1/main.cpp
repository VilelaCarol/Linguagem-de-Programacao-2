#include <iostream>
#include "player.hpp"
#include "potion.hpp"
#include "poison.hpp"
#include "bag.hpp"

using namespace std;

int main()
{
    Player player1(001, "player1", 5);
    Bag bag1(&player1);

    Player player2(002, "player2", 10);
    Bag bag2(&player2);

    Player player3(003, "player3", 15);
    Bag bag3(&player3);

    Potion potion1;
    Poison poison1;

    bag1.GetItem(&poison1);
    bag1.UseItem(0, &player2);

    bag3.GetItem(&potion1);
    bag3.PowerUpPotion(0);
    bag3.GiveItem(0, &bag2);

    bag2.UseItem(0);

    system("PAUSE");

    return 0;
}