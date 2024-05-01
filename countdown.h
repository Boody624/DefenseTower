#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QGraphicsTextItem>
#include <QTimer>
#include <QTime>
#include <QFont>
#include <QFontMetrics>

class CountdownTimer : public QGraphicsTextItem {
public:
    CountdownTimer(QGraphicsItem *parent = nullptr) : QGraphicsTextItem(parent) {
        setTime(5, 0); // Set initial time to 5 minutes
        setPlainText("05:00");
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

    void start() {
        timer.start(1000);
    }

    void setTime(int minutes, int seconds) {
        time = QTime(0, minutes, seconds);
    }

private:
    QTime time;
    QTimer timer;

private slots:
    void updateTime() {
        time = time.addSecs(-1); // Decrement time by 1 second
        if (time.minute() == 0 && time.second() == 0) {
            timer.stop();
            setPlainText("00:00");
            return;
        }
        setPlainText(QString("%1").arg(time.toString("mm:ss")));
    }
};

#endif // COUNTDOWN_H
