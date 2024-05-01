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


signals:
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
