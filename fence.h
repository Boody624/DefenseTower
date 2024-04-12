#ifndef FENCE_H
#define FENCE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include <QString>

class Fence : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    // Constructor
    Fence(int initialHealth, const QPoint& location, const QString& imagePath, QGraphicsItem* parent = nullptr);

    // Getter methods
    int getHealth() const;
    QPoint getLocation() const;

    // Setter methods
    void setHealth(int health);
    void setLocation(const QPoint& location);

    // Other methods
    void damage(int amount);
signals:
    // Signal emitted when the health changes
    void healthChanged(int newHealth);
private:
    int health;
    QPoint location;
};

#endif // FENCE_H
