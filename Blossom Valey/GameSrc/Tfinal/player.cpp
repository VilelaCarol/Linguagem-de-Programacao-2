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
    PlayerBullet* bullet = new PlayerBullet();
    bullet->setPos(this->x()+this->pixmap().width()*0.15,this->y()+this->pixmap().height()*0.15);
    scene()->addItem(bullet);
    this->bullets.push_back(bullet);
}
Player::~Player()
{
    qDebug() << "Player deleted";
    // anda no vetor de bullets e deleta todos os elementos
    for(int i = 0; i < this->bullets.size(); i++){
        delete this->bullets[i];
    }
}
