#include "player.h"

player::player()
{
    name="name";
    score=0;
}

void player::setData(int inputScore, QString inputName)
{
    score=inputScore;
    name=inputName;
}

QString player::getName()
{
    return name;
}

int player::getScore()
{
    return score;
}
