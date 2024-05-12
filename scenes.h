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
#include <QSet>
#include <QTime>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include "castle.h"
#include "defence_unit.h"
#include "fence.h"
#include "enemyspawner.h"
#include "myscene.h"
class Scenes  {
public:
    Scenes(QString designFilePath, QString castlePath, int castleHealth,
           QString defenseTowerPath, QString bulletPath, int bulletDamage,
           QString enemyPath, int enemyHealth, int enemyDamage, QString bgPath,
           QString fencePath, int fenceHealth, QString builderHutPath,
           QString builderPath, int builderHeal, QTime initialTime, QString enemyAttack,
           QString enemyStill, QString soundPath, float speed);
    QGraphicsView* getView();
    QGraphicsView* view;
    myscene* scene;
    QVector<QVector<int>> graph;
    Fence* fence;
    QVector<QVector<QChar>> Boarddata;
    Castle* castle;
    QVector<Fence*> fences;
    Defence_unit* defense_unit;
    EnemySpawner* enemySpawner;
    void readDesignFromFile(const QString& filePath);
    QGraphicsView* renderScene();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QSet<QPoint> fencePositions;
    QString castlePath;
    int castleHealth;
    QString defenseTowerPath;
    QString bulletPath;
    QString soundPath;
    float speed;
    int bulletDamage;
    QString enemyPath;
    QString enemyAttack;
    QString enemyStill;
    int enemyHealth;
    int enemyDamage;
    QString bgPath;
    QString fencePath;
    int fenceHealth;
    QString builderHutPath;
    QString builderPath;
    int builderHeal;
    QTime initialTime;
    void deleteAllObjects();
    QPointF castlePosition;
    void gameOver();
    void changeScore();



    //QVector<QGraphicsItems* > obstacles;

};

#endif // SCENES_H
