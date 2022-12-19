#include<QGraphicsScene>
#include<QTimer>
#include<QDebug>
#include<QList>


#include "projectile.h"

Projectile::Projectile(QGraphicsItem*parent):QObject(),QGraphicsPixmapItem(parent)
{
    

}
Projectile::~Projectile()
{
    qDebug() << "Projectile deleted";
}


void Projectile::move()
{
    // printa a posição do playerbullet
    qDebug() << "PlayerBullet position: " << pos().x() << " " << pos().y();
    setPos(x()+this->speed,y());
    if(pos().x() > 1200){
        scene()->removeItem(this);
        delete this;
    }
}
