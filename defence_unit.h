#ifndef DEFENCE_UNIT_H
#define DEFENCE_UNIT_H
#include <QObject>
#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QPointF>
class Defence_unit : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    QGraphicsScene* thescene;
    QTimer timer;
    QTimer bullettimer;
    bullet * bull;
public:
    Defence_unit(QGraphicsScene* thescene, QString defenceTowerPath, QString bulletPath, int bulletDamage);
    ~Defence_unit();
    QPointF position;
    QString defenceTowerPath;
    QString bulletPath;
    int bulletDamage;

public slots:
    void spawnBullet();
};

#endif // DEFENCE_UNIT_H

