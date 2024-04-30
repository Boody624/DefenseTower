#include "defence_unit.h"
#include "bullet.h"
#include <QDebug>
Defence_unit::Defence_unit(QGraphicsScene* thescene) {
    this->thescene = thescene;
    thescene->addItem(this);

    // setting the image
    QString path = ":/imgs/wizardTower.png";
    QPixmap img3 = (path);
    setPixmap(img3.scaled(50, 50));
}
Defence_unit::~Defence_unit()
{
    QObject::disconnect(&timer,&QTimer::timeout,this,&Defence_unit::spawnBullet);
    delete bull;
}
void Defence_unit::spawnBullet()
{
    xpos = this->x();
    ypos = this->y();
    qDebug() << "this is the x and y pos " << this->x() << " " << this->y();
    bull = new bullet();
    bull->setPos(xpos, ypos);
    scene()->addItem(bull);

    QObject::connect(&bullettimer,&QTimer::timeout,bull,&bullet::move);
    bullettimer.start(50);
}

