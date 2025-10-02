#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>

#include "player.h"
#include "score.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent = 0);

    QGraphicsScene* scene;

    Player* player;

    Score* score;

    void displayGameOverWindow();

    void spawnMoreAsteroids();

    void spawnComets();

public slots:
    void restartGame();
};

#endif // GAME_H
