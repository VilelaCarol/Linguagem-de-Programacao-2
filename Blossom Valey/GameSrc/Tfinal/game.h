#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include<QGraphicsScene>

#include "player.h"
#include "score.h"

class Game : public QGraphicsView
{
public:
    Player* player;
    Score* score;

public:
    Game(QWidget * parent = 0);
    ~Game();
    QGraphicsScene * scene;
    void keyPressEvent(QKeyEvent *event);

private:
    void createNewPlayer();
    void setTimerNormalEnemySpawn(int time);
public slots:
    void spawnNomalEnemy();
    // botão de fechar da janela
    void closeEvent(QCloseEvent *event);
};

#endif // GAME_H
