#ifndef BULLET_H
#define BULLET_H
#include <QCursor>
#include <QPoint>
#include <QtMath>
#include <QLine>
#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>


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
    float speed = 50;
    float damage = 10;
    QPoint getMousePosition();
    QLine line;
    float distance;
    QTimer timer;
    void setDestination(QPointF destination);
public slots:
    void move();
};

#endif // BULLET_H
