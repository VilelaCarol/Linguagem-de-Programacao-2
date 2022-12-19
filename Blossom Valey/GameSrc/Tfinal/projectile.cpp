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



