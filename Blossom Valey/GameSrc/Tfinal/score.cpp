#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QUrl>
#include <QString>

#include "score.h"

Score::Score()
{
    this->score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
    this->soundtrack = new QMediaPlayer();
    this->soundtrack->setMedia(QUrl("qrc:/sounds/battleThemeA.mp3"));
    this->soundtrack->play();
}
Score::~Score()
{
    // para a musica
    this->soundtrack->stop();
    delete soundtrack;
}
void Score::increase()
{
    this->score++;
    setPlainText(QString("Score: ") + QString::number(score));
}
int Score::getScore()
{
    return this->score;
}
