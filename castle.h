#ifndef CASTLE_H
#define CASTLE_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Castle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Castle();

    int getHealth() const;
    void setHealth(int health);
    bool isDestroyed();
    bool decHealth(int damage);
    bool incHealth(int health);

signals:
    void gotHit();

private:
    int health;
    int maxHealth;
};

#endif // CASTLE_H
