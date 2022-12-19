#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <vector>
#include <QObject>
#include <QTimer>


#include "player.h"
#include "score.h"
#include "enemy.h"

using namespace std;

class Game : public QGraphicsView
{

public:
    QTimer *timer;
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
    void freeMemory();
public slots:
  //void timeout();
  slots void spawnNormalEnemy();
  // botão de fechar da janela
  void closeEvent(QCloseEvent *event);
};

#endif // GAME_H
