#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class player
{
public:
    player();

    void setData(int inputScore, QString inputName);

    int getScore();
    QString getName();


private:
    QString name;
    int score;
};

#endif // PLAYER_H
