#include "editplayer.h"
#include "ui_editplayer.h"

editPlayer::editPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editPlayer)
{
    ui->setupUi(this);


    incMode=1;

}

editPlayer::~editPlayer()
{
    delete ui;
}

void editPlayer::on_button_incOne_clicked()
{
    score=score+incMode;
    zeroGuard();
    ui->display_score->display(score);
}



void editPlayer::on_button_incFive_clicked()
{
    score=score+5*incMode;
    zeroGuard();
    ui->display_score->display(score);
}

void editPlayer::on_button_incTwentyFive_clicked()
{
    score=score+25*incMode;
    zeroGuard();
    ui->display_score->display(score);
}

void editPlayer::loadEntryPtr(entry * input)
{
    entryPtr=input;
}

void editPlayer::on_button_confirm_clicked()
{

    emptyNameGuard();
    entryPtr->loadPlayer(score,ui->input_name->text());
    entryPtr->refreshView();
    this->close();
 }



void editPlayer::on_button_toggleIncMode_clicked()
{
    if (incMode==1)
    {
        incMode=-1;
        ui->label_incMode->setText("-");
    }
    else
    {
        incMode=1;
        ui->label_incMode->setText("+");
    }

}

void editPlayer::zeroGuard()
{
    if (score<0) score=0;
}

void editPlayer::emptyNameGuard()
{
    if (QString::compare(ui->input_name->text(),"",Qt::CaseSensitive)==0)
    {
        ui->input_name->setText("name");

    }
}

void editPlayer::loadPlayerData()
{
    name=entryPtr->getPlayer().getName();
    score=entryPtr->getPlayer().getScore();

    ui->input_name->setText(name);
    ui->display_score->display(score);

}
