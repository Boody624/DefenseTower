#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPoint>
#include <QCursor>
#include "str.h"
//forward declaration of fence class
class Fence;
class Castle;
struct Node;

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QString enemyPath, int damage, int health, QString enemyAttack, QString enemyStill, QGraphicsScene *theScene);
    QPoint initial;
    QVector<QPoint> path1;
    int damage;
    QMovie *moveAnimation;
    QGraphicsScene * theScene;
    QMovie *attackAnimation;
    QMovie *stillAnimation;
    Fence* targetedFence;
    int health;
    int c = 0;
    int x_prev;
    int y_prev;
    QTimer collisiontimer;
    static QVector<Fence*> fences;
    static QPoint targetPoint; // Target point for enemy movement
    static QVector<QVector<int>> graph;
    static QVector<QPointF> obstacles;
    static QVector<QVector<int>>Map;
    static QPoint targetPoint1; // Target point for enemy movement
    str* s;
    QTimer *moveTimer; // Timer for enemy movement
    QTimer *moveAlongTimer;
    //QTimer *updateTimer;
    bool hasCollided = false;
    bool fence;
    QVector<QPoint> currentPath;
    bool fenceDestroyed = false;
    int count = 0;
    int frameMoveCounter = 0;
    int frameAttackCounter = 0;
    int frameStillCounter = 0;
    QPoint currentNextPosition;
    QPoint collidingFence;
    QPixmap framePixmap;
    QTimer *pathUpdateTimer;

public slots:
    //void checkCollision();
    void move();
    void doDamage(Fence* fence);
    void onFenceDestroyed();
    void checkCollision();
    void checkCastleCollision();
    void updatePixmap();
    void updateAttack();
    void updateStill();
    QPixmap rotateTowardsCastle(QPixmap originalPixmap);
    void doDamageCastle(Castle* castle);
    void moveAlongPath();
    void updateAnimation(QMovie *animation);
    void updatePath();
    //void updateCurrent();
    //void destroyFence(int x , int y);

private:
    QTimer *castleCollisionTimer;
    QTimer *fenceCollisionTimer;
    QTimer *destroyedTimer;
    // QTimer *checkDestroyedTimer;

signals:
    //void singleShotFinished();
    void moving();
    void still();
    void attacking();
};

#endif // ENEMY_H
