#include "myscene.h"

myscene::myscene() {

}


void myscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        qDebug() << "Mouse clicked at: " << event->scenePos();
        QPointF point = event->scenePos();
        emit mousePresseddd(point);
    }
}

