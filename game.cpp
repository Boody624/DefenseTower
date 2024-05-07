#include "game.h"
#include "scenes.h"
#include "customdialogue.h"
#include "finalboss.h"
#include "bossmagic.h"
game::game() {

}

void game::displayLVL1(){
    QString designFilePath = ":/design/LVL1.txt";
    QString castlePath = ":imgs/castle.png";
    int castleHealth = 100;
    QString defenseTowerPath = ":imgs/wizardTower.png";
    QString bulletPath = ":imgs/red_laser.png";
    int bulletDamage = 10;
    QString enemyPath = ":imgs/enemy.png";
    int enemyHealth = 50;
    int enemyDamage = 10;
    QString bgPath = ":imgs/mtland.png";
    QString fencePath = ":imgs/fence.png";
    int fenceHealth = 50;
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    int builderHeal = 10;
    QTime initialTime(0, 1, 15);

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                                bulletPath, bulletDamage, enemyPath,
                                enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                                builderHutPath, builderPath, builderHeal, initialTime);
    QObject::connect(scenes->scene, &myscene::displayLVL2, this, &game::onDisplayLVL2);

    this->view = scenes->renderScene();
    this->view->showFullScreen();
}

void game::displayLVL2(){

    qDebug() << "Displaying level 2 from the game right niowww";

    QString designFilePath = ":/design/LVL2.txt";
    QString castlePath = ":imgs/castle.png";
    int castleHealth = 100;
    QString defenseTowerPath = ":imgs/wizardTower.png";
    QString bulletPath = ":imgs/red_laser.png";
    int bulletDamage = 10;
    bullet::damage = bulletDamage;
    QString enemyPath = ":imgs/enemy.png";
    int enemyHealth = 50;
    int enemyDamage = 10;
    QString bgPath = ":imgs/mtland.png";
    QString fencePath = ":imgs/fence.png";
    int fenceHealth = 50;
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    int builderHeal = 10;
    QTime initialTime(0, 1, 0);

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                                bulletPath, bulletDamage, enemyPath,
                                enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                                builderHutPath, builderPath, builderHeal, initialTime);
    QObject::connect(scenes->scene, &myscene::displayLVL3, this, &game::onDisplayLVL3);
    this->view = scenes->renderScene();
    this->view->showFullScreen();

}

void game::displayLVL3(){
    qDebug() << "Displaying level 3 from the game right niowww";

    QString designFilePath = ":/design/LVL3.txt";
    QString castlePath = ":imgs/castle.png";
    int castleHealth = 100;
    QString defenseTowerPath = ":imgs/wizardTower.png";
    QString bulletPath = ":imgs/red_laser.png";
    int bulletDamage = 10;
    bullet::damage = bulletDamage;
    QString enemyPath = ":imgs/enemy.png";
    int enemyHealth = 50;
    int enemyDamage = 10;
    QString bgPath = ":imgs/mtland.png";
    QString fencePath = ":imgs/fence.png";
    int fenceHealth = 50;
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    int builderHeal = 10;
    QTime initialTime(0, 0, 45);

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                              bulletPath, bulletDamage, enemyPath,
                              enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                              builderHutPath, builderPath, builderHeal, initialTime);
    QObject::connect(scenes->scene, &myscene::displayLVL4, this, &game::onDisplayLVL4);
    this->view = scenes->renderScene();
    this->view->showFullScreen();
}

void game::displayLVL4(){
    qDebug() << "Displaying level 4 from the game right niowww";

    QString designFilePath = ":/design/LVL4.txt";
    QString castlePath = ":imgs/castle.png";
    int castleHealth = 100;
    QString defenseTowerPath = ":imgs/wizardTower.png";
    QString bulletPath = ":imgs/red_laser.png";
    int bulletDamage = 10;
    bullet::damage = bulletDamage;
    QString enemyPath = ":imgs/enemy.png";
    int enemyHealth = 50;
    int enemyDamage = 10;
    QString bgPath = ":imgs/mtland.png";
    QString fencePath = ":imgs/fence.png";
    int fenceHealth = 50;
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    int builderHeal = 10;
    QTime initialTime(0, 0, 30);

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                              bulletPath, bulletDamage, enemyPath,
                              enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                              builderHutPath, builderPath, builderHeal, initialTime);
    QObject::connect(scenes->scene, &myscene::displayLVL5, this, &game::onDisplayLVL5);
    this->view = scenes->renderScene();
    this->view->showFullScreen();
}

void game::displayLVL5(){
    qDebug() << "Displaying level 5 from the game right niowww";

    QString designFilePath = ":/design/LVL5.txt";
    QString castlePath = ":imgs/castle.png";
    int castleHealth = 100;
    QString defenseTowerPath = ":imgs/wizardTower.png";
    QString bulletPath = ":imgs/red_laser.png";
    int bulletDamage = 10;
    bullet::damage = bulletDamage;
    QString enemyPath = ":imgs/enemy.png";
    int enemyHealth = 50;
    int enemyDamage = 10;
    QString bgPath = ":imgs/mtland.png";
    QString fencePath = ":imgs/fence.png";
    int fenceHealth = 50;
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    int builderHeal = 10;
    QTime initialTime(0, 0, 15);

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                              bulletPath, bulletDamage, enemyPath,
                              enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                              builderHutPath, builderPath, builderHeal, initialTime);
    QObject::connect(scenes->scene, &myscene::displayFinal, this, &game::onDisplayFinal);
    this->view = scenes->renderScene();
    this->view->showFullScreen();
}

void game::displayFinal(){
    qDebug() << "Displaying level FINAL from the game right niowww";

    QString designFilePath = ":/design/LVLFinal.txt";
    QString castlePath = ":imgs/castle.png";
    int castleHealth = 100;
    QString defenseTowerPath = ":imgs/wizardTower.png";
    QString bulletPath = ":imgs/red_laser.png";
    int bulletDamage = 10;
    bullet::damage = bulletDamage;
    QString enemyPath = ":/imgs/gomel_walk011.gif";
    int enemyHealth = 50;
    int enemyDamage = 10;
    QString bgPath = ":imgs/mtland.png";
    QString fencePath = ":imgs/fence.png";
    int fenceHealth = 50;
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    int builderHeal = 10;
    QTime initialTime(0, 1, 0);


    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                              bulletPath, bulletDamage, enemyPath,
                              enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                              builderHutPath, builderPath, builderHeal, initialTime);
    //scenes->enemySpawner->timer->stop();
    this->view = scenes->renderScene();
    bossMagic::target = scenes->castlePosition;
    qDebug() << "Boss magic target: " << bossMagic::target;
    FinalBoss *finalBoss = new FinalBoss(nullptr, scenes->scene);
    scenes->scene->addItem(finalBoss);
    this->view->showFullScreen();
}

void game::onDisplayLVL2() {
    if (this->view) {
        this->view->close();
    }
    QList<QGraphicsItem*> items = this->scenes->scene->items();
    for (QGraphicsItem *item : items) {
        // Check if the item is a QGraphicsPixmapItem
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            // Remove the item from the scene
            this->scenes->scene->removeItem(item);
            // Delete the item to free memory
            delete item;
        }
    }
    if (this->scenes) {

        delete this->scenes;
    }

    CustomDialog winDialog;
    int result = winDialog.exec();
    if (result == QDialog::Accepted) {
        displayLVL2();
    } else {
        exit(0);
    }
}


void game::onDisplayLVL3() {
    // Call your displayLVL3 function
    if (this->view) {
        this->view->close();
    }
    QList<QGraphicsItem*> items = this->scenes->scene->items();
    for (QGraphicsItem *item : items) {
        // Check if the item is a QGraphicsPixmapItem
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            // Remove the item from the scene
            this->scenes->scene->removeItem(item);
            // Delete the item to free memory
            delete item;
        }
    }
    if (this->scenes) {

        delete this->scenes;
    }

    CustomDialog winDialog;
    int result = winDialog.exec();
    if (result == QDialog::Accepted) {
        displayLVL3();
    } else {
        exit(0);
    }
}

void game::onDisplayLVL4() {
    if (this->view) {
        this->view->close();
    }
    QList<QGraphicsItem*> items = this->scenes->scene->items();
    for (QGraphicsItem *item : items) {
        // Check if the item is a QGraphicsPixmapItem
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            // Remove the item from the scene
            this->scenes->scene->removeItem(item);
            // Delete the item to free memory
            delete item;
        }
    }
    if (this->scenes) {

        delete this->scenes;
    }

    CustomDialog winDialog;
    int result = winDialog.exec();
    if (result == QDialog::Accepted) {
        displayLVL4();
    } else {
        exit(0);
    }
}

void game::onDisplayLVL5() {
    if (this->view) {
        this->view->close();
    }
    QList<QGraphicsItem*> items = this->scenes->scene->items();
    for (QGraphicsItem *item : items) {
        // Check if the item is a QGraphicsPixmapItem
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            // Remove the item from the scene
            this->scenes->scene->removeItem(item);
            // Delete the item to free memory
            delete item;
        }
    }
    if (this->scenes) {

        delete this->scenes;
    }

    CustomDialog winDialog;
    int result = winDialog.exec();
    if (result == QDialog::Accepted) {
        displayLVL5();
    } else {
        exit(0);
    }
}

void game::onDisplayFinal() {
    // Call your displayFinal function
    if (this->view) {
        this->view->close();
    }
    QList<QGraphicsItem*> items = this->scenes->scene->items();
    for (QGraphicsItem *item : items) {
        // Check if the item is a QGraphicsPixmapItem
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            // Remove the item from the scene
            this->scenes->scene->removeItem(item);
            // Delete the item to free memory
            delete item;
        }
    }
    if (this->scenes) {

        delete this->scenes;
    }

    CustomDialog winDialog;
    int result = winDialog.exec();
    if (result == QDialog::Accepted) {
        displayFinal();
    } else {
        exit(0);
    }
}

