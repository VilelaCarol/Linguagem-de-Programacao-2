#ifndef GREENBOSS_H
#define GREENBOSS_H

#include "enemy.h"
#include <QObject>

using namespace std;
class GreenBoss : public Enemy
{

public:
    GreenBoss( QGraphicsItem *parent = 0);
    ~GreenBoss();

public slots:
    void move();
    void animate();
};

#endif // GREENBOSS_H
