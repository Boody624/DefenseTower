#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsItem>
#include <QVector>
#include "fence.h"
#include "enemy.h"

class EnemySpawner : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    EnemySpawner(QGraphicsScene* thescene, QVector<QVector<QChar>> Boarddata);
    ~EnemySpawner();
    QVector<Fence*> fences;
    QVector<QVector<QChar>> Boarddata2;
    double row;
    double col;
public slots:
    void spawnEnemy();

private:
    QGraphicsScene* thescene;
    QTimer timer;
};

#endif // ENEMYSPAWNER_H
