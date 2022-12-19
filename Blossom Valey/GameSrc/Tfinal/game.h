#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include<QGraphicsScene>

class Game : public QGraphicsView
{
public:
    Game(QWidget * parent = 0);
    ~Game();
    QGraphicsScene * scene;

};

#endif // GAME_H
