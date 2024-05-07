#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QGraphicsTextItem>

class myscene : public QGraphicsScene
{
    Q_OBJECT

public:
    myscene(QObject *parent = nullptr);
    void startTimer();
    QGraphicsTextItem *timerDisplay;
    void DisplayLVL2();
    void DisplayLVL3();
    void DisplayLVL4();
    void DisplayLVL5();
    void DisplayFinal();


signals:
    void displayLVL2();
    void displayLVL3();
    void displayLVL4();
    void displayLVL5();
    void displayFinal();
    void mousePresseddd(const QPointF& pos);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private slots:
    void updateTimer();

private:
    QTimer *timer;
    int timeRemaining;
    void updateTimerDisplay();
};

#endif // MYSCENE_H
