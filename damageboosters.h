#ifndef DAMAGEBOOSTERS_H
#define DAMAGEBOOSTERS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimerEvent>

class damageBoosters : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    damageBoosters(QObject *parent = nullptr);

};

#endif // DAMAGEBOOSTERS_H
