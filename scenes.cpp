#include "scenes.h"
#include "builder_hut.h"
#include "countdown.h"
#include "damageboosters.h"
#include "bullet.h"
#include "healthBar.h"
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>




Scenes::Scenes(QString designFilePath, QString castlePath, int castleHealth,
               QString defenseTowerPath, QString bulletPath, int bulletDamage,
               QString enemyPath, int enemyHealth, int enemyDamage, QString bgPath
               , QString fencePath, int fenceHealth, QString builderHutPath,
               QString builderPath, int builderHeal, QTime initialTime, QString enemyAttack,
               QString enemyStill, QString soundPath, float speed) {
    view = new QGraphicsView();
    scene = new myscene();
    view->setScene(scene);
    this->speed = speed;
    view->setWindowTitle("Protect the Castle!");
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setMouseTracking(true);
    this->castlePath = castlePath;
    this->castleHealth = castleHealth;
    this->defenseTowerPath = defenseTowerPath;
    this->bulletPath = bulletPath;
    this->bulletDamage = bulletDamage;
    this->enemyPath = enemyPath;
    this->enemyAttack = enemyAttack;
    this->enemyStill = enemyStill;
    this->enemyHealth = enemyHealth;
    this->enemyDamage = enemyDamage;
    this->bgPath = bgPath;
    this->fencePath = fencePath;
    this->fenceHealth = fenceHealth;
    this->builderHutPath = builderHutPath;
    this->builderPath = builderPath;
    this->builderHeal = builderHeal;
    this->initialTime = initialTime;
    this->soundPath = soundPath;

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
        QVector <QChar> rowData;
        QVector <int> rowGraph;
        int count = 0;
        for (int i = 0; i < line.size(); ++i) {
            QChar chartemp = line.at(i);
            if (chartemp == '0' || chartemp == '1' || chartemp == '2' || chartemp == '3'|| chartemp =='4' || chartemp =='5') {
                //int intValue = chartemp.digitValue();
                rowData.push_back(chartemp);
                rowGraph.push_back(count);
                count++;
            }
        }
        Boarddata.push_back(rowData);

        graph.push_back(rowGraph);

    }

    file.close();
    Enemy::Map.resize(Boarddata.size());
    for (int i = 0; i<Boarddata.size(); i++){
        Enemy::Map[i].resize(Boarddata[i].size());
    }
    Builder::Map = Enemy::Map;
}

void Scenes::changeScore(){
    QGraphicsTextItem *incScore = new QGraphicsTextItem("+1");
    incScore->setFont(QFont("times", 16));
    incScore->setDefaultTextColor(Qt::blue);
    incScore->setPos(-10, 0);
    scene->addItem(incScore);

}

QGraphicsView* Scenes::renderScene() {
    scene->setSceneRect(0, 0, Boarddata[0].size() * 50, Boarddata.size() * 50);
    QPixmap bgimage(bgPath);
    bgimage = bgimage.scaled(50, 50);

    ScoreWidget *scoreWidget = new ScoreWidget();
    QGraphicsProxyWidget *proxy2 = new QGraphicsProxyWidget();
    proxy2->setWidget(scoreWidget);
    scene->addItem(proxy2);
    proxy2->setPos(1200, scene->height() + 10);

    HealthBar *healthBar = new HealthBar();
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget();
    proxy->setWidget(healthBar);
    scene->addItem(proxy);
    proxy->setPos(0, scene->height() + 20);

    // Instantiate the ScoreWidget and add it to your main layout


    // Update the score whenever needed


    for (int i = 0; i < Boarddata.size(); i++) {
        for (int j = 0; j < Boarddata[i].size(); j++) {
            QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(bgimage);
            scene->addItem(backgroundItem);
            backgroundItem->setPos(50 * j, 50 * i);
            Enemy::Map[i][j] = 1;
            Builder::Map[i][j] = 1;

            if (Boarddata[i][j] == '1') {
                castle = new Castle(castlePath, castleHealth);
                castle->setPos(backgroundItem->x() , backgroundItem->y());
                Castle::connect(this->castle, &Castle::castleHit, healthBar, &HealthBar::setValue);
                this->castlePosition = QPointF(backgroundItem->x(), backgroundItem->y());
                Enemy::targetPoint = QPoint(backgroundItem->x()/50, backgroundItem->y()/50);
                Enemy::targetPoint1 = QPoint(backgroundItem->x(), backgroundItem->y());
                Enemy::Map[i][j] = 2;

                scene->addItem(castle);

            } else if (Boarddata[i][j] == '2') {
                defense_unit = new Defence_unit(scene, defenseTowerPath, bulletPath, bulletDamage, soundPath, speed);
                defense_unit->setPos(backgroundItem->x() - 75, backgroundItem->y() -75);
                defense_unit->position = QPointF(backgroundItem->x(), backgroundItem->y());
                Enemy::Map[i][j] = 20;

                scene->addItem(defense_unit);
                QObject::connect(scene, &myscene::mousePresseddd, defense_unit, &Defence_unit::spawnBullet);
                enemySpawner = new EnemySpawner(scene, Boarddata, enemyPath, enemyHealth, enemyDamage, enemyAttack, enemyStill);
                QTimer::singleShot(1000, enemySpawner, &EnemySpawner::spawnEnemy);



            } else if (Boarddata[i][j] == '3') {
                fence = new Fence(nullptr, fencePath, fenceHealth);
                fence->setPos(backgroundItem->x(), backgroundItem->y());
                fence->x = i;
                fence->y = j;
                Enemy::Map[i][j] = 8;

                scene->addItem(fence);
                this->fences.push_back(fence);
            }

            else if (Boarddata[i][j] == '4'){
                //create a builder hut
                builder_hut *builderHut = new builder_hut(scene, fences, builderHutPath, builderPath, builderHeal);
                builderHut->setPos(backgroundItem->x(), backgroundItem->y());
                builderHut->origin = QPointF(backgroundItem->x(), backgroundItem->y());
                //Enemy::Map[i][j] = 15;

                scene->addItem(builderHut);
                QTimer::singleShot(1000, builderHut, &builder_hut::spawnBuilder);
            }
        }
    }
    Builder::fences = this->fences;
    Enemy::fences = this->fences;
    Enemy::graph = this->graph;
    QObject::connect(defense_unit, &Defence_unit::incCastleHealth, this->castle, &Castle::fillHealth);

    CountdownTimer *timer = new CountdownTimer(nullptr, initialTime);
    QObject::connect(timer, &CountdownTimer::displayLVL2, scene, &myscene::DisplayLVL2);
    QObject::connect(timer, &CountdownTimer::displayLVL3, scene, &myscene::DisplayLVL3);
    QObject::connect(timer, &CountdownTimer::displayLVL4, scene, &myscene::DisplayLVL4);
    QObject::connect(timer, &CountdownTimer::displayLVL5, scene, &myscene::DisplayLVL5);
    QObject::connect(timer, &CountdownTimer::displayFinal, scene, &myscene::DisplayFinal);
    QObject::connect(timer, &CountdownTimer::Won, castle, &Castle::onWon);

    QObject::connect(this->defense_unit, &Defence_unit::incKillCount, scoreWidget, &ScoreWidget::updateScore);
    //QObject::connect(scoreWidget, &ScoreWidget::scoreUpdated, this, &Scenes::changeScore);

    damageBoosters *damageBooster = new damageBoosters(nullptr, ":/imgs/damageBooster.png");
    damageBoosters *healthBooster = new damageBoosters(nullptr, ":/imgs/healthBooster.png");
    damageBoosters * multiShot = new damageBoosters(nullptr, ":/imgs/multiShot.png");
    int row, col;
    QRectF sceneRect = scene->sceneRect();
    qreal sceneWidth = sceneRect.width();
    qreal sceneHeight = sceneRect.height();
    srand(time(0));
    // Calculate random positions within the permissible area of the scene
    do {
        row = rand() % static_cast<int>(sceneWidth - 50);  // Subtract 50 to ensure the enemy's pixmap is fully visible
        col = rand() % static_cast<int>(sceneHeight - 50);
    } while (Boarddata[col / 50][row / 50] != '0');
    damageBooster->setPos(row, col);
    do {
        row = rand() % static_cast<int>(sceneWidth - 50);  // Subtract 50 to ensure the enemy's pixmap is fully visible
        col = rand() % static_cast<int>(sceneHeight - 50);
    } while (Boarddata[col / 50][row / 50] != '0');
    healthBooster->setPos(row, col);
    do {
        row = rand() % static_cast<int>(sceneWidth - 50);  // Subtract 50 to ensure the enemy's pixmap is fully visible
        col = rand() % static_cast<int>(sceneHeight - 50);
    } while (Boarddata[col / 50][row / 50] != '0');
    multiShot->setPos(row, col);

    QTimer::singleShot(3000, [=]() {
        scene->addItem(damageBooster);
    });
    QTimer::singleShot(4000, [=]() {
        scene->addItem(multiShot);
    });
    QTimer::singleShot(4000, [=]() {
        scene->addItem(healthBooster);
    });


    scene->addItem(timer);
    return view;
}


void Scenes::deleteAllObjects() {
    QList<QGraphicsItem*> items = scene->items();
    for (QGraphicsItem* item : items) {
        if(item){
            scene->removeItem(item);
            delete item;
        }
    }
}

void Scenes::gameOver()
{
    this->view->close();
}







