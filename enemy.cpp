#include "enemy.h"
#include <QDebug>
#include <QGraphicsScene>
#include <fence.h>
#include <QMessageBox>

// Make target point static
QPoint Enemy::targetPoint;

Enemy::Enemy() : QObject(), QGraphicsPixmapItem() {
    // Setting the image of the enemy
    QString path = ":/imgs/enemy.png";
    QPixmap img = QPixmap(path);
    setPixmap(img.scaled(50, 50));
    setPos(0, 0); // Initial position at the top left corner
    damage = 50; // Set the damage value
    // Creating the movement timer
    moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(50); // Adjust the interval as needed
    checkCollisionTimer = new QTimer(this);
    connect(checkCollisionTimer, SIGNAL(timeout()), this, SLOT(checkCollision()));
    checkCollisionTimer->start(50);
    // damageTimer = nullptr; // Initialize damageTimer to nullptr
}

void Enemy::move() {
    // Calculate the direction towards the target point
    qreal dx = targetPoint.x() - x();
    qreal dy = targetPoint.y() - y();

    // Calculate the distance to the target point
    qreal distance = qSqrt(dx * dx + dy * dy);

    // Normalize the direction vector
    dx /= distance;
    dy /= distance;

    // Move the enemy towards the target point
    setPos(x() + dx * 2, y() + dy * 2); // Adjust the speed as needed

    // If the enemy reaches the target point, stop moving
    if (pos().toPoint() == targetPoint) {
        moveTimer->stop();
        // Delay the game over message using a QTimer
        QTimer::singleShot(1000, this, [=]() {
            QMessageBox gameOverBox;
            gameOverBox.setWindowTitle("Game Over");
            gameOverBox.setText("The enemy has reached the target!");
            gameOverBox.setStandardButtons(QMessageBox::Ok);
            gameOverBox.setDefaultButton(QMessageBox::Ok);
            gameOverBox.exec();
            exit(2000);

        });
    }
}
void Enemy::checkCollision()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Fence)) {
            Fence* fence = dynamic_cast<Fence*>(colliding_items[i]);
            targetedFence = fence;
            if(!targetedFence->isDestroyed()){
                qDebug() << "Collision detected";
                this->moveTimer->stop();
                fence->decHealth(this->damage);
                checkCollisionTimer->stop();
                if(targetedFence->getHealth()<=0){
                    qDebug() << "Fence is destroyed in the collision";
                    checkCollisionTimer->start(50);
                    moveTimer->start(50); // Resume the movement timer
                    return;
                }
                QTimer::singleShot(2000, this, [=]() {
                    // Resume the original timer
                    checkCollisionTimer->start(50);
                    moveTimer->start(50); // Resume the movement timer
                });
            }
            else{
                qDebug() << "Fence is destroyed";
                moveTimer->start(50); // Resume the movement timer
                return;
            }
        }
    }
}

