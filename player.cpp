#include "player.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QMediaPlayer>

#include "bullet.h"
#include "asteroid.h"
#include "comet.h"

Player::Player(QGraphicsItem* parent)
{
    QPixmap pixmap = QPixmap(":/space/amin.jpg");
    pixmap = pixmap.scaled(100,120);
    setPixmap(pixmap);

    bulletSound = new QMediaPlayer(this);
    bulletSound->setSource(QUrl("src:/bulletSound/laser2.mp3"));
}

void Player::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    int mouseX = mapToScene(event->pos()).x();
    int mouseY = mapToScene(event->pos()).y();

    if(mouseX >= 50 && mouseX <= 850 && mouseY >= 0 && mouseY <= 650)
    {
        this->setPos(mouseX-50, mouseY-50);
    }
}

void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+30,y()-50);
    scene()->addItem(bullet);


    if (bulletSound->isPlaying())
    {
        bulletSound->stop();
    }

    bulletSound->play();
}

void Player::spawnAsteroid()
{
    Asteroid* asteroid = new Asteroid();
    scene()->addItem(asteroid);
}

void Player::spawnComet()
{
    Comet* comet = new Comet();
    scene()->addItem(comet);
}
