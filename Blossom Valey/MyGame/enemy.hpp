#ifndef ENEMY_HPP
#define ENEMY_HPP

//#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include<QObject>

// iniimigo padrão, mais generico
class Enemy:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
    int life;
    int animation = 0;
public slots:
    void move();
    void Animator();
};

#endif // ENEMY_HPP
