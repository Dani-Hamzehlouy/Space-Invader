#include <QList>

#include "bullet.h"
#include "asteroid.h"
#include "Game.h"
#include "comet.h"

extern Game* game;

Bullet::Bullet(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    QPixmap pixmap = QPixmap(":/space/amin.jpg");
    pixmap = pixmap.scaled(20, 60);
    setPixmap(pixmap);

    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(10);
}

void Bullet::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Asteroid))
        {
            game->score->increaseScore();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Comet))
        {
            scene()->removeItem(this);
            delete this;
        }
    }

    setPos(x(),y()-10);

    if (pos().y() < -60){
        scene()->removeItem(this);
        delete this;
    }
}
