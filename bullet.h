#ifndef BULLET_H
#define BULLET_H
#include <QCursor>
#include <QPoint>
#include <QtMath>
#include <QLine>
#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QPointF>
#include <QGraphicsScene>
#include <qmath.h>

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:

public:
    bullet(QPointF origin);
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
    void setDestination(QPointF destination);
    float slope;
public slots:
    void move();
    void incDamage();
};

#endif // BULLET_H
