#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QDebug>
#include <QObject>
class myscene : public QGraphicsScene
{
    Q_OBJECT

public:
    myscene();

signals:
    void mousePresseddd(const QPointF& pos);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MYSCENE_H
