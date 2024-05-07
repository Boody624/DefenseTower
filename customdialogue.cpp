#include "customdialogue.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

CustomDialog::CustomDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Congratulations!");
    setFixedSize(800, 800);
    setupUi();
}

void CustomDialog::setupUi() {
    // Set background image
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(QPixmap(":/imgs/design.png").scaled(size()));
    backgroundLabel->setGeometry(0, 0, width(), height());

    // Add text label
    QLabel *textLabel = new QLabel("You have won the level! Continue?", this);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet("color: white; font-size: 20px;");
    textLabel->setGeometry(100, 100, 600, 100);

    // Add buttons
    QPushButton *continueButton = new QPushButton("Continue", this);
    connect(continueButton, &QPushButton::clicked, this, &CustomDialog::accept);
    continueButton->setGeometry(200, 600, 200, 50);

    QPushButton *exitButton = new QPushButton("Exit", this);
    connect(exitButton, &QPushButton::clicked, this, &CustomDialog::reject);
    exitButton->setGeometry(400, 600, 200, 50);
}

