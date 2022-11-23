#include <iostream>
#include <string>
#include "player.hpp"
#include <vector>

using namespace std;

vector<Player*> listaDeJogadores;


void menuCreatePlayer()
{
    cout << "CREATING NEW PLAYER" << endl;
    cout << "Character Name: " ;
    string nome;
    cin >> nome;
    listaDeJogadores.push_back(new Player(nome));
}
void menuSelectPlayer()
{
    cout << "SELECT A PLAYER" << endl;
}

int main()
{
    while (1)
    {
        cout << "WELCOME TO POTION FINDER!!!!!!!" << endl;
        cout << "1 - CREATE PLAYER" << endl;
        cout << "2 - SELECT A PLAYER TO MAKE A MOVE" << endl;
        cout << "3 - EXIT" << endl;
        cout << "SELECT AN OPTION" << endl;

        string option;
        cin >> option;

        if (option == "1")
        {
            menuCreatePlayer();
        }
        else if (option == "2")
        {
            menuSelectPlayer();
        }
        else if (option == "3")
        {
            for( int i=0; i<listaDeJogadores.size(); i++){
                delete listaDeJogadores.at(i);

            }
            break;
        }
        else
        {
            cout << "INVALID OPTION" << endl;
        }
    }
    return 0;
}