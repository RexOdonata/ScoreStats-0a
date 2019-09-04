#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "entry.h"
#include "displayscores.h"

#define LIMIT 8

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool getRemoveState();

    void enableAddPlayerButton();

    void maxEntryCheck();

public slots:
    void deleteEntryResponse(entry * entryPtr);

private slots:
    void on_button_addPlayer_clicked();

    void on_button_removePlayer_clicked();



    void on_button_calcScore_clicked();

private:
    Ui::MainWindow *ui;

    QVector<entry *> entryList;

    bool removeState;

};

#endif // MAINWINDOW_H
