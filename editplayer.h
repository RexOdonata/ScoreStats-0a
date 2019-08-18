#ifndef EDITPLAYER_H
#define EDITPLAYER_H

#include <QWidget>
#include <QString>

#include "entry.h"
#include "player.h"

namespace Ui {
class editPlayer;
}

class editPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit editPlayer(QWidget *parent = nullptr);
    ~editPlayer();

    void loadEntryPtr(entry * input);

    void zeroGuard();

    void emptyNameGuard();

    void loadPlayerData();

private slots:
    void on_button_incOne_clicked();

    void on_button_incFive_clicked();

    void on_button_incTwentyFive_clicked();

    void on_button_confirm_clicked();

    void on_button_toggleIncMode_clicked();

private:
    Ui::editPlayer *ui;

    int score;
    QString name;

    int incMode;

    entry * entryPtr;

};

#endif // EDITPLAYER_H
