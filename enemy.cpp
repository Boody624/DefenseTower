#include "enemy.h"
#include "fence.h"
#include "castle.h"
#include <QMessageBox>
#include <QMovie>
#include "str.h"

// Make target point static
QPoint Enemy::targetPoint;
QPoint Enemy::targetPoint1;
QVector<Fence*> Enemy::fences;
QVector<QPointF> Enemy::obstacles (5, QPointF(0,0));
QVector<QVector<int>> Enemy::graph;
QVector<QVector<int>> Enemy::Map;

Enemy::Enemy(QString enemyPath, int health, int damage,
             QString enemyAttack, QString enemyStill, QGraphicsScene* theScene) : QObject(), QGraphicsPixmapItem() {
    // Setting the image of the enemy
    this->fences = fences;
    this->theScene = theScene;
    QString path = enemyPath;
    QPixmap img = QPixmap(path);
    setPixmap(img.scaled(48, 48));
    setScale(1.7);
    setZValue(2);
    //setPos(0, 0); // Initial position at the top left corner
    this->damage = damage; // Set the damage value
    this->health = health;
    // Creating the movement timer
    moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(1000); // Adjust the interval as needed
    castleCollisionTimer = new QTimer(this);
    connect(castleCollisionTimer, SIGNAL(timeout()), this, SLOT(checkCastleCollision()));

    fenceCollisionTimer = new QTimer(this);
    connect(fenceCollisionTimer, SIGNAL(timeout()), this, SLOT(checkCollision()));

    moveAlongTimer = new QTimer(this);
    connect(moveAlongTimer, SIGNAL(timeout()), this, SLOT(moveAlongPath()));
    // pathUpdateTimer = new QTimer(this);
    // connect(pathUpdateTimer, SIGNAL(timeout()), this, SLOT(updatePath));
    // pathUpdateTimer->start(1000);


    // Load the GIF animations and connect them
    moveAnimation = new QMovie(enemyPath);
    connect(moveAnimation, SIGNAL(frameChanged(int)), this, SLOT(updatePixmap()));


    attackAnimation = new QMovie(enemyAttack);
    connect(attackAnimation, SIGNAL(frameChanged(int)), this, SLOT(updateAttack()));

    stillAnimation = new QMovie(enemyStill);
    connect(stillAnimation, SIGNAL(frameChanged(int)), this, SLOT(updateStill()));

    //Signals to start and stop the animations
    connect(this, &Enemy::moving, moveAnimation, &QMovie::start);
    connect(this, &Enemy::moving, stillAnimation, &QMovie::stop);
    connect(this, &Enemy::moving, attackAnimation, &QMovie::stop);
    connect(this, &Enemy::still, moveAnimation, &QMovie::stop);
    connect(this, &Enemy::still, stillAnimation, &QMovie::start);
    connect(this, &Enemy::attacking, attackAnimation, &QMovie::start);
    //rotateTowardsCastle();


}
void Enemy::updatePath()
{
    s = new str(initial, Enemy::targetPoint, Enemy::obstacles);

    if (!currentPath.isEmpty()) {
        // Clear the current path before recalculating
        currentPath.clear();
    }
    // Recalculate the path
    currentPath = s->findPath(Map);
}

void Enemy::move() {
    moveTimer->stop();
    //checkCollision();
    //Calculate the direction towards the target point


    s = new str(initial, Enemy::targetPoint, Enemy::obstacles);
    // Calculate path if not already calculated or if the current path is empty
    if (currentPath.isEmpty()) {
        currentPath = s->findPath(Map);

    }
    // If path is not empty, move to the next position
    if (!currentPath.isEmpty()) {
        // Take the next node from the path if it's not empty

        QPoint nextNode = currentPath.takeFirst(); // Take the next node from the path
        QPoint nextPosition(nextNode.x() * 50 - 20, nextNode.y() * 50 - 30);

        // Check if the next position is the castle or a fence
        if (Map[nextNode.y()][nextNode.x()] == 2 ) {

            currentPath.clear();
        }
        else if (Map[nextNode.y()][nextNode.x()] == 8) {

        }
        if(count == 0){
            theScene->addItem(this);
            setPos(nextPosition);
            count++;
        }
        currentNextPosition = nextPosition;
        // Update enemy's position5
        moveAlongTimer->start(50);
        initial = nextPosition;
        emit moving();
    }
}


void Enemy::moveAlongPath()
{
    checkCastleCollision();
    checkCollision();

    // Get the current position of the enemy
    QPoint currentPosition = this->pos().toPoint();

    // Calculate the distance between the current position and the target position
    qreal distance = QLineF(currentPosition, currentNextPosition).length();

    // Define a maximum distance for approximation
    qreal maxDistance = 5.0; // Adjust as needed

    if (distance <= maxDistance) {
        // If the distance is within the maximum distance, stop moving along the path
        if(!hasCollided){
        moveAlongTimer->stop();
        // Start moving to the next position
        //updatePath();
        move();

        // Emit the moving signal
        emit moving();
        }
    }
    else {

        if(!hasCollided)
        {
        qreal dx = currentNextPosition.x() - x();
        qreal dy = currentNextPosition.y() - y();

        // Normalize the direction vector
        qreal length = qSqrt(dx * dx + dy * dy);
        dx /= length;
        dy /= length;

        // Move the enemy towards the target position
        setPos(x() + dx * 2, y() + dy * 2); // Adjust the speed as needed

        // Emit the moving signal
        emit moving();
        }
    }
}
void Enemy::checkCastleCollision() {
    QList<QGraphicsItem*> collidingItemsList = collidingItems();
    // Iterate through the list to find the castle
    for (QGraphicsItem* item : collidingItemsList) {
        Castle* castle = dynamic_cast<Castle*>(item);
        if (castle) {
            // Inflict damage to the castle
            if (!hasCollided) {
                emit still();
                hasCollided = true;
                QTimer::singleShot(2000, this, [=]() {
                    doDamageCastle(castle);
                    hasCollided = false; // Reset collision flag
                });
            }
            return; // Exit the loop after processing the castle collision
        }

    }
    if (!hasCollided && !moveAlongTimer->isActive())
    {
        moveAlongTimer->start(50);
    }
}

void Enemy::checkCollision() {
    QList<QGraphicsItem*> collidingItemsList = collidingItems();
    // Iterate through the list to find fences
    for (QGraphicsItem* item : collidingItemsList) {
        Fence* fence = dynamic_cast<Fence*>(item);
        if (fence) {
            // Inflict damage to the fence
            emit still();
            if (!hasCollided) {
                hasCollided = true;
                QTimer::singleShot(2000, this, [=]() {
                    doDamage(fence);
                    hasCollided = false; // Reset collision flag
                });
            }
            return; // Exit the loop after processing the fence collision
        }
    }
    // If no collision with a fence is detected, resume movement if it was stopped
    if (!hasCollided && !moveAlongTimer->isActive()) {
        moveAlongTimer->start(50);
    }
}
void Enemy::updatePixmap() {
    // Update the move animation pixmap
    updateAnimation(moveAnimation);
}

void Enemy::updateAttack() {
    // Update the attack animation pixmap
    updateAnimation(attackAnimation);
}

void Enemy::updateStill() {
    // Update the still animation pixmap
    updateAnimation(stillAnimation);
}

void Enemy::updateAnimation(QMovie* animation) {
    // Increment the frame counter
    frameMoveCounter++;

    // Check if it's time to update the pixmap
    if (frameMoveCounter >= 1) {
        // Reset the frame counter
        frameMoveCounter = 0;

        // Get the current pixmap from the animation
        framePixmap = animation->currentPixmap();

        // Scale the pixmap to 50x50 pixels
        framePixmap = framePixmap.scaled(48, 48);

        // Set the scaled pixmap as the pixmap for the QGraphicsPixmapItem
        framePixmap = rotateTowardsCastle(framePixmap);

        setPixmap(framePixmap);

        // Rotate towards the castle if necessary
    }
}


QPixmap Enemy::rotateTowardsCastle(QPixmap originalPixmap) {
    qreal dx = Enemy::targetPoint1.x() - x();
    //qreal dy = Enemy::targetPoint.y() - y();
    //qreal angle = qRadiansToDegrees(qAtan2(dy, dx));

    // Convert the original pixmap to QImage
    QImage originalImage = originalPixmap.toImage();

    // Create a mirrored version of the original image
    QImage mirroredImage = originalImage.mirrored(true, false);

    // Convert the mirrored image back to QPixmap
    QPixmap mirroredPixmap = QPixmap::fromImage(mirroredImage);

    // Check if the castle is to the left of the enemy
    if (dx <= 0) {
        return mirroredPixmap;
    } else {
        return originalPixmap;
    }


}


void Enemy::doDamageCastle(Castle *castle)
{
    castle->decHealth(this->damage);
    emit attacking();
}


void getFencesPosition(QVector<Fence*> fences){
    // for(Fence* fence : fences){
    //     Enemy::obstacles.push_back(fence->pos());
    // }
}



void Enemy::doDamage(Fence* fence)
{
    fence->decHealth(this->damage);
    emit attacking();
}

void Enemy::onFenceDestroyed()
{
    if(!moveAlongTimer->isActive()) {
        moveAlongTimer->start(50); // Resume movement
    }
}






