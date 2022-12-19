#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem*parent=0);
    ~Enemy();

public slots:
    void move();
    void animate();

protected:
    int health;
    int animationFrame;

};

#endif // ENEMY_H
