#include "asteroid.h"
#include "player.h"
#include "Game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

extern Game* game;

Asteroid::Asteroid(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    int randomAsteroid = rand() % 3;
    switch(randomAsteroid)
    {
    case 0:
        setPixmap(QPixmap(":/space/amin.jpg").scaled(150,150));
        break;

    case 1:
        setPixmap(QPixmap(":/space/amin.jpg").scaled(60,70));
        break;

    case 2:
        setPixmap(QPixmap(":/space/amin.jpg").scaled(60, 60));
        break;
    }

    int randomX = (rand() % 725) + 25;
    setPos(randomX,-150);

    speed = (rand() % 4) + 4;

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(15);
}

void Asteroid::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            game->displayGameOverWindow();

            return;
        }
    }

    this->setPos(x(), y() + speed);

    if (pos().y() > 720){
        scene()->removeItem(this);
        delete this;
    }
}
