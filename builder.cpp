#include "builder.h"
#include <QTimer>

Builder::Builder() : QObject(), QGraphicsPixmapItem(), targetPoint(500, 600) {
    // Setting the image of the enemy
    QString path = ":/imgs/builder.png";
    QPixmap img = QPixmap(path);
    setPixmap(img.scaled(50, 50));
    setPos(0, 0); // Initial position at the top left corner

    // Creating and starting the movement timer
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Builder::move);
    moveTimer->start(50); // Adjust the interval as needed
}
//make a function to go to the damaged fence and then come back to the point of origin
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
                    if (fence->atFullHealth()) {
                        moveTimer->start();
                        healTimer->stop();
                        healTimer->deleteLater(); // Cleanup timer
                    }
                } else {
                    // Fence no longer exists or is destroyed, resume enemy movement
                    moveTimer->start();
                    healTimer->stop();
                    healTimer->deleteLater(); // Cleanup timer
                }
            });
            healTimer->start(2000);
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
    // Move the enemy towards the target point
    setPos(x() + dx * 10, y() + dy * 10);
}

