#include "finalboss.h"
#include "bossmagic.h"

FinalBoss::FinalBoss(QGraphicsItem *parent, myscene * scene) : QObject(), QGraphicsPixmapItem(parent), health(100)
{
    // Set the image of the final boss
    QPixmap img(":/imgs/final_boss.png");
    setPixmap(img.scaled(50, 50));
    setScale(2);
    setPos(10, 10);
    this->scene = scene;
    setZValue(2);

    // Initialize the movement timer for periodic movement updates
    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &FinalBoss::move);
    moveTimer->start(50); // Adjust the movement interval as needed
    QTimer *fireTimer = new QTimer(this);
    connect(fireTimer, &QTimer::timeout, this, &FinalBoss::fire);
    fireTimer->start(2000);
}

void FinalBoss::move()
{
    // Define movement speed and distance to move down
     // Adjust the horizontal movement speed as needed
    qreal verticalSpeed = 20;  // Adjust the vertical movement speed as needed
    qreal moveDownDistance = 5; // Adjust the distance to move down as needed

    // Get the scene's bounding rectangle
    QRectF sceneRect = scene->sceneRect();

    // Move horizontally
    qreal nextX = x() + horizontalSpeed;
    qreal nextY = y();

    // If the boss reaches the right edge of the screen and hasn't moved down yet
    if (nextX >= sceneRect.right() - 100)
    {
        qDebug() << "Going left";
        // Move down and continue moving left
        horizontalSpeed *= -1; // Change horizontal direction to move left

    }
    if (nextX <= sceneRect.left())
    {
        qDebug() << "Going right";
        // Move down and continue moving left
        horizontalSpeed *= -1; // Change horizontal direction to move left
    }

    // Set the new position
    setPos(nextX, nextY);
}

void FinalBoss::fire()
{
    qDebug() << "Firing magic";
    bossMagic *magic = new bossMagic(this->pos());
    scene->addItem(magic);
    emit magic->fired();

}
