#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QUrl>
#include <QString>

class Score : public QGraphicsTextItem
{
public:
    QMediaPlayer* soundtrack;

    Score();
    ~Score();
    void increase();
    int getScore();
    

private:
    int score;
};

#endif // SCORE_H
