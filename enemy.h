#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPoint>
#include <QtMath>
#include <QLine>
#include <QGraphicsScene>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QPoint m_destination;
    QTimer *m_movementTimer;
    qreal m_speed;
public:
    Enemy();
    float xposition;
    float yposition;
    float initialx;
    float initialy;
    float speed = 50;
    float damage = 10;
    QPoint getDestination();
    QLine line;
    float distance;
public slots:
    void move();
};

#endif // ENEMY_H
