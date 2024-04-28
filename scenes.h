#ifndef SCENES_H
#define SCENES_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include "castle.h"
#include "defence_unit.h"
#include "fence.h"
#include "enemyspawner.h"
#include "myscene.h"
class Scenes  {
public:
    Scenes();
    QGraphicsView* getView();
    QGraphicsView* view;
    myscene* scene;
    QVector<QVector<QChar>> Boarddata;
    Castle* castle;
    Defence_unit* defense_unit;
    EnemySpawner* enemySpawner;
    Fence* fence;
    void readDesignFromFile(const QString& filePath);
    QGraphicsView* renderScene();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENES_H
