#include "castle.h"
#include <QPixmap>
#include <QAudioOutput>
#include <QMediaPlayer>
Castle::Castle(QString castlePath, int castleHealth) : health(castleHealth), maxHealth(castleHealth)
{
    this->castlePath = castlePath;
    QPixmap img(castlePath);
    setPixmap(img.scaled(50, 50));
    setScale(1.5);
    setZValue(2);

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
    emit castleHit(health);
    if(health <= maxHealth/3){
        if(!played)
        {
        QAudioOutput * bgoutput = new QAudioOutput();
        bgoutput->setVolume(1);
        QMediaPlayer * bgsound = new QMediaPlayer();
        bgsound->setAudioOutput(bgoutput);
        bgsound->setSource(QUrl("qrc:/sounds/We-Must-Keep-Going.wav"));
        bgsound->setPlaybackRate(1);

        bgsound->play();
        played = true;
        }
    }
    if (health <= 0)
    {
        emit gameOver();
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

void Castle::onWon()
{
    emit gameWon();
    //hide();
}

void Castle::fillHealth()
{
    health = maxHealth;

}
