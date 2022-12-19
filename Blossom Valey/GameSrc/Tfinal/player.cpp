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
    this->setPos(this->x(),this->y()-10);
}
void Player::moveDown()
{
    this->setPos(this->x(),this->y()+10);
}
void Player::shoot()
{
    qDebug() << "shoot";
}
Player::~Player()
{
    qDebug() << "Player deleted";
}
