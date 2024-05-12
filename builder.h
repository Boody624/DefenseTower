#ifndef BUILDER_H
#define BUILDER_H
#include <QObject>
#include <QPointF>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <QMovie>
#include "fence.h"
class Builder: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Builder(QPointF origin, QString builderPath, int heal);
    void move();
    QPointF origin;
    QString builderPath;
    QString builderHealPath;
    QString builderStill;

    QPoint dest;
    static QVector<Fence*> fences;
    static QVector<QVector<int>>Map;
    static QVector<QPointF> obstac;
    static QVector<Builder*> builders;
    QVector<QPoint> currentPath;
    bool first = true;
    int heal;
    QPointF targetPoint;
    void checkDamagedFence();
    void moveToOrigin();
    QTimer *originTimer;
    QMovie *moveAnimation;
    QMovie *healAnimation;
    QMovie *stillAnimation;
    void Heal();
public slots:
    void updatePixmap();
    void updateHeal();
    void updateStill();

private:
    QTimer *moveTimer;
    QTimer *checkFence;
signals:
    void moving();
    void still();
    void healing();
};
#endif
