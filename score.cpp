#include <QFont>

#include "score.h"
#include "Game.h"

extern Game* game;

bool difficultyOne = 0;
bool difficultyTwo = 0;
bool cometSpawning = 0;

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    score = 0;
    difficultyOne = 0;
    difficultyTwo = 0;
    cometSpawning = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",20));
}

void Score::increaseScore()
{
    if (difficultyOne == 0 && score >= 500)
    {
        game->spawnMoreAsteroids();

        difficultyOne = 1;
    }

    if (difficultyTwo == 0 && score >= 1500)
    {
        game->spawnMoreAsteroids();

        difficultyTwo = 1;
    }

    if (cometSpawning == 0 && score >= 2000)
    {
        game->spawnComets();

        cometSpawning = 1;
    }

    score += 50;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
