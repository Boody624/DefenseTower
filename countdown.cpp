#include "countdown.h"
#include "storydialogue.h"
CountdownTimer::CountdownTimer(QGraphicsItem *parent, QTime initial) : QGraphicsTextItem(parent) {
    setTime(initial.minute(), initial.second()); // Set initial time to 5 minutes
    QString timeString = time.toString("mm:ss");
    setPlainText(timeString);
    setZValue(2);
    setVisible(true);
    setPos(10, 0);
    QFont font;
    font.setPointSize(30); // Adjust the font size as needed
    font.setItalic(true);
    setDefaultTextColor(Qt::black);
    font.setFamily("Roboto");
    setFont(font);
    QFontMetrics fm(font);
    qreal letterSpacing = fm.averageCharWidth() * 0.3; // Adjust this value to increase or decrease spacing
    font.setLetterSpacing(QFont::AbsoluteSpacing, letterSpacing);
    setFont(font);
    connect(&timer, &QTimer::timeout, this, &CountdownTimer::updateTime);
    timer.start(1000); // Start the timer with a timeout of 1 second
}

void CountdownTimer::start() {
    timer.start(1000);
}

void CountdownTimer::setTime(int minutes, int seconds) {
    time = QTime(0, minutes, seconds);
}

void CountdownTimer::updateTime() {
    time = time.addSecs(-1); // Decrement time by 1 second
    if (time.minute() == 0 && time.second() == 0) {
        timer.stop();
        setPlainText("00:00");

        emit Won();
        return;
    }
    else if (time.minute() == 4 && time.second() == 45) {
        emit displayLVL2();
    }
    else if (time.minute() == 4 && time.second() == 30) {
        emit displayLVL3();
    }
    else if (time.minute() == 4 && time.second() == 15) {
        emit displayLVL4();
    }
    else if (time.minute() == 4 && time.second() == 00) {
        emit displayLVL5();
    }
    else if (time.minute() == 3 && time.second() == 40) {
        emit displayFinal();
    }
    setPlainText(QString("%1").arg(time.toString("mm:ss")));
}
