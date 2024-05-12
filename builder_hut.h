#ifndef BUILDER_HUT_H
#define BUILDER_HUT_H
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsItem>
#include <QVector>
#include <QPointF>
#include "fence.h"
#include "builder.h"

class builder_hut: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    builder_hut(QGraphicsScene* thescene, QVector<Fence*> fencess, QString builderHutPath, QString builderPath, int builderHeal);
    ~builder_hut();
    QVector<Fence*> fences;
    QPointF origin;
    QString builderHutPath;
    QString builderPath;
    int builderHeal;

public slots:
    void spawnBuilder();

private:
    QGraphicsScene* thescene;
    QTimer timer;
};

#endif
