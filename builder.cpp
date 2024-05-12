#include "builder.h"
#include "fence.h"
#include "enemy.h"
#include <QDebug>
QVector<Fence*> Builder::fences;

Builder::Builder(QPointF original, QString builderPath, int builderHeal) : QObject(), QGraphicsPixmapItem(), origin(original) {
    QString path = builderPath;
    QPixmap img = QPixmap(path);
    setPixmap(img.scaled(50, 50));
    this->heal = builderHeal; // heal value

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Builder::move);

    checkFence = new QTimer(this);
    connect(checkFence, &QTimer::timeout, this, &Builder::checkDamagedFence);
    checkFence->start(500);

    originTimer = new QTimer(this);
    connect(originTimer, &QTimer::timeout, this, &Builder::moveToOrigin);
}

void Builder::move() {
    QList<QGraphicsItem*> collidingItemsList = collidingItems();
    for (int i = 0; i < collidingItemsList.size(); i++) {
        Fence* fence = dynamic_cast<Fence*>(collidingItemsList[i]);
        if (fence && !fence->atFullHealth()) {
            checkFence->stop();
            moveTimer->stop();
            QTimer::singleShot(2000, this, [=]() {
                fence->incHealth(heal);
                qDebug() << "Builder healed fence at" << fence->pos() << "to"
                         << fence->getHealth() << "health" <<"from " << fence->getHealth() - heal << "health";
                if (fence->atFullHealth()) {
                    qDebug() << "Fence at full health, returning to origin now";
                    checkFence->start(500);
                }
                else {
                    qDebug() << "Fence still damaged, moving to next damaged fence";
                    move();
                }
            });
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

    qreal dx = targetPoint.x() - x();
    qreal dy = targetPoint.y() - y();
    qreal distance = qSqrt(dx * dx + dy * dy);
    dx /= distance;
    dy /= distance;
    setPos(x() + dx * 3, y() + dy * 3);
}

void Builder::checkDamagedFence() {
    for (Fence* fence : fences) {
        if (!fence->atFullHealth()) {
            targetPoint = fence->pos();
            qDebug() << "Builder moving to fence at" << targetPoint;
            moveTimer->start(50);
            if(originTimer->isActive())
            {
                originTimer->stop();
            }
            // stop fence checking temporarily
            return;
        }
    }
    // if all fences are fully healed, start moving back to origin
    if (!originTimer->isActive()) {
        originTimer->start(50);
    }
    if (moveTimer->isActive()) {
        moveTimer->stop();
    }
}

void Builder::moveToOrigin() {
    if (pos() == origin) {
        checkFence->start(500);
        originTimer->stop();
        return;
    }
    qreal dx = origin.x() - x();
    qreal dy = origin.y() - y();
    qreal distance = qSqrt(dx * dx + dy * dy);
    dx /= distance;
    dy /= distance;
    setPos(x() + dx * 3, y() + dy * 3);
}
