#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    removeState=false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_addPlayer_clicked()
{


    entry * ptrEntry = new entry;

    ui->layout_entries->addWidget(ptrEntry);

    //give address of main window to entry
    ptrEntry->loadMainPtr(this);

    entryList.append(ptrEntry);

    maxEntryCheck();

}

void MainWindow::on_button_removePlayer_clicked()
{
    if (removeState)
    {
        removeState=false;
        ui->button_removePlayer->setText("Remove Player");
        ui->button_addPlayer->setEnabled(true);


        for (int i=0; i<entryList.length(); i++)
        {
            entryList[i]->setButtonText(removeState);
        }
    }
    else
    {
        removeState=true;
        ui->button_removePlayer->setText("Cancel");
        ui->button_addPlayer->setEnabled(false);

        for (int i=0; i<entryList.length(); i++)
        {
            entryList[i]->setButtonText(removeState);
        }
    }

}

void MainWindow::deleteEntryResponse(entry * entryPtr)
{
    //set remove to off and set all alter button text to edit.
    removeState=false;
    ui->button_removePlayer->setText("Remove Player");

    for (int i=0; i<entryList.length(); i++)
    {
        entryList[i]->setButtonText(removeState);
    }

    //remove entry from layout
    ui->layout_entries->removeWidget(entryPtr);

    //remove entry from list of entries
    entryList.remove(entryList.indexOf(entryPtr));

    //delete entry
    delete entryPtr;

    maxEntryCheck();


}

bool MainWindow::getRemoveState()
{
    return removeState;
}

void MainWindow::on_button_calcScore_clicked()
{
    displayScores * ptrDisplay = new displayScores;
    ptrDisplay->loadEntryListPtr(entryList);
    ptrDisplay->runStats();
    ptrDisplay->populate();
    ptrDisplay->showMaximized();
}

void MainWindow::enableAddPlayerButton()
{
    ui->button_addPlayer->setEnabled(true);
}

void MainWindow::maxEntryCheck()
{
    if (entryList.length()==LIMIT)
    {
        ui->button_addPlayer->setEnabled(false);
        ui->button_addPlayer->setText("Max Entries");
    }
    else if (entryList.length()<LIMIT)
    {
        ui->button_addPlayer->setEnabled(true);
        ui->button_addPlayer->setText("Add Player");
    }

}
