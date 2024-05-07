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
    EnemySpawner(QGraphicsScene* thescene, QVector<QVector<QChar>> Boarddata, QString enemyPath, int enemyHealth, int enemyDamage);
    ~EnemySpawner();
    QVector<Fence*> fences;
    QVector<QVector<QChar>> Boarddata2;
    double row;
    double col;
    QString enemyPath;
    int enemyHealth;
    int enemyDamage;
    QTimer timer;

public slots:
    void spawnEnemy();

private:
    QGraphicsScene* thescene;
};

#endif // ENEMYSPAWNER_H
