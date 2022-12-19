#include <QString>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include <vector>


#include "enemy.h"

using namespace std;
extern vector <Enemy*> enemies;

Enemy::Enemy(QGraphicsItem*parent): QGraphicsPixmapItem(parent)
{
    animationFrame =  1;
    this->img = "0";
    QString img_url = QString::fromStdString(this->img + to_string(this->animationFrame) + ".png");
    // printa o caminho da imagem
    qDebug() << ":/assets/corvo_"+img_url;
    setPixmap(QPixmap(":/assets/corvo_"+img_url));
    int random_y = rand() % 637;
    setPos(1000,random_y);
    setScale(0.15);
    health = 1;

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(150);
    QTimer *timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(animate()));
    timer2->start(200);
}

void Enemy::move()
{
    setPos(x()-5,y());
    if(pos().x() < 0)
    {
        scene()->removeItem(this);
        // busca no vetor a referencia a si mesmo e se encontrar remove ela dele
        for(int i = 0; i < enemies.size(); i++){
            if(enemies[i] == this){
                enemies.erase(enemies.begin()+i);
            }
        }
        delete this;
    }
}

void Enemy::animate()
{
    // frames: 01 e 02
    animationFrame = (animationFrame == 1) ? 2 : 1;
    QString img_url = QString::fromStdString(this->img + to_string(this->animationFrame) + ".png");
    
    qDebug() << ":/assets/corvo_" + img_url;
    setPixmap(QPixmap(":/assets/corvo_" + img_url));
}

Enemy::~Enemy()
{
    qDebug() << "Enemy deleted";
}
