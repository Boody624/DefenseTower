#include "myscene.h"

myscene::myscene(QObject *parent) : QGraphicsScene(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &myscene::updateTimer);
    timer->setInterval(1000); // Update timer every second

    // Create and initialize the timer display
    timerDisplay = new QGraphicsTextItem();
    updateTimerDisplay(); // Update the initial display

}


void myscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPointF point = event->scenePos();
        emit mousePresseddd(point);
    }
}
void myscene::startTimer() {
    timeRemaining = 5 * 60; // 5 minutes in seconds
    timer->start();
}
void myscene::updateTimer()
{
    if (timeRemaining > 0) {
        timeRemaining--;
        updateTimerDisplay();
    } else {
        timer->stop();
        // Handle timer expiration
    }
}
void myscene::updateTimerDisplay() {
    int minutes = timeRemaining / 60;
    int seconds = timeRemaining % 60;
    QString displayText = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    timerDisplay->setPlainText(displayText);
    timerDisplay->setPos(100, 100); // Set position of the timer display
}
void myscene::DisplayLVL2()
{
    emit displayLVL2();
}
void myscene::DisplayLVL3()
{
    emit displayLVL3();
}
void myscene::DisplayLVL4()
{
    emit displayLVL4();
}
void myscene::DisplayLVL5()
{
    emit displayLVL5();
}
void myscene::DisplayFinal()
{
    emit displayFinal();
}
