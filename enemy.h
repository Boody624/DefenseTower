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
    Enemy(QString enemyPath, int damage, int health);
    int damage;
    QMovie *enemyAnimation;
    Fence* targetedFence;
    int health;
    static QPoint targetPoint; // Target point for enemy movement
    QTimer *moveTimer; // Timer for enemy movement
    bool hasCollided = false;

public slots:
    //void checkCollision();
    void move();
    void doDamage(Fence* fence);
    void onFenceDestroyed();
    void checkCollision();
    void updatePixmap();

private:
    QTimer *checkCollisionTimer;
    QTimer *destroyedTimer;
    // QTimer *checkDestroyedTimer;

signals:
    //void singleShotFinished();
};

#endif // ENEMY_H
