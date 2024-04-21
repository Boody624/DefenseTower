#include "bullet.h"
bullet::bullet() : QObject(), QGraphicsPixmapItem()
{
    initialx = this->x();
    initialy = this->y();
    // setting the image of the bullet
    QString path = ":/imgs/red_laser.png";
    QPixmap img3 = (path);
    setPixmap(img3.scaled(50, 50));
    setPos(500, 400);
    line.setLine(this->x(), this->y(), getMousePosition().x(), getMousePosition().y());
}

QPoint bullet::getMousePosition() {
    return QCursor::pos();
}
void bullet::move()
{
    if (pos().x() > 0 && pos().y() > 0 && pos().x()+50 < scene()->sceneRect().right() && pos().y()+50 < scene()->sceneRect().bottom())
    {

     setPos(x()+line.dx()/10, y()+line.dy()/10);
    }
    else
    {
        scene()->removeItem(this);
        delete this;
    }

}

