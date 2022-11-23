#include <iostream>
#include <string>
#include "player.hpp"
#include <vector>
#include <random>

using namespace std;

vector<Player *> listaDeJogadores;

void menuCreatePlayer()
{
    cout << endl
         << endl
         << "CREATING NEW PLAYER" << endl;
    cout << "Character Name: ";
    string nome;
    cin >> nome;
    listaDeJogadores.push_back(new Player(nome));
}
void playerSelectedOptions(Player *pSelected)
{
    cout <<endl<<endl<< "PLAYER SELECTED: " << pSelected->getNome() << endl;
    cout << "1 - Walk" << endl;
    cout << "2 - See bag" << endl;
    cout << "3 - Challenge another player" << endl;
    cout << "4 - Exit" << endl;
    int option;
    cin >> option;
    int random = rand() % 100;
    switch (option)
    {
    case 1:
        cout << "Walking..." << endl;
        // existe uma chance aleatoria de encontra um item (heal ou poison)
        // se encontrar, chama o metodo adicionarItem da classe Player

        // gera um numero entre 0 e 100
        // se o numero for menor que 10, encontra um item
        if (random < 70)
        {
            // se o numero for 0, encontra um heal
            if (random < 35)
            {
                cout << "Found a heal" << endl;
                Heal *h = new Heal();
                pSelected->adicionarItem(h);
            }
            // se o numero for 1, encontra um poison
            else
            {
                cout << "Found a poison" << endl;
                Poison *p = new Poison();
                pSelected->adicionarItem(p);
            }
        }
        break;
    case 2:
        pSelected->listarItensDaMochila();
        break;
    case 3:
        cout << "Challenging another player..." << endl;
        break;
    case 4:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid option" << endl;
        break;
    }
}
void menuSelectPlayer()
{
    cout << "SELECT A PLAYER" << endl;
    for (int i = 0; i < listaDeJogadores.size(); i++)
    {
        cout << i << " - " << listaDeJogadores.at(i)->getNome() << endl;
    }
    string escolha;
    cin >> escolha;
    Player *pSelected = listaDeJogadores.at(stoi(escolha));
    playerSelectedOptions(pSelected);
}

int main()
{
    while (1)
    {
        cout <<endl<<endl<< "WELCOME TO POTION FINDER!!!!!!!" << endl;
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
            for (int i = 0; i < listaDeJogadores.size(); i++)
            {
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