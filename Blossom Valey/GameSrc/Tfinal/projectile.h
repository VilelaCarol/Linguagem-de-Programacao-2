#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Projectile :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
protected:

    int speed;
public:
    Projectile(QGraphicsItem * parent=0);
    ~Projectile();
private:
public slots:
    virtual void move(){};

};

#endif // PROJECTILE_H
