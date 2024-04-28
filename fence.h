#ifndef FENCE_H
#define FENCE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include <QTimer>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsScene>
#include <QWidget>
#include "healthBar.h"
#include "enemy.h"

class Fence : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:


public:
    // Constructor
    Fence(QGraphicsItem* parent = nullptr, int health = 100);

    int getHealth() const;
    QPoint getLocation() const;
    bool isDamaged();
    bool atFullHealth();
    int health;
    int maxhealth;
    QPoint location;
    void setHealth(int health);
    bool isDestroyed();
    bool decHealth(int health);
    void incHealth(int health);
    void setLocation(const QPoint& location);

    // Other methods
    void damage(int amount);
    void displayHealthBar();

public slots:
    void takeDmg(int damage);

signals:
    // Signal emitted when the health changes
    void healthChanged(int newHealth);
};

#endif // FENCE_H
