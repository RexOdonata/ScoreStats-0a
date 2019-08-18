#include "displayscores.h"
#include "ui_displayscores.h"

#include <cmath>
#include <QLabel>

displayScores::displayScores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayScores)
{
    ui->setupUi(this);

    mean=0;
    stdDev=0;

}

displayScores::~displayScores()
{
    delete ui;
}

void displayScores::on_button_close_clicked()
{
    this->close();
}

void displayScores::loadEntryListPtr(QVector<entry *> input)
{
   entryListPtr=input;
}

void displayScores::runStats()
{
    int numEntries=entryListPtr.length();

    for (int i=0; i<numEntries; i++)
    {
        //add score to mean
        mean+=entryListPtr[i]->getPlayer().getScore();
        //copy player into vector
        playerList.append(entryListPtr[i]->getPlayer());
    }

    mean=mean/numEntries;

    QString temp = "Mean: ";

    ui->label_mean->setText(temp.append(QString::number(mean)));

    for (int i=0; i<numEntries; i++)
    {
        stdDev+=pow(entryListPtr[i]->getPlayer().getScore()-mean,2);
    }

    stdDev=sqrt(stdDev/numEntries);

    temp = "stdDev: ";

    ui->label_stdDev->setText(temp.append(QString::number(stdDev)));
}

void displayScores::populate()
{
    int max;
    int index=0;
    while (playerList.length()>0)
    {
        max=0;
        for (int i=0; i<playerList.length(); i++)
        {
            if (playerList[i].getScore()>max)
            {
                max=playerList[i].getScore();
                index=i;
            }
        }
        QLabel * nameLabel = new QLabel;
        nameLabel->setText(playerList[index].getName());

        QLabel * scoreLabel = new QLabel;
        QString score = QString::number(playerList[index].getScore()/mean*100);
        scoreLabel->setText(score.append("%"));

        QLabel * groupLabel = new QLabel;
        if (playerList[index].getScore()>mean+stdDev) groupLabel->setText("+");
        else if (playerList[index].getScore()<mean-stdDev) groupLabel->setText("-");
        else groupLabel->setText("x");

        ui->layout_name->addWidget(nameLabel);
        nameLabel->setAlignment(Qt::AlignCenter);
        ui->layout_score->addWidget(scoreLabel);
        scoreLabel->setAlignment(Qt::AlignCenter);
        ui->layout_group->addWidget(groupLabel);
        groupLabel->setAlignment(Qt::AlignCenter);

        playerList.removeAt(index);

    }
}
