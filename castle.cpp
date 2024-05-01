#include "castle.h"
#include <QPixmap>

Castle::Castle() : health(100), maxHealth(100)
{
    QPixmap img(":/imgs/castle.png");
    setPixmap(img.scaled(50, 50));
}

int Castle::getHealth() const
{
    return health;
}

void Castle::setHealth(int health)
{
    this->health = health;
}

bool Castle::isDestroyed()
{
    if (health <= 0)
    {
        hide();
        return true;
    }
    return false;
}

bool Castle::decHealth(int damage)
{
    health -= damage;
    if (health <= 0)
    {
        hide();
        return true;
    }
    return false;
}

bool Castle::incHealth(int health)
{
    this->health += health;
    if (this->health >= maxHealth)
    {
        this->health = maxHealth;
    }
    return false;
}
