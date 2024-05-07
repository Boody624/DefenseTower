#include "builder.h"
#include "fence.h"
#include "enemy.h"
#include <QDebug>
QVector<Fence*> Builder::fences;

Builder::Builder(QPointF original, QString builderPath, int builderHeal) : QObject(), QGraphicsPixmapItem(), origin(original) {
    // Setting the image of the builder
    QString path = builderPath;
    QPixmap img = QPixmap(path);
    setPixmap(img.scaled(50, 50));
    this->heal = builderHeal; // Set the heal value

    // Creating the movement timer
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Builder::move);

    // Creating the fence check timer
    checkFence = new QTimer(this);
    connect(checkFence, &QTimer::timeout, this, &Builder::checkDamagedFence);
    checkFence->start(500); // Adjust the interval as needed

    // Creating the origin timer
    originTimer = new QTimer(this);
    connect(originTimer, &QTimer::timeout, this, &Builder::moveToOrigin);
}

void Builder::move() {
    // Check for collision with fences or enemies
    QList<QGraphicsItem*> collidingItemsList = collidingItems();
    for (int i = 0; i < collidingItemsList.size(); i++) {
        Fence* fence = dynamic_cast<Fence*>(collidingItemsList[i]);
        if (fence && !fence->atFullHealth()) {
            // Stop the builder and start healing the fence
            checkFence->stop();
            moveTimer->stop();
            QTimer::singleShot(2000, this, [=]() {
                fence->incHealth(heal);
                qDebug() << "Builder healed fence at" << fence->pos() << "to"
                         << fence->getHealth() << "health" <<"from " << fence->getHealth() - heal << "health";
                if (fence->atFullHealth()) {
                    qDebug() << "Fence at full health, returning to origin now";
                    checkFence->start(500); // Resume fence checking
                }
                else {
                    qDebug() << "Fence still damaged, moving to next damaged fence";
                    move();
                }
            });
            return;
        }
        if(Enemy* enemy = dynamic_cast<Enemy*>(collidingItemsList[i])){
            // Hide and delete the builder if colliding with an enemy
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
    setPos(x() + dx * 3, y() + dy * 3);
}

void Builder::checkDamagedFence() {
    // Iterate through fences to find a damaged one
    for (Fence* fence : fences) {
        if (!fence->atFullHealth()) {
            // Found a damaged fence, move towards it
            targetPoint = fence->pos();
            qDebug() << "Builder moving to fence at" << targetPoint;
            moveTimer->start(50);
            if(originTimer->isActive())
            {
                originTimer->stop();
            }
            // Stop fence checking temporarily
            return;
        }
    }
    // If all fences are fully healed, start moving back to origin
    if (!originTimer->isActive()) {
        originTimer->start(50);
    }
    if (moveTimer->isActive()) {
        moveTimer->stop();
    }
}

void Builder::moveToOrigin() {
    if (pos() == origin) {
        // Reached the origin, resume fence checking
        checkFence->start(500);
        originTimer->stop();
        return;
    }
    // Calculate the direction towards the origin
    qreal dx = origin.x() - x();
    qreal dy = origin.y() - y();
    // Calculate the distance to the origin
    qreal distance = qSqrt(dx * dx + dy * dy);
    // Normalize the direction vector
    dx /= distance;
    dy /= distance;
    setPos(x() + dx * 3, y() + dy * 3);
}
