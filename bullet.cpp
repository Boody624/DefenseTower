#include <QMessageBox>
#include "bullet.h"
#include "enemy.h"
int bullet::counter = 0;
bullet::bullet() : QObject(), QGraphicsPixmapItem()
{
    initialx = this->x();
    initialy = this->y();
    // setting the image of the bullet
    QString path = ":/imgs/red_laser.png";
    QPixmap img3 = (path);
    setPixmap(img3.scaled(50, 50));
    //setPos(879,435);
    line.setLine(this->x(), this->y(), getMousePosition().x(), getMousePosition().y());
    distance = qSqrt(qPow(line.dx(), 2) + qPow(line.dy(), 2));
}

QPoint bullet::getMousePosition() {
    return QCursor::pos();
}
void bullet::move()
{
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for (int i =0; i<colliding_items.size(); i++){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            counter++;
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    if(counter == 50){
        QMessageBox gameOverBox;
        gameOverBox.setWindowTitle("Game Over");
        gameOverBox.setText("You have won");
        gameOverBox.setStandardButtons(QMessageBox::Ok);
        gameOverBox.setDefaultButton(QMessageBox::Ok);
        gameOverBox.exec();
        exit(2000);
    }
    if (pos().x() > 0 && pos().y() > 0 && pos().x()+50 < scene()->sceneRect().right() && pos().y()+50 < scene()->sceneRect().bottom())
    {

        setPos(this->x()+ speed * line.dx() / distance* 2, this->y() + speed * line.dy() / distance *2);
    }
    else
    {
        scene()->removeItem(this);
        delete this;
    }

}

