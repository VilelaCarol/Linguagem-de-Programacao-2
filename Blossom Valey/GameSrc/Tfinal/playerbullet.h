#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "projectile.h"

class PlayerBullet : public Projectile
{
public:
    PlayerBullet( QGraphicsItem *parent = 0);
    ~PlayerBullet();
public slots:
    void move(); 

};

#endif // PLAYERBULLET_H
