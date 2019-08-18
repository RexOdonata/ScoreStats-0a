#include "entry.h"
#include "ui_entry.h"

#include "mainwindow.h"
#include "editplayer.h"

entry::entry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::entry)
{
    ui->setupUi(this);

    player * ptrPlayer= new player;

    data=*ptrPlayer;

    refreshView();


}

entry::~entry()
{
    delete ui;
}

void entry::refreshView()
{
    ui->label_name->setText(data.getName());
    ui->label_score->setText(QString::number(data.getScore()));
}

void entry::setButtonText(bool removeToggle)
{

    if (removeToggle)
    {
        ui->button_alter->setText("del");
    }
    else
    {
        ui->button_alter->setText("edit");
    }
}

void entry::on_button_alter_clicked()
{
    MainWindow * ptrMain = static_cast<MainWindow *>(mainWindowPtr);

    if (ptrMain->getRemoveState())
    {
        connect(this,&entry::deleteEntrySignal,ptrMain,&MainWindow::deleteEntryResponse);
        emit deleteEntrySignal(this);
        ptrMain->enableAddPlayerButton();
    }
    else
    {
        editPlayer * editWindow = new editPlayer;

        editWindow->loadEntryPtr(this);

        editWindow->loadPlayerData();

        editWindow->showMaximized();

     }

}

void entry::loadMainPtr(QMainWindow *ptrMain)
{
    mainWindowPtr=ptrMain;    
}

void entry::loadPlayer(int score, QString name)
{
    data.setData(score,name);
}

player entry::getPlayer()
{
    return data;
}

