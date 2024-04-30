#ifndef BULLET_H
#define BULLET_H
#include <QCursor>
#include <QPoint>
#include <QLine>
#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include<qmath.h>

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:

public:
    bullet();
    static int counter;
    float xposition;
    float yposition;
    float initialx;
    float initialy;
    float speed = 20;
    float damage = 10;
    QPoint getMousePosition();
    QLine line;
    float distance;
    QTimer timer;
    float slope;
    void setDestination(QPointF destination);

public slots:
    void move();
};

#endif // BULLET_H
