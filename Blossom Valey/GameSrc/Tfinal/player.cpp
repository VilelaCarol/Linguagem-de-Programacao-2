#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>

#include "player.h"

Player::Player(QGraphicsItem*parent): QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/assets/Pantalho.png"));
    this->setScale(0.15);
}
void Player::moveUp()
{
    // verrifica se a movimentação não ultrapassa o limite superior da tela incluind metade to tamanho da imagem do player
    int tamanhoPlayer = this->pixmap().height()*0.15;
    if(this->y()+(tamanhoPlayer/2)-10 > 0){
        this->setPos(this->x(),this->y()-10);
    }
}
void Player::moveDown()
{
    // verrifica se a movimentação não ultrapassa o limite inferior da tela
    if(this->y()+10 < 673){
        this->setPos(this->x(),this->y()+10);
    }
}
void Player::shoot()
{
    qDebug() << "shoot";
}
Player::~Player()
{
    qDebug() << "Player deleted";
}
