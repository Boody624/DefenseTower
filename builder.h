#ifndef BUILDER_H
#define BUILDER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include "fence.h"
class Builder: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Builder();
    void move();
    int heal;
private:
    QTimer *moveTimer; // Timer for movement
    QPoint targetPoint; // Target point for movement
};
#endif // BUILDER_H
