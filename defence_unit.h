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

public:
    Defence_unit(QGraphicsScene* thescene, QString defenceTowerPath, QString bulletPath,
                 int bulletDamage, QString soundPath, float speed);
    ~Defence_unit();
    QGraphicsScene* thescene;
    QTimer timer;
    QTimer bullettimer;
    bullet * bull;
    QPointF position;
    QString defenceTowerPath;
    QString bulletPath;
    int bulletDamage;
    static bool multi;
    QString soundPath;
    float speed;


public slots:
    void spawnBullet();
    void spawnBullet2();
    //void addBulletWithDelay(bullet* newBullet, int delay);

signals:
    void incKillCount();
    void incCastleHealth();
};

#endif // DEFENCE_UNIT_H

