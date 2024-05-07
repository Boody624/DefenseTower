#ifndef BUILDER_H
#define BUILDER_H
#include <QObject>
#include <QPointF>
#include <QGraphicsPixmapItem>
#include <QVector>
#include "fence.h"
class Builder: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Builder(QPointF origin, QString builderPath, int heal);
    void move();
    QPointF origin;
    QString builderPath;
    static QVector<Fence*> fences;
    int heal;
    QPointF targetPoint; // Target point for movement
    void checkDamagedFence();
    void moveToOrigin();
    QTimer *originTimer;

private:
    QTimer *moveTimer; // Timer for movement
    QTimer *checkFence;

};
#endif // BUILDER_H
