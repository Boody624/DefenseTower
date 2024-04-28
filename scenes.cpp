#include "scenes.h"
#include "builder_hut.h"
Scenes::Scenes() {
    view = new QGraphicsView();
    scene = new myscene();
    view->setScene(scene);
    view->setWindowTitle("Protect your Queen");
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setMouseTracking(true);

    QString textFilePath = ":/design/Design.txt";
    readDesignFromFile(textFilePath);
    view = renderScene();

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
    QString bgpath = ":/imgs/mtland.png";
    QPixmap bgimage(bgpath);
    bgimage = bgimage.scaled(50, 50);

    for (int i = 0; i < Boarddata.size(); i++) {
        for (int j = 0; j < Boarddata[i].size(); j++) {
            QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(bgimage);
            scene->addItem(backgroundItem);
            backgroundItem->setPos(50 * j, 50 * i);

            if (Boarddata[i][j] == '1') {
                castle = new Castle();
                castle->setPos(backgroundItem->x(), backgroundItem->y());
                Enemy::targetPoint = QPoint(backgroundItem->x(), backgroundItem->y());
                scene->addItem(castle);

            } else if (Boarddata[i][j] == '2') {
                defense_unit = new Defence_unit(scene);
                defense_unit->setPos(backgroundItem->x(), backgroundItem->y());
                scene->addItem(defense_unit);
                QObject::connect(scene, &myscene::mousePresseddd, defense_unit, &Defence_unit::spawnBullet);
                enemySpawner = new EnemySpawner(scene, Boarddata);
                QTimer::singleShot(3000, enemySpawner, &EnemySpawner::spawnEnemy);

            } else if (Boarddata[i][j] == '3') {
                fence = new Fence();
                fence->setPos(backgroundItem->x(), backgroundItem->y());
                scene->addItem(fence);
            }

            else if (Boarddata[i][j] == '4'){
                //create a builder hut
                builder_hut *builderHut = new builder_hut(scene);
                builderHut->setPos(backgroundItem->x(), backgroundItem->y());
                scene->addItem(builderHut);
            }
        }
    }


    return view;
}




