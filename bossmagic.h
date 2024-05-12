
#ifndef BOSSMAGIC_H
#define BOSSMAGIC_H
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
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QMovie>
class bossMagic: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    bossMagic(QPointF position);
    static int damage;
    float xposition;
    float yposition;
    float initialx;
    float initialy;
    QLine line;
    float distance;
    QTimer *timer;
    float speed = 10;
    void setDestination(QPointF destination);
    float slope;
    static QPointF target;
    QMovie *moveAnimation;
    void updatePixmap();
    QAudioOutput *audio;
    QMediaPlayer *player;
public slots:
    void move();
signals:
    void fired();
};

#endif
