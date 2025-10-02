#include "comet.h"
#include "qgraphicsscene.h"
#include "qtimer.h"
#include "player.h"
#include "Game.h"

extern Game* game;

Comet::Comet(QGraphicsItem* parent)
{
    setPixmap(QPixmap(":/comet/comet.png").scaled(200,200));

    //int randomX = (rand() % 725) + 25;
    setPos(game->player->x()-50,-150);

    speed = 8;

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(15);
}

void Comet::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            scene()->removeItem(colliding_items[i]);

            delete colliding_items[i];

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
