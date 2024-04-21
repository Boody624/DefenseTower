#include "tower.h"
#include "bullet.h"
#include <QCursor>
#include<QPoint>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QEvent>

tower::tower() {

    QString path = ":/imgs/design.png";
    QPixmap img3 = (path);
    setPixmap(img3.scaled(100, 100));
}
void tower::keyPressEvent(QKeyEvent *Event)
{
    if (Event->key() == Qt::Key_Space)
    {
        bullet *bllet = new bullet();
        bllet->setPos(this->x(), this->y());
        scene()->addItem(bllet);
    }
}

void tower::death()
{
    if (health == 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

