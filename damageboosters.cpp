#include "damageBoosters.h"
#include <QPainter>

damageBoosters::damageBoosters(QObject *parent, QString path) : QObject(parent)
{
    this->path = path;
    QPixmap img(path);
    setPixmap(img.scaled(50, 50));
    setZValue(2);
    setPos(50, 50);
}
