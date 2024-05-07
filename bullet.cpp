#include <QMessageBox>
#include "bullet.h"
#include "enemy.h"
#include "damageboosters.h"
int bullet::counter = 0;
int bullet::damageCounter = 0;
int bullet::damage = 10;
bool bullet::boosted = false;
bullet::bullet(QPointF position, QString bulletPath, int bulletDamage) : QObject(), QGraphicsPixmapItem()
{
    initialx = this->x();
    initialy = this->y();
    // setting the image of the bullet
    QString path = bulletPath;
    QPixmap img3 = (path);
    setPixmap(img3.scaled(50, 50));
    setPos(position.x(),position.y());
    line.setLine(this->x(), this->y(), getMousePosition().x(), getMousePosition().y());
    distance = qSqrt(qPow(line.dx(), 2) + qPow(line.dy(), 2));
}

QPoint bullet::getMousePosition() {
    return QCursor::pos();
}
void bullet::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);
            enemy->health -= bullet::damage;

            if (enemy->health <= 0) {
                scene()->removeItem(enemy);
                qDebug() << "Enemy killed with damage" << bullet::damage <<Qt::endl;
                counter++;
                incDamage();
                delete enemy;
            }

            scene()->removeItem(this);
            deleteLater();
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(damageBoosters)) {
            damageBoosters* booster = dynamic_cast<damageBoosters*>(colliding_items[i]);

            // Remove both items from the scene
            scene()->removeItem(booster);

            boostDamage();
            delete booster;
            // Delete both items
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

void bullet::incDamage() {
    if(counter % 20 == 0 ){
        bullet::damage = ((bullet::damage/10) + bullet::damage);
        bullet::damageCounter++;
    }
}

void bullet::boostDamage() {
    int dmg = bullet::damage;
    bullet::damage = 5 * bullet::damage;
    //bullet::boosted = true;
    qDebug() << "Damage Boosted to " << bullet::damage << Qt::endl;
    QTimer::singleShot(30000, [=]() {
        qDebug() << "Damage Boost Expired" << Qt::endl;
        bullet::damage = (dmg + dmg/10 * damageCounter);
        //bullet::boosted = false;
    });
}

