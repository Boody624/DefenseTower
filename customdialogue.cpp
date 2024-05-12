#include "customdialogue.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QAudioOutput>
CustomDialog::CustomDialog(QWidget *parent, QString windowTitle, QString audioPath, qreal playbackRate,
                           QString bgPath, QString message, QString order) : QDialog(parent) {
    this->windowTitle = windowTitle;
    this->audioPath = audioPath;
    this->playbackRate = playbackRate;
    this->bgPath = bgPath;
    this->message = message;
    this->order = order;

    setWindowTitle(windowTitle);
    setFixedSize(800, 800);
    QAudioOutput * bgoutput = new QAudioOutput();
    bgoutput->setVolume(30);

    bgsound->setAudioOutput(bgoutput);
    bgsound->setSource(QUrl(audioPath));
    bgsound->setPlaybackRate(playbackRate);
    bgsound->setLoops(100);
    bgsound->play();

    setupUi();


}

void CustomDialog::setupUi() {
    // Set background image
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(QPixmap(bgPath).scaled(size()));
    backgroundLabel->setGeometry(0, 0, width(), height());

    // Add text label
    QLabel *textLabel = new QLabel(message, this);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet("color: white; font-size: 20px; font-weight: bold;");
    textLabel->setGeometry(50, 50, 700, 200); // Centered horizontally, 50px from the top, and 200px in height

    // Add buttons
    QPushButton *continueButton = new QPushButton(order, this);
    continueButton->setFont(QFont("Arial", 14));
    continueButton->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border: none; padding: 10px 24px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 12px; } QPushButton:hover { background-color: #45a049; }");
    connect(continueButton, &QPushButton::clicked, this, &CustomDialog::accept);
    continueButton->setGeometry(300, 300, 200, 60); // Centered horizontally, 250px from the top, and 60px in height

    QPushButton *exitButton = new QPushButton("Exit", this);
    exitButton->setFont(QFont("Arial", 14));
    exitButton->setStyleSheet("QPushButton { background-color: #f44336; color: white; border: none; padding: 10px 24px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 12px; } QPushButton:hover { background-color: #d32f2f; }");
    connect(exitButton, &QPushButton::clicked, this, &CustomDialog::reject);
    exitButton->setGeometry(300, 400, 200, 60); // Centered horizontally, 350px from the top, and 60px in height
}
