#include "enemy.h"
#include "fence.h"
#include "castle.h"
#include <QMessageBox>

// Make target point static
QPoint Enemy::targetPoint;

Enemy::Enemy() : QObject(), QGraphicsPixmapItem() {
    // Setting the image of the enemy
    QString path = ":/imgs/enemy.png";
    QPixmap img = QPixmap(path);
    setPixmap(img.scaled(50, 50));
    setPos(0, 0); // Initial position at the top left corner
    damage = 20; // Set the damage value
    health = 50;
    // Creating the movement timer
    moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(50); // Adjust the interval as needed

}

void Enemy::move() {
    checkCollision();
    // Calculate the direction towards the target point
    if(!hasCollided){
    qreal dx = targetPoint.x() - x();
    qreal dy = targetPoint.y() - y();

    // Calculate the distance to the target point
    qreal distance = qSqrt(dx * dx + dy * dy);

    // Normalize the direction vector
    dx /= distance;
    dy /= distance;

    // Move the enemy towards the target point
    setPos(x() + dx * 2, y() + dy * 2); // Adjust the speed as needed

    }
}

void Enemy::doDamage(Fence* fence)
{
    fence->decHealth(this->damage);
}

void Enemy::onFenceDestroyed()
{
    if (!moveTimer->isActive()) {
        moveTimer->start(50); // Resume movement
    }
}

void Enemy::checkCollision()
{
    moveTimer->stop(); // Stop the movement timer
    QList<QGraphicsItem*> collidingItemsList = collidingItems();
    // Iterate through the list to find the first fence
    for (QGraphicsItem* item : collidingItemsList)
    {
        // Check if the colliding item is a Fence
        Fence* fence = dynamic_cast<Fence*>(item);
        if (fence)
        {
            // Connect the signal from the Fence to the slot in the Enemy
            connect(fence, &Fence::gotDestroyed, this, &Enemy::onFenceDestroyed);

            if (fence->isDestroyed())
            {

            }
            else
            {
                // Inflict damage after a delay
                QTimer::singleShot(2000, this, [=]() {
                    doDamage(fence);
                    moveTimer->start(50); // Resume the movement timer after damage is inflicted
                    hasCollided = true;
                });
            }
            // Exit the loop after processing the first fence
            return;
        }
        Castle* castle = dynamic_cast<Castle*>(item);
        if (castle)
        {
            moveTimer->stop(); // Stop the movement timer
            // Inflict damage to the castle
            QTimer::singleShot(2000, this, [=]() {
                castle->decHealth(damage);
                qDebug() << "Castle health: " << castle->getHealth();
                moveTimer->start(50); // Resume the movement timer after damage is inflicted
                hasCollided = true;
                // Check if the castle is destroyed
                if (castle->isDestroyed())
                {
                    QMessageBox gameOverBox;
                    gameOverBox.setWindowTitle("Game Over");
                    gameOverBox.setText("The enemies have invaded your castle");
                    gameOverBox.setStandardButtons(QMessageBox::Ok);
                    gameOverBox.setDefaultButton(QMessageBox::Ok);
                    gameOverBox.exec();
                    exit(1000); // Exit the game
                }
                else
                {
                }
            });
            return;
        }
    }

    // If no collision with a fence is detected, resume movement if it was stopped
    if (!moveTimer->isActive())
    {
        hasCollided = false;
        moveTimer->start(50);
    }
}

