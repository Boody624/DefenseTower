#ifndef SCENES_H
#define SCENES_H
#include <QMessageBox>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QScreen>
#include "fence.h"
#include "healthbar.h"
#include "defence_unit.h"

QVector<QVector<int>> readClanDesignFromFile(const QString& filePath) {
    QVector<QVector<int>> clanDesign;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file:" << file.errorString();
        return clanDesign;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList tokens = line.split(",", Qt::SkipEmptyParts);
        QVector<int> row;

        for (const QString& token : tokens) {
            int value = token.toInt();
            row.append(value);
        }

        clanDesign.append(row);
    }

    file.close();
    return clanDesign;
}
//Assign the path of the design file to the function that reads it
QString filePath = "C:/AUC/Spring24/CS II/DefenseTower-main/Design.txt";
QVector<QVector<int>> clanDesign = readClanDesignFromFile(filePath);


QGraphicsView* createSceneView(const QVector<QVector<int>>& clanDesign) {
    // Create a new QGraphicsScene
    QGraphicsScene *scene = new QGraphicsScene;
    Defence_unit* defense_unit = new Defence_unit(scene);
    scene->setSceneRect(0, 0, 1200, 1000);
    // Populate the scene with the clan design
    for (int i = 0; i < clanDesign.size(); ++i) {
        for (int j = 0; j < clanDesign[i].size(); ++j) {
            int value = clanDesign[i][j];
            QGraphicsPixmapItem *pixmapItem = nullptr;

            switch (value) {
            case 0: // Empty land
                pixmapItem = new QGraphicsPixmapItem(QPixmap(":/imgs/mtland.png"));
                break;
            case 1: // Clan castle
                pixmapItem = new QGraphicsPixmapItem(QPixmap(":/imgs/castle.png"));
                break;
            case 2: // Defense unit
                // pixmapItem = new QGraphicsPixmapItem(QPixmap(":/imgs/wizardTower.png"));
                pixmapItem = new QGraphicsPixmapItem (defense_unit->pixmap());
                defense_unit->spawnBullet();
                break;
            case 3: // Fence
                pixmapItem = new QGraphicsPixmapItem(QPixmap(":/imgs/fence.png"));
                // Create Fence object
                //Fence *fence = new Fence(100, QPoint(j * 100, i * 100), "D:/AUC/Spring 2024/CS 2/Project/Defense/fence.png");

                //const QString fenceImagePath = "D:/AUC/Spring 2024/CS 2/Project/Defense/fence.png";
                //QPoint point(j*100, i*100);
                //Fence *fence = new Fence(100, point, fenceImagePath);
                //scene->addItem(fence);
                // Create HealthBar object and position it at the bottom of the fence image
                //HealthBar *healthBar = new HealthBar();
                //healthBar->setGeometry(fence->getLocation().x(), fence->getLocation().y() + 100, 100, 10);

                // Connect fence health change signal to health bar update slot
                //QObject::connect(fence, &Fence::setHealth, healthBar, &HealthBar::setHealth);

                break;
            }

            if (pixmapItem) {
                pixmapItem->setPos(j * 100, i * 100);
                scene->addItem(pixmapItem);
            }
        }
    }

    // Create a new QGraphicsView and set the scene
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    return view;
}
#endif // SCENES_H
