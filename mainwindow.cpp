#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set background image
    QPixmap backgroundImage(":imgs/design.png");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), backgroundImage);
    this->setPalette(palette);
    //set audio
    QAudioOutput * bgoutput = new QAudioOutput();
    bgoutput->setVolume(30);

    bgsound->setAudioOutput(bgoutput);
    bgsound->setSource(QUrl("qrc:/sounds/bgsound.wav"));
    bgsound->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Exit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_Start_clicked()
{
    this->hide();
    MainWindow::bgsound->stop();
    // Create the scene
    game* thegame = new game();
    thegame->displayFinal();

}

void MainWindow::on_Options_clicked()
{

}

