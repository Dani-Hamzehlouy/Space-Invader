#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QSoundEffect>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player(QGraphicsItem* parent = nullptr);

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);

public slots:
    void spawnAsteroid();

    void spawnComet();

private:
    QMediaPlayer* bulletSound;
};

#endif // PLAYER_H
