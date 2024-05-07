// HealthBar.cpp
#include "healthbar.h"
#include <QBrush>

HealthBar::HealthBar(qreal maxWidth, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), maxWidth(maxWidth)
{
    setRect(0, 0, maxWidth, height);
    setBrush(QBrush(Qt::green)); // Initial color of the health bar
}

void HealthBar::setPercentage(qreal percentage)
{
    qreal newWidth = maxWidth * percentage;
    setRect(0, 0, newWidth, rect().height());

    // Change color based on health level (optional)
    if (percentage <= 0.25) {
        setBrush(QBrush(Qt::red)); // Low health, red color
    } else if (percentage <= 0.5) {
        setBrush(QBrush(Qt::yellow)); // Moderate health, yellow color
    } else {
        setBrush(QBrush(Qt::green)); // High health, green color
    }
}
