#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QImage>
#include <QBrush>

#include "Game.h"
#include "score.h"
#include "button.h"

Game::Game(QWidget* parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 900, 720);

    setBackgroundBrush(QBrush(QImage(":/space/amin.jpg")));

    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(900,720);


    player = new Player();
    player->setPos(450-50, 720-140);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    setMouseTracking(true);
    player->grabMouse();


    score = new Score();
    scene->addItem(score);


    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),player,SLOT(spawnAsteroid()));
    timer->start(1000);

    show();
}

void Game::displayGameOverWindow()
{
    QString scoreText = QString("Score: ") + QString::number(this->score->getScore());

    scene->clear();

    QString gameOverText = QString("AMIN OVER");
    QGraphicsTextItem* gameOverMessage = new QGraphicsTextItem(gameOverText);
    gameOverMessage->setPos(200,300);
    gameOverMessage->setDefaultTextColor(Qt::red);
    gameOverMessage->setFont(QFont("times",70));

    scene->addItem(gameOverMessage);


    QGraphicsTextItem* scoreMessage = new QGraphicsTextItem(scoreText);
    scoreMessage->setPos(200,450);
    scoreMessage->setDefaultTextColor(Qt::white);
    scoreMessage->setFont(QFont("times",35));

    scene->addItem(scoreMessage);


    Button* playAgainButton = new Button(QString("Play Again"));
    playAgainButton->setPos(200, 550);
    scene->addItem(playAgainButton);
    QObject::connect(playAgainButton,SIGNAL(clicked()),this,SLOT(restartGame()));

    Button* exitButton = new Button(QString("Exit"));
    exitButton->setPos(500, 550);
    scene->addItem(exitButton);
    QObject::connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
}

void Game::spawnMoreAsteroids()
{
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),player,SLOT(spawnAsteroid()));
    timer->start(1000);
}

void Game::spawnComets()
{
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),player,SLOT(spawnComet()));
    timer->start(5000);
}

void Game::restartGame()
{
    scene->clear();

    player = new Player();
    player->setPos(450-50, 720-140);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    setMouseTracking(true);
    player->grabMouse();


    score = new Score();
    scene->addItem(score);


    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),player,SLOT(spawnAsteroid()));
    timer->start(1000);

    show();
}
