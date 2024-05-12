#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QGraphicsTextItem>
#include <QTimer>
#include <QTime>
#include <QFont>
#include <QFontMetrics>
#include <QObject>
#include "scenes.h"

class CountdownTimer : public QGraphicsTextItem {
    Q_OBJECT
public:
    CountdownTimer(QGraphicsItem *parent, QTime initial);

    void start();

    void setTime(int minutes, int seconds);

private:
    QTime time;
    QTimer timer;

private slots:
    void updateTime();

signals:
    void displayLVL2();
    void displayLVL3();
    void displayLVL4();
    void displayLVL5();
    void displayFinal();
    void Won();
};

#endif // COUNTDOWN_H
