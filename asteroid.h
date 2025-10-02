#ifndef ASTEROID_H
#define ASTEROID_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Asteroid : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Asteroid(QGraphicsItem* parent = nullptr);

    int speed;

public slots:
    void move();
};

#endif // ASTEROID_H
