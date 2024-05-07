#include "scenes.h"
#include "builder_hut.h"
#include "countdown.h"
#include "damageboosters.h"

Scenes::Scenes(QString designFilePath, QString castlePath, int castleHealth,
               QString defenseTowerPath, QString bulletPath, int bulletDamage,
               QString enemyPath, int enemyHealth, int enemyDamage, QString bgPath
               , QString fencePath, int fenceHealth, QString builderHutPath,
               QString builderPath, int builderHeal, QTime initialTime) {
    view = new QGraphicsView();
    scene = new myscene();
    view->setScene(scene);
    view->setWindowTitle("Protect your Queen");
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setMouseTracking(true);
    this->castlePath = castlePath;
    this->castleHealth = castleHealth;
    this->defenseTowerPath = defenseTowerPath;
    this->bulletPath = bulletPath;
    this->bulletDamage = bulletDamage;
    this->enemyPath = enemyPath;
    this->enemyHealth = enemyHealth;
    this->enemyDamage = enemyDamage;
    this->bgPath = bgPath;
    this->fencePath = fencePath;
    this->fenceHealth = fenceHealth;
    this->builderHutPath = builderHutPath;
    this->builderPath = builderPath;
    this->builderHeal = builderHeal;
    this->initialTime = initialTime;

    QString textFilePath = designFilePath;
    readDesignFromFile(textFilePath);


}

QGraphicsView* Scenes::getView() {
    return view;
}

void Scenes::readDesignFromFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << file.errorString();
        return;
    }
    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QVector<QChar> rowData;
        for (int i = 0; i < line.size(); ++i) {
            QChar chartemp = line.at(i);
            if (chartemp == '0' || chartemp == '1' || chartemp == '2' || chartemp == '3'|| chartemp =='4' || chartemp =='5') {
                rowData.push_back(chartemp);
            }
        }
        Boarddata.push_back(rowData);
    }
    file.close();
}

QGraphicsView* Scenes::renderScene() {
    scene->setSceneRect(0, 0, Boarddata[0].size() * 50, Boarddata.size() * 50);
    QPixmap bgimage(bgPath);
    bgimage = bgimage.scaled(50, 50);

    for (int i = 0; i < Boarddata.size(); i++) {
        for (int j = 0; j < Boarddata[i].size(); j++) {
            QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(bgimage);
            scene->addItem(backgroundItem);
            backgroundItem->setPos(50 * j, 50 * i);

            if (Boarddata[i][j] == '1') {
                castle = new Castle(castlePath, castleHealth);
                castle->setPos(backgroundItem->x(), backgroundItem->y());
                this->castlePosition = QPointF(backgroundItem->x(), backgroundItem->y());
                Enemy::targetPoint = QPoint(backgroundItem->x(), backgroundItem->y());
                scene->addItem(castle);

            } else if (Boarddata[i][j] == '2') {
                defense_unit = new Defence_unit(scene, defenseTowerPath, bulletPath, bulletDamage);
                defense_unit->setPos(backgroundItem->x(), backgroundItem->y());
                defense_unit->position = QPointF(backgroundItem->x(), backgroundItem->y());
                defense_unit->setScale(1.5);
                scene->addItem(defense_unit);
                QObject::connect(scene, &myscene::mousePresseddd, defense_unit, &Defence_unit::spawnBullet);
                enemySpawner = new EnemySpawner(scene, Boarddata, enemyPath, enemyHealth, enemyDamage);
                QTimer::singleShot(3000, enemySpawner, &EnemySpawner::spawnEnemy);

            } else if (Boarddata[i][j] == '3') {
                fence = new Fence(nullptr, fencePath, fenceHealth);
                fence->setPos(backgroundItem->x(), backgroundItem->y());
                scene->addItem(fence);
                this->fences.push_back(fence);
            }

            else if (Boarddata[i][j] == '4'){
                //create a builder hut
                builder_hut *builderHut = new builder_hut(scene, fences, builderHutPath, builderPath, builderHeal);
                builderHut->setPos(backgroundItem->x(), backgroundItem->y());
                builderHut->origin = QPointF(backgroundItem->x(), backgroundItem->y());
                scene->addItem(builderHut);
                QTimer::singleShot(1000, builderHut, &builder_hut::spawnBuilder);
            }
        }
    }
    Builder::fences = this->fences;

    CountdownTimer *timer = new CountdownTimer(nullptr, initialTime);
    QObject::connect(timer, &CountdownTimer::displayLVL2, scene, &myscene::DisplayLVL2);
    QObject::connect(timer, &CountdownTimer::displayLVL3, scene, &myscene::DisplayLVL3);
    QObject::connect(timer, &CountdownTimer::displayLVL4, scene, &myscene::DisplayLVL4);
    QObject::connect(timer, &CountdownTimer::displayLVL5, scene, &myscene::DisplayLVL5);
    QObject::connect(timer, &CountdownTimer::displayFinal, scene, &myscene::DisplayFinal);

    damageBoosters *damageBooster = new damageBoosters(nullptr);
    int row, col;
    QRectF sceneRect = scene->sceneRect();
    qreal sceneWidth = sceneRect.width();
    qreal sceneHeight = sceneRect.height();

    // Calculate random positions within the permissible area of the scene
    do {
        row = rand() % static_cast<int>(sceneWidth - 50);  // Subtract 50 to ensure the enemy's pixmap is fully visible
        col = rand() % static_cast<int>(sceneHeight - 50);
    } while (Boarddata[col / 50][row / 50] != '0');
    damageBooster->setPos(row, col);

    QTimer::singleShot(5000, [=]() {
        scene->addItem(damageBooster);
    });



    scene->addItem(timer);
    return view;
}

// void Scenes::deleteViewAndScene() {
//     if (view) {
//         delete view;
//         view = nullptr;
//     }
//     if (scene) {
//         delete scene;
//         scene = nullptr;
//     }
// }
// void Scenes::disconnectTimerSignals() {
//     // Disconnect signals from the timer
//     disconnect(timer, &CountdownTimer::displayLVL2, scene, &myscene::DisplayLVL2);
//     disconnect(timer, &CountdownTimer::displayLVL3, scene, &myscene::DisplayLVL3);
//     disconnect(timer, &CountdownTimer::displayLVL4, scene, &myscene::DisplayLVL4);
//     disconnect(timer, &CountdownTimer::displayLVL5, scene, &myscene::DisplayLVL5);
//     disconnect(timer, &CountdownTimer::displayFinal, scene, &myscene::DisplayFinal);
// }
//make a function that deletes all objects in the scene
void Scenes::deleteAllObjects() {
    QList<QGraphicsItem*> items = scene->items();
    for (QGraphicsItem* item : items) {
        if(item){
        scene->removeItem(item);
            delete item;
        }
    }
}







