#ifndef COMET_H
#define COMET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Comet : public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT

public:
    Comet(QGraphicsItem* parent = nullptr);

public slots:
    void move();

private:
    int speed;
};

#endif // COMET_H
