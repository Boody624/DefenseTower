#ifndef FENCE_H
#define FENCE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include "healthBar.h"

class Fence : public QObject, public QGraphicsPixmapItem {    
    Q_OBJECT
private:
    int health;
    QPoint location;
    //HealthBar healthBar; // Add a health bar instance

public:
    // Constructor
    Fence(int initialHealth, const QPoint& location, const QString& imagePath, QGraphicsItem* parent = nullptr)
        : QGraphicsPixmapItem(QPixmap(imagePath), parent), health(initialHealth), location(location) {
        // Initialize the health bar
        //healthBar.setGeometry(location.x(), location.y() + 100, 100, 10);
        //healthBar.setHealth(initialHealth);
    }


    // Getter methods
    int getHealth() const {
        return health;
    }

    QPoint getLocation() const {
        return location;
    }

    // Setter methods
    void setHealth(int health) {
        this->health = health;
        // Update the health bar
        //healthBar.setHealth(health);
    }

    void setLocation(const QPoint& location) {
        this->location = location;
    }

    // Other methods
    void damage(int amount);
    void displayHealthBar();

    // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override {
    //     // Draw the pixmap
    //     QGraphicsPixmapItem::paint(painter, option, widget);

    //     // Draw the health bar
    //     QRect healthBarRect(location.x(), location.y() + 100, 100 * health / 100, 10);
    //     painter->fillRect(healthBarRect, Qt::green);
    // }
signals:
    // Signal emitted when the health changes
    void healthChanged(int newHealth);
};

#endif // FENCE_H
