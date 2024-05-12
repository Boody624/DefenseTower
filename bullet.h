#ifndef BULLET_H
#define BULLET_H
#include <QCursor>
#include <QPoint>
#include <QtMath>
#include <QLine>
#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QPointF>
#include <QGraphicsScene>
#include <qmath.h>
#include <QLabel>
#include <QAudioOutput>
#include <QMediaPlayer>

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:

public:
    bullet(QPointF origin, QString bulletPath, int bulletDamage, QString soundPath, float speed);
    static int counter;
    float xposition;
    float yposition;
    float initialx;
    float initialy;
    QPointF destination;
    float speed;
    static int damage;
    static int damageCounter;
    QPoint getMousePosition();
    QLine line;
    float distance;
    QTimer timer;
    void setDestination(QPointF destination);
    float slope;
    static bool boosted;
    QString soundPath;
    QAudioOutput *audio;
    QMediaPlayer *player;

public slots:
    void move();
    void incDamage();
    static void boostDamage();
signals:
    void enemyDead();
    void boostHealth();

};

#endif
