#include "damageBoosters.h"
#include <QPainter>

damageBoosters::damageBoosters(QObject *parent) : QObject(parent)
{
    QString imgPath = ":/imgs/damageBooster.png";
    QPixmap img(imgPath);
    setPixmap(img.scaled(50, 50));
    setZValue(2);
    setPos(50, 50);
}
