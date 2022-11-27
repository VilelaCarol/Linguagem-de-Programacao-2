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
    cout << endl
         << endl
         << "PLAYER SELECTED: " << pSelected->getNome() << endl;
    cout << "1 - Walk" << endl;
    cout << "2 - See bag" << endl;
    cout << "3 - Challenge another player" << endl;
    cout << "4 - Exit" << endl;
    int option;
    cin >> option;
    if (option == 1)
    {
        cout << "Walking..." << endl;
        // existe uma chance aleatoria de encontra um item (heal ou poison)
        // se encontrar, chama o metodo adicionarItem da classe Player

        // gera um numero entre 0 e 100
        // se o numero for menor que 10, encontra um item
        int random = rand() % 100;
        if (random < 70)
        {
            // se o numero for 0, encontra um heal
            if (random < 35)
            {
                cout << "Found a heal" << endl;
                Heal *h = new Heal();
                // pSelected->adicionarItem(h);
                *pSelected << h;
            }
            // se o numero for 1, encontra um poison
            else
            {
                cout << "Found a poison" << endl;
                Poison *p = new Poison();
                // pSelected->adicionarItem(p);
                *pSelected << p;
            }
        }
    }
    else if (option == 2)
    {
        pSelected->listarItensDaMochila();
    }
    else if (option == 3)
    {
        cout << "Challenging another player..." << endl;
        // primeiro voce tem que escolher quem voce quer desafiar
        // fazer um loop e printar o nome de todos os jogadores que não são o jogador selecionado
        for (int i = 0; i < listaDeJogadores.size(); i++)
        {
            if (pSelected->getNome() == listaDeJogadores.at(i)->getNome())
            {
                continue;
            }

            cout << i << " - " << listaDeJogadores.at(i)->getNome() << endl;
        }

        int escolha;
        Player *pDesafiado;
        cin >> escolha;
        pDesafiado = listaDeJogadores.at(escolha);

        // cada jogador vai escolher uma quantidade de venenos para jogar np outro (uma rodada)
        // fazer cada jogador escolher uma quantidade de veneno para jogar (então tem q mostrar a bag de cada um)
        int qtdVenenoPS, qtdVenenoPD;
        while (1)
        {
            cout << pSelected->getNome() << "'s bag" << endl;
            pSelected->listarItensDaMochila();
            cout << "how many poisons do you want?" << endl;
            cin >> qtdVenenoPS;
            if (pSelected->removerItem(qtdVenenoPS, "veneno"))
            {
                break;
            }
        }

        while (1)
        {
            cout << pDesafiado->getNome() << "'s bag" << endl;
            pDesafiado->listarItensDaMochila();
            cout << "how many poisons do you want?" << endl;
            cin >> qtdVenenoPD;
            if (pDesafiado->removerItem(qtdVenenoPD, "veneno"))
            {
                break;
            }
        }

        // calcular os danos de acordo com as quantidades escolhidas
        Poison p = Poison();
        *pDesafiado - (p.dano * qtdVenenoPS);
        *pSelected - (p.dano * qtdVenenoPD);

        cout << pSelected->getNome()<<": "<<pSelected->getHP()<<endl;
        cout << pDesafiado->getNome()<<": "<<pDesafiado->getHP()<<endl;

        // vence quem estiver vivo ou com mais vida
        // se os dois morrerem f
        if (pSelected->isAlive() || pDesafiado->isAlive())
        {
            // entra no if quando pelo menos um dos players esta vivo ou os dois vivos
            if (pSelected->isAlive() && pDesafiado->isAlive())
            {
                // entra quando os dois estão vivos
                if (pSelected->getHP() > pDesafiado->getHP())
                {
                    cout << "the winner is  " << pSelected->getNome() << endl;
                }
                else if (pDesafiado->getHP() > pSelected->getHP())
                {
                    cout << "the winner is  " << pDesafiado->getNome() << endl;
                }
                else
                {
                    cout << "it's a draw" << endl;
                }
            }
        }
        else
        {
            // entra no else quando os dois players estão mortos
            cout << "F" << endl;
        }
    }
    else if (option == 4)
    {

        cout << "Exiting..." << endl;
    }
    else
    {

        cout << "Invalid option" << endl;
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
        cout << endl
             << endl
             << "WELCOME TO POTION FINDER!!!!!!!" << endl;
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