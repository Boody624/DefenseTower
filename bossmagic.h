#ifndef BOSSMAGIC_H
#define BOSSMAGIC_H
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

class bossMagic: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    bossMagic(QPointF position);
    static int damage;
    float xposition;
    float yposition;
    float initialx;
    float initialy;
    QLine line;
    float distance;
    QTimer *timer;
    float speed = 30;
    void setDestination(QPointF destination);
    float slope;
    static QPointF target;
public slots:
    void move();
};

#endif // BOSSMAGIC_H
