#ifndef TOWER_H
#define TOWER_H
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QEvent>
class tower : public QGraphicsPixmapItem
{
public:
    tower();
    float health = 3;
    void death();
    void keyPressEvent(QKeyEvent* Event);
};

#endif // TOWER_H

