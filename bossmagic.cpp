#include "bossmagic.h"
#include "fence.h"
#include "castle.h"

int bossMagic::damage = 50;
QPointF bossMagic::target;

bossMagic::bossMagic(QPointF position): QObject(), QGraphicsPixmapItem()
{
    initialx = this->x();
    initialy = this->y();
    // setting the image of the bullet
    QString path = ":/imgs/bossMagic.png";
    QPixmap img3 = (path);
    setPixmap(img3.scaled(50, 50));
    setPos(position.x(),position.y());
    line.setLine(this->x(), this->y(), bossMagic::target.x(), bossMagic::target.y());
    distance = qSqrt(qPow(line.dx(), 2) + qPow(line.dy(), 2));
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &bossMagic::move);
    timer->start(50);
}

void bossMagic::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(Fence)) {
            Fence* fence = dynamic_cast<Fence*>(colliding_items[i]);
            fence->decHealth(bossMagic::damage);
            qDebug() << "Fence hit with damage " << bossMagic::damage <<Qt::endl;

            if (fence->health <= 0) {
                qDebug() << "Fence destroyed with damage" << bossMagic::damage <<Qt::endl;
            }

            scene()->removeItem(this);
            deleteLater();
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(Castle)) {
            Castle* castle = dynamic_cast<Castle*>(colliding_items[i]);

            // Remove both items from the scene
            qDebug() << "Castle hit" << Qt::endl;
            scene()->removeItem(this);
            deleteLater();

            return; // Exit the loop or function
        }

    }




    if (pos().x() > 0 && pos().y() > 0 && pos().x() + 50 < scene()->sceneRect().right() && pos().y() + 50 < scene()->sceneRect().bottom()) {
        setPos(this->x()+ speed * line.dx() / distance* 2, this->y() + speed * line.dy() / distance *2);
    }
    else {
        scene()->removeItem(this);
        delete this;
    }
}
