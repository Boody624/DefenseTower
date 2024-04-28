#include "enemySpawner.h"

EnemySpawner::EnemySpawner(QGraphicsScene* thescene, QVector<QVector<QChar>> Boarddata) : QObject(), QGraphicsPixmapItem(), thescene(thescene) {
    thescene->addItem(this);

    // setting the image
    QString path = ":/imgs/mtland.png";
    QPixmap img3 = (path);
    setPixmap(img3.scaled(50, 50));
    setPos(200, 300);
    Boarddata2 = Boarddata;
    QObject::connect(&timer, &QTimer::timeout, this, &EnemySpawner::spawnEnemy);
    timer.start(2000); // Adjust the interval as needed for enemy spawn rate
}

EnemySpawner::~EnemySpawner() {
    // Disconnect timer when object is destroyed
    QObject::disconnect(&timer, &QTimer::timeout, this, &EnemySpawner::spawnEnemy);
}

void EnemySpawner::spawnEnemy() {
    // Create an Enemy object
    Enemy *enemy = new Enemy();
    //seed the rand with time
    srand(time(0));
    // Set a randomized position for the enemy
    // Assuming thescene is a QGraphicsScene pointer

    QRectF sceneRect = thescene->sceneRect();
    qreal sceneWidth = sceneRect.width();
    qreal sceneHeight = sceneRect.height();

    // Calculate random positions within the permissible area of the scene
    do {
        row = rand() % static_cast<int>(sceneWidth - 50);  // Subtract 50 to ensure the enemy's pixmap is fully visible
        col = rand() % static_cast<int>(sceneHeight - 50);
    } while (Boarddata2[col / 50][row / 50] != '0');
    enemy->setPos(row, col);

    // Add enemy to the scene
    thescene->addItem(enemy);
}
