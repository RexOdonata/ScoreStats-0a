#ifndef ENTRY_H
#define ENTRY_H

#include <QWidget>
#include <QMainWindow>

#include "player.h"

namespace Ui {
class entry;
}

class entry : public QWidget
{
    Q_OBJECT

public:
    explicit entry(QWidget *parent = nullptr);
    ~entry();

    void refreshView();

    void setButtonText(bool removeToggle);

    void loadMainPtr(QMainWindow * ptrMain);

    player getPlayer();

    void loadPlayer(int score, QString name);

signals:
    void deleteEntrySignal(entry * entryPtr);

private slots:
    void on_button_alter_clicked();

private:
    Ui::entry *ui;

    player data;

    QMainWindow * mainWindowPtr;
};

#endif // ENTRY_H
