#include <QMessageBox>
#include "bullet.h"
#include "enemy.h"
int bullet::counter = 0;
bullet::bullet(QPointF position) : QObject(), QGraphicsPixmapItem()
{
    initialx = this->x();
    initialy = this->y();
    // setting the image of the bullet
    QString path = ":/imgs/red_laser.png";
    QPixmap img3 = (path);
    setPixmap(img3.scaled(50, 50));
    setPos(position.x(),position.y());
    damage = 10;
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
            enemy->health -= damage;

            if (enemy->health <= 0) {
                scene()->removeItem(enemy);
                qDebug() << "Enemy killed";
                counter++;

                delete enemy;
            }

            scene()->removeItem(this);
            deleteLater();
            return;
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
        damage = ((damage/10) + damage);
    }
}

