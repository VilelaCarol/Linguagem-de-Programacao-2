#include "game.h"

Game::Game(QWidget *parent)
{
    this->scene = new QGraphicsScene();

    this->setSceneRect(0,0,800,600);
    // add aqui a imagem de fundo, redimensiona ela pra ter o tamanho da imagem e depois coloca ela no scene
    // imagem original: 1849x1040
    // redimensionada (mantendo proporção): 800x450
    this->scene->setBackgroundBrush(QBrush(QImage(":/assets/Fundo_casa.png").scaled(800,450)));


    this->setScene(scene);

    // desabilita barra de rolagem
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // desabilita o resize
    this->setFixedSize(800,450);


    this->show();


}

Game::~Game()
{
    delete this->scene;
}
