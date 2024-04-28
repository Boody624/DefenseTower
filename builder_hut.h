#ifndef BUILDER_HUT_H
#define BUILDER_HUT_H
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsItem>
#include <QVector>
#include "fence.h"
#include "builder.h"
class builder_hut: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    builder_hut(QGraphicsScene* thescene);
    ~builder_hut();
    QVector<Fence*> fences;

public slots:
    void spawnBuilder();

private:
    QGraphicsScene* thescene;
    QTimer timer;
};

#endif // BUILDER_HUT_H
