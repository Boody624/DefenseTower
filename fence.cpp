#include "fence.h"

Fence::Fence(QGraphicsItem* parent, int health) : QObject(), QGraphicsPixmapItem(parent), health(health), maxhealth(health) {
    QString path = ":/imgs/fence.png";
    QPixmap img3(path);
    setPixmap(img3.scaled(50, 50));

}

int Fence::getHealth() const {
    return health;
}

QPoint Fence::getLocation() const {
    return location;
}

bool Fence::isDamaged() {
    return (health < maxhealth);
}

bool Fence::atFullHealth() {
    return (health == maxhealth);
}

void Fence::setHealth(int health) {
    this->health = health;
}
void Fence::checkIfDestroyed() {
    if (health <= 0) {
        hide();
        delete this;
    }
}
bool Fence::isDestroyed() {
    if (this->health <= 0) {
        this->hide();
        emit gotDestroyed();
        return true;
    }
    else {
        return false;
    }
}

bool Fence::decHealth(int health) {
    this->health -= health;
    return isDestroyed();
}

void Fence::incHealth(int health) {
    this->health += health;
    if (this->health >= maxhealth) {
        this->health = maxhealth;
    }
}

void Fence::setLocation(const QPoint& location) {
    this->location = location;
}

void Fence::damage(int amount) {
    health -= amount;
}

void Fence::displayHealthBar() {
    // Implement health bar display logic here
}

void Fence::takeDmg(int damage) {
    health -= damage;
}
