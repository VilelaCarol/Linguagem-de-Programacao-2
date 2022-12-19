#include <QGraphicsTextItem>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QKeyEvent>
# include <vector>
using namespace std;
#include "game.h"
vector<Enemy*> enemies;
Game::Game(QWidget *parent)
{
    this->scene = new QGraphicsScene();

    this->setSceneRect(0,0,1200,673);
    // add aqui a imagem de fundo, redimensiona ela pra ter o tamanho da imagem e depois coloca ela no scene
    // imagem original: 1849x1040
    // redimensionada (mantendo proporção): 1200x673
    this->scene->setBackgroundBrush(QBrush(QImage(":/assets/Fundo_casa.png").scaled(1200,673)));


    this->setScene(scene);

    // desabilita barra de rolagem
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // desabilita o resize
    this->setFixedSize(1200,673);

    // cria o player
    this->createNewPlayer();

    // cria o score
    this->score = new Score();
    this->scene->addItem(this->score);

    // cria o timer para spawnar os inimigos
    this->setTimerNormalEnemySpawn(5500);


    this->show();


}

void Game::setTimerNormalEnemySpawn(int time){

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, std::bind(&Game::spawnNormalEnemy, this));
    timer->start(time);
}
void Game::spawnNormalEnemy()
{
    // printa no console
    qDebug() << "spawnou inimigo";
    Enemy * enemy = new Enemy();
    this->scene->addItem(enemy);
    enemies.push_back(enemy);
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        this->player->moveUp();
    }
    else if(event->key() == Qt::Key_Down){
        this->player->moveDown();
    }
    else if(event->key() == Qt::Key_Space){
        this->player->shoot();
    }
}

void Game::createNewPlayer()
{
    this->player = new Player();
    this->player->setPos(250,100); // posição(x,y)
    this->player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->player->setFocus();
    this->scene->addItem(this->player);
}

void Game::freeMemory(){
    // para o timer
    this->timer->stop();
    // anda pelo vetor de inimigos e deleta cada um deles
    for(int i = 0; i < enemies.size(); i++){
        delete enemies[i];
    }
    delete this->score;
    delete this->player;
    delete this->scene;
}
void Game::closeEvent(QCloseEvent *event)
{
    this->freeMemory();
}

Game::~Game()
{
    this->freeMemory();
}
