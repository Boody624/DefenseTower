#include "login.h"

namespace Ui{
login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_logbutton_clicked()
{

}


void login::on_signbutton_clicked()
{
    //take input from userline and passline and add them into a txt file
    QString username = ui->userline->text();
    QString password = ui->passline->text();

}
}
