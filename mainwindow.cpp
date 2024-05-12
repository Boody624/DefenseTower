#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QDebug>
#include "storydialogue.h"
#include "optionsdialog.h"

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
    bgoutput = new QAudioOutput();
    currentVolume = 1.0;
    bgoutput->setVolume(currentVolume);
    bgsound->setAudioOutput(bgoutput);
    bgsound->setSource(QUrl("qrc:/sounds/themeMusic.mp3"));
    bgsound->setPlaybackRate(0.8);
    bgsound->setLoops(100);
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
    // game* thegame = new game();
    // thegame->displayFinal();
    QStringList speech = {"Welcome to the Castle!",
                          "The castle had been safe for a long time but a devilish spirit arrived",
                          "The spirit has been attacking the castle and the king is worried", "Wait, what's happening?!",
                          "I've watched you for ages, whispered into the darkest corners of your mind. "
                          "The shadows you fear? They're me. Every chill, every nightmare... it's always been me. "
                          "Only try, and I'll show you what true terror feels like.",
                          "The spirit is already here! We need your help!"};
    QStringList bgs = {":/imgs/1.jpg", ":/imgs/2.jpg", ":/imgs/2.jpg",
                       ":/imgs/2.jpg", ":/imgs/final_boss.png", ":/imgs/2.jpg"};
    QStringList voices = {"qrc:/sounds/1.wav", "qrc:/sounds/2.wav", "qrc:/sounds/3.wav",
                          "qrc:/sounds/4.wav", "qrc:/sounds/5.wav", "qrc:/sounds/6.wav"};
    StoryDialog* story = new StoryDialog(nullptr, bgs, voices, speech);
    story->exec();
}

void MainWindow::on_Options_clicked()
{
    // Create a new dialog for options
    OptionsDialog optionsDialog(this);

    // Set the initial values of volume and difficulty in the dialog
    optionsDialog.setVolume(currentVolume * 100.0);
    optionsDialog.setDifficulty(game::difficulty);

    // Connect signals and slots for updating volume and difficulty
    connect(&optionsDialog, &OptionsDialog::volumeChanged, this, &MainWindow::updateVolume);
    //connect(&optionsDialog, &OptionsDialog::difficultyChanged, this, &MainWindow::updateDifficulty);

    // Open the options dialog
    optionsDialog.exec();
}

void MainWindow::updateVolume(int volume)
{
    // Update the volume of the game with the new value
    // For example, if you have a global audio manager, you can call its setVolume function
    qDebug()<< "the volume is "<<volume;
    currentVolume = volume/100.0;
    bgoutput->setVolume(volume/100.0);

}




