#ifndef PLAYER_H
#define PLAYER_H

//#include<QGraphicsRectItem>
#include<QObject>
#include<QGraphicsItem>
#include<QGraphicsPixmapItem>

class Player : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem*parent=0);
    ~Player();
    void moveUp();
    void moveDown();
    void shoot();
};

#endif // PLAYER_H
