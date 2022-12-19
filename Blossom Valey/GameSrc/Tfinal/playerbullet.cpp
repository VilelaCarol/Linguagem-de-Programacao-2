#include<QGraphicsScene>
#include<QTimer>
#include<QDebug>
#include<QList>

#include "playerbullet.h"

PlayerBullet::PlayerBullet( QGraphicsItem *parent)
        : Projectile(parent)
{
    setPixmap(QPixmap(":/assets/foguinho.png"));
    setScale(0.04);
    this->speed = 10;
    // Seta o timer de movimento
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}
PlayerBullet::~PlayerBullet()
{
    qDebug() << "PlayerBullet deleted";
}
void PlayerBullet::move()
{
    // chama a função move da classe pai
    Projectile::move();
}





