#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsRectItem>

class HealthBar : public QGraphicsRectItem
{
public:
    HealthBar(qreal maxWidth, qreal height, QGraphicsItem *parent = nullptr);

    void setPercentage(qreal percentage);

private:
    qreal maxWidth;
};

#endif // HEALTHBAR_H
