#ifndef CASTLE_H
#define CASTLE_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Castle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Castle(QString castlePath, int castleHealth);

    int getHealth() const;
    void setHealth(int health);
    bool isDestroyed();
    bool decHealth(int damage);
    bool incHealth(int health);
    bool played = false;
    QString castlePath;
    void onWon();
    void fillHealth();

signals:
    void gameOver();
    void castleHit(int health);
    void gameWon();
private:
    int health;
    int maxHealth;
};

#endif // CASTLE_H
