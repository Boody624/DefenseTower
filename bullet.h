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
    float xposition;
    float yposition;
    float initialx;
    float initialy;
    float speed = 50;
    float damage = 10;
    QPoint getMousePosition();
    QLine line;
    float distance;
public slots:
    void move();
};

#endif // BULLET_H
