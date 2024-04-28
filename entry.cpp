#include "entry.h"
#include "ui_entry.h"
#include "mainwindow.h"


entry::entry(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::entry)
{
    ui->setupUi(this);
}

entry::~entry()
{
    delete ui;
}

void entry::on_logbutton_clicked()
{
    //check if the username and password are in the txt file
    QString username = ui->userline->text();
    QString password = ui->passline->text();
    QString path = ":/stream/users.txt";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Could not open file for reading";
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line == username + " " + password) {
            //if the username and password are in the txt file, open the main window
            ui->already->setText("Login successful!");
            MainWindow *main = new MainWindow();
            main->show();
            this->close();
        }
    }
    ui->already->setText("Invalid username or password.");
    file.close();
}


void entry::on_signbutton_clicked()
{
    //sign up the user
    QString path = ":/stream/users.txt";
    QFile file(path);
    file.open(QFile::ReadWrite | QFile::Text);
    if (!file.isOpen()){
        qDebug() << "Could not open file for writing";
        return;
    }
    QString username = ui->userline->text();
    QString password = ui->passline->text();
    QTextStream out(&file);
    out << username + " " + password + "\n";
    file.flush();
    file.close();
    ui->already->setText("Account created! Please login now.");
}

