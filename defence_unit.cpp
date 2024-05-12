#include "defence_unit.h"
#include "bullet.h"
#include <QDebug>

bool Defence_unit::multi = false;

Defence_unit::Defence_unit(QGraphicsScene* thescene, QString defenceTowerPath, QString bulletPath,
                           int bulletDamage, QString soundPath, float speed) {
    this->thescene = thescene;
    thescene->addItem(this);
    this->speed = speed;
    this->defenceTowerPath = defenceTowerPath;
    this->bulletPath = bulletPath;
    this->bulletDamage = bulletDamage;
    this->soundPath = soundPath;
    setZValue(2);
    //setScale(0.7);
    // setting the image
    QString path = defenceTowerPath;
    QPixmap img3 = (path);
    setPixmap(img3.scaled(150, 150));
    setScale(0.9);


}
Defence_unit::~Defence_unit()
{
    QObject::disconnect(&timer,&QTimer::timeout,this,&Defence_unit::spawnBullet);
    //delete bull;
}
void Defence_unit::spawnBullet()
{
    float xpos = this->x();
    float ypos = this->y();
    if (multi)
    {
        spawnBullet2();

        QTimer::singleShot(500, [=]() {
            spawnBullet2(); //
        });
        QTimer::singleShot(1000, [=]() {
            spawnBullet2(); //
        });
    }
    else{

        bull = new bullet(position, bulletPath, bulletDamage, soundPath, speed);
        bull->setPos(xpos, ypos);
        scene()->addItem(bull);

        QObject::connect(&bullettimer,&QTimer::timeout,bull,&bullet::move);
        QObject::connect(bull,&bullet::enemyDead,this,&Defence_unit::incKillCount);
        QObject::connect(bull, &bullet::boostHealth, this, &Defence_unit::incCastleHealth);
        bullettimer.start(50);
    }
}

void Defence_unit::spawnBullet2()
{
    float xpos = this->x();
    float ypos = this->y();

    bull = new bullet(position, bulletPath, bulletDamage, soundPath, speed);
    bull->setPos(xpos, ypos);
    scene()->addItem(bull);

    QObject::connect(&bullettimer,&QTimer::timeout,bull,&bullet::move);
    QObject::connect(bull,&bullet::enemyDead,this,&Defence_unit::incKillCount);
    QObject::connect(bull, &bullet::boostHealth, this, &Defence_unit::incCastleHealth);
    bullettimer.start(50);
}


// void Defence_unit::addBulletWithDelay(bullet *newBullet, int delay)
// {
//     QTimer::singleShot(delay, [=]() {
//         scene()->addItem(newBullet);
//         bullettimer.start(50);
//     });
// }

