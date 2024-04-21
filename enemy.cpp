#include "enemy.h"

Enemy::Enemy() : QGraphicsPixmapItem(), m_speed(2.0)
{
    setPixmap(QPixmap(":/images/enemy.png"));
    setPos(0, 0); // Start from top left corner

    m_movementTimer = new QTimer(this);
    connect(m_movementTimer, &QTimer::timeout, this, &Enemy::move);
    m_movementTimer->start(50); // Movement update every 50 milliseconds
}

QPoint Enemy::getDestination()
{
    // Return the destination point
    return m_destination;
}

void Enemy::move()
{
    // Calculate distance to destination
    QLineF lineToDestination(pos(), m_destination);
    qreal distanceToDestination = lineToDestination.length();

    if (distanceToDestination > 1)
    {
        // Calculate the vector towards the destination
        QPointF direction = lineToDestination.unitVector().p2();

        // Calculate the new position based on speed
        qreal dx = direction.x() * m_speed;
        qreal dy = direction.y() * m_speed;

        // Check if the new position exceeds the destination
        if (distanceToDestination > m_speed)
        {
            setPos(pos() + QPointF(dx, dy));
        }
        else
        {
            setPos(m_destination);
        }
    }
    else
    {
        // Enemy reached the destination (optional: emit signal or perform some action)
    }
}
