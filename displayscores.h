#ifndef DISPLAYSCORES_H
#define DISPLAYSCORES_H

#include <QWidget>
#include <QVector>
#include <QMainWindow>

#include "entry.h"

namespace Ui {
class displayScores;
}

class displayScores : public QWidget
{
    Q_OBJECT

public:
    explicit displayScores(QWidget *parent = nullptr);
    ~displayScores();

    void loadEntryListPtr(QVector<entry *> input);

    void runStats();

    void populate();


private slots:
    void on_button_close_clicked();

private:
    Ui::displayScores *ui;

    QVector<entry *> entryListPtr;

    QVector<player> playerList;

    double mean;
    double stdDev;
};

#endif // DISPLAYSCORES_H
