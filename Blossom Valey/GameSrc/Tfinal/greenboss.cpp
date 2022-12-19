#include <QString>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include <vector>
#include <string.h>

#include "enemy.h"
#include "greenboss.h"

using namespace std;
extern vector <Enemy*> enemies;



GreenBoss::GreenBoss( QGraphicsItem *parent)
    : Enemy(parent)
{
    animationFrame = 1;
    this->img = "1";
    QString img_url = QString::fromStdString(this->img + to_string(this->animationFrame) + ".png");
    // printa o caminho da imagem
    //qDebug() << img;
    setPixmap(QPixmap(":/assets/corvo_"+img_url));
    int random_y = rand() % 637;
    setPos(1000,random_y);
    setScale(0.15);
    health = 3;


}

void GreenBoss::move()
{
    // chama a função move da classe pai
    Enemy::move();
}

void GreenBoss::animate()
{
    Enemy::animate();
}

GreenBoss::~GreenBoss()
{

}
