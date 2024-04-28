#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPoint>
#include <QCursor>
//forward declaration of fence class
class Fence;

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy();
    int damage;
    Fence* targetedFence;
    static QPoint targetPoint; // Target point for enemy movement
    QTimer *moveTimer; // Timer for enemy movement


public slots:
    void checkCollision();
    void move();
    //void damageFence();


private:
    QTimer *checkCollisionTimer;
    // QTimer *damageTimer;
    // QTimer *checkDestroyedTimer;


};

#endif // ENEMY_H
