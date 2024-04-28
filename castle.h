#ifndef CASTLE_H
#define CASTLE_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Castle: public QObject, public QGraphicsPixmapItem
{
public:
    Castle(){
        QPixmap img = QPixmap(":/imgs/castle.png");
        setPixmap(img.scaled(50, 50));
        setPos(500, 400);

    }

    int health = 100;
    int maxhealth = health;
    int getHealth() const {
        return health;
    }
    void setHealth(int health) {
        this->health = health;
    }
    bool isDestroyed() {
        if (this->health <= 0){
            this->hide();
            return true;
        }
        return false;
    }
    bool decHealth(int health) {
        this->health -= health;
        if (this->health <= 0) {
            this->hide();
            isDestroyed();
        }
        return false;
        isDestroyed();
    }
    bool incHealth(int health) {
        this->health += health;
        if (this->health >= 100) {
            this->health = 100;
        }
        return false;
    }
};

#endif // CASTLE_H
