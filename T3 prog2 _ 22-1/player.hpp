#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
using namespace std;

class Player
{
private:
    int _id;
    string _name;
    int _hp;

public:
    Player() {};
    Player(int id, string name, int hp) : _id(id), _name(name), _hp(hp)  {};

    string GetName() { return _name; };
    int GetHp() { return _hp; };
    void SetHp(int hp) {_hp += hp; }
};

#endif