#ifndef FINALBOSS_H
#define FINALBOSS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "myscene.h"
class FinalBoss : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit FinalBoss(QGraphicsItem *parent = nullptr, myscene *scene = nullptr);
    myscene *scene;
    bool movedDown = false;
    qreal horizontalSpeed = 10;
    QPointF target;
signals:
    //void defeated();

public slots:
    //void attack(); // Method for the boss's attack
    //void receiveDamage(int damage); // Method to handle receiving
    void move();
    void fire();

private:
    int health; // Boss's health
    QTimer *attackTimer; // Timer for the boss's attacks

    // Add any other properties or methods specific to the final boss
};

#endif // FINALBOSS_H
