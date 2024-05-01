#include "builder.h"
#include <QTimer>
#include <QDebug>

Builder::Builder(QPointF original, QVector<Fence*> fences) : QObject(), QGraphicsPixmapItem(), origin(original), fences(fences) {
    // Setting the image of the enemy
    QString path = ":/imgs/builder.png";
    QPixmap img = QPixmap(path);
    setPixmap(img.scaled(50, 50));
    heal = 10; // Set the heal value

    // Creating and starting the movement timer
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Builder::move);

    // Creating the fence check timer
    checkFence = new QTimer(this);
    connect(checkFence, &QTimer::timeout, this, &Builder::checkDamagedFence);
    checkFence->start(500); // Adjust the interval as needed
}

void Builder::move() {
    //if it hits a fence, stop moving
    QList<QGraphicsItem*> collidingItemsList = collidingItems();
    for (int i = 0; i < collidingItemsList.size(); i++) {
        if (Fence* fence = dynamic_cast<Fence*>(collidingItemsList[i])) {
            // Stop the enemy and make the fence start to take damage every 2 seconds
            moveTimer->stop();
            QTimer* healTimer = new QTimer();
            connect(healTimer, &QTimer::timeout, [=]() {
                if (!fence->atFullHealth()) { // Check if fence exists and not destroyed
                    fence->incHealth(heal); // Damage the fence
                    qDebug() << "Fence at: " << fence->x() << ", " << fence->y() << " healed by " << heal;
                    qDebug()<< "Fence's health is at " <<fence->getHealth();

                    if (fence->atFullHealth()) {
                        targetPoint = origin;
                        moveTimer->start();
                        healTimer->stop();
                        healTimer->deleteLater(); // Cleanup timer
                    }

                }
                else {
                    targetPoint = origin;
                    moveTimer->start();
                    healTimer->stop();
                    healTimer->deleteLater(); // Cleanup timer
                }
            });
            healTimer->start(2000);
            return;
        }

        if(Enemy* enemy = dynamic_cast<Enemy*>(collidingItemsList[i])){
            this->hide();
            QTimer::singleShot(2000, this, [=]() {
                delete this;
            });
            return;
        }
    }
    // Calculate the direction towards the target point
    qreal dx = targetPoint.x() - x();
    qreal dy = targetPoint.y() - y();
    // Calculate the distance to the target point
    qreal distance = qSqrt(dx * dx + dy * dy);
    // Normalize the direction vector
    dx /= distance;
    dy /= distance;
    setPos(x() + dx * 2, y() + dy * 2);
}

void Builder::checkDamagedFence(){
    for (int i = 0; i < fences.size(); i++) {
        if (!fences[i]->atFullHealth()) {
            qDebug() << "Damaged fence found at: " << fences[i]->x() << ", " << fences[i]->y()<< "health "<<fences[i]->getHealth();
            targetPoint = (fences[i]->pos());
            if(!moveTimer->isActive()){
                moveTimer->start();
            }
            return;
        }
    }
}
