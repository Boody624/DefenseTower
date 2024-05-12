#include "game.h"
#include "scenes.h"
#include "customdialogue.h"
#include "finalboss.h"
#include "bossmagic.h"
#include <QTimer>
#include "storydialogue.h"
#include "healthBar.h"
int game::difficulty = 0;
int game::weapon = 0;
game::game() {

}

void game::displayLVL1(){

    setGame( enemyHealth, enemyDamage, fenceHealth,
            builderHeal, bulletDamage, speed, defenseTowerPath,
            bulletPath, soundPath);


    int castleHealth = 100;
    QString designFilePath = ":/design/LVL1.txt";
    QString castlePath = ":imgs/castle.png";
    QString bgPath = ":imgs/mtland.png";
    QString fencePath = ":imgs/fence.png";
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    QTime initialTime(0, 5, 0);
    QString enemyPath = ":/imgs/moveEnemy4.gif";
    QString enemyAttack = ":/imgs/attackEnemy4.gif";
    QString enemyStill = ":/imgs/stillEnemy4.gif";

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                                bulletPath, bulletDamage, enemyPath,
                                enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                                builderHutPath, builderPath, builderHeal, initialTime, enemyAttack,
                              enemyStill, soundPath, speed);
    QObject::connect(scenes->scene, &myscene::displayLVL2, this, &game::onDisplayLVL2);
    this->view = scenes->renderScene();
    connect(scenes->castle, &Castle::gameOver, this, &game::onGameOver);
    connect(scenes->castle, &Castle::gameWon, this, &game::onGameWon);
    this->view->showFullScreen();

}

void game::displayLVL2(){

    setGame( enemyHealth, enemyDamage, fenceHealth,
            builderHeal, bulletDamage, speed, defenseTowerPath,
            bulletPath, soundPath);

    enemyHealth += 5;
    enemyDamage += 5;
    fenceHealth -= 5;
    builderHeal -= 1;
    bulletDamage -= 1;


    int castleHealth = 100;

    QString designFilePath = ":/design/LVL2.txt";
    QString castlePath = ":imgs/castle.png";
    QString bgPath = ":/imgs/sand.png";
    QString fencePath = ":/imgs/sandFence.png";
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    QTime initialTime(0, 4, 45);
    QString enemyPath = ":/imgs/moveEnemy4.gif";
    QString enemyAttack = ":/imgs/attackEnemy4.gif";
    QString enemyStill = ":/imgs/stillEnemy4.gif";

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                              bulletPath, bulletDamage, enemyPath,
                              enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                              builderHutPath, builderPath, builderHeal, initialTime, enemyAttack,
                              enemyStill, soundPath, speed);

    QObject::connect(scenes->scene, &myscene::displayLVL3, this, &game::onDisplayLVL3);
    this->view = scenes->renderScene();
    connect(scenes->castle, &Castle::gameOver, this, &game::onGameOver);
    connect(scenes->castle, &Castle::gameWon, this, &game::onGameWon);

    this->view->showFullScreen();

}

void game::displayLVL3(){
    setGame( enemyHealth, enemyDamage, fenceHealth,
            builderHeal, bulletDamage, speed, defenseTowerPath,
            bulletPath, soundPath);

    enemyHealth += 10;
    enemyDamage += 10;
    fenceHealth -= 5;
    builderHeal -= 1;
    bulletDamage -= 1;

    int castleHealth = 100;
    QString designFilePath = ":/design/LVL3.txt";
    QString castlePath = ":imgs/castle.png";
    QString bgPath = ":/imgs/pavement.png";
    QString fencePath = ":/imgs/coneFence.png";
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    QTime initialTime(0, 4, 30);
    QString enemyPath = ":/imgs/moveEnemy4.gif";
    QString enemyAttack = ":/imgs/attackEnemy4.gif";
    QString enemyStill = ":/imgs/stillEnemy4.gif";

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                              bulletPath, bulletDamage, enemyPath,
                              enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                              builderHutPath, builderPath, builderHeal, initialTime, enemyAttack,
                              enemyStill, soundPath, speed);
    QObject::connect(scenes->scene, &myscene::displayLVL4, this, &game::onDisplayLVL4);
    this->view = scenes->renderScene();
    connect(scenes->castle, &Castle::gameOver, this, &game::onGameOver);
    connect(scenes->castle, &Castle::gameWon, this, &game::onGameWon);

    this->view->showFullScreen();
}

void game::displayLVL4(){
    setGame( enemyHealth, enemyDamage, fenceHealth,
            builderHeal, bulletDamage, speed, defenseTowerPath,
            bulletPath, soundPath);
    enemyHealth += 10;
    enemyDamage += 10;
    fenceHealth -= 5;
    builderHeal -= 2;
    bulletDamage -= 2;

    int castleHealth = 100;
    QString designFilePath = ":/design/LVL4.txt";
    QString castlePath = ":imgs/castle.png";
    QString bgPath = ":/imgs/snow.png";
    QString fencePath = ":/imgs/iceFence.png";
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    QTime initialTime(0, 4, 15);
    QString enemyPath = ":/imgs/moveEnemy4.gif";
    QString enemyAttack = ":/imgs/attackEnemy4.gif";
    QString enemyStill = ":/imgs/stillEnemy4.gif";

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                              bulletPath, bulletDamage, enemyPath,
                              enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                              builderHutPath, builderPath, builderHeal, initialTime, enemyAttack,
                              enemyStill, soundPath, speed);
    QObject::connect(scenes->scene, &myscene::displayLVL5, this, &game::onDisplayLVL5);
    this->view = scenes->renderScene();
    connect(scenes->castle, &Castle::gameOver, this, &game::onGameOver);
    connect(scenes->castle, &Castle::gameWon, this, &game::onGameWon);

    this->view->showFullScreen();
}

void game::displayLVL5(){
    setGame( enemyHealth, enemyDamage, fenceHealth,
            builderHeal, bulletDamage, speed, defenseTowerPath,
            bulletPath, soundPath);
    enemyHealth += 10;
    enemyDamage += 10;
    fenceHealth -= 8;
    builderHeal -= 3;
    bulletDamage -= 3;
    int castleHealth = 100;

    QString designFilePath = ":/design/LVL5.txt";
    QString castlePath = ":imgs/castle.png";
    QString bgPath = ":/imgs/wood.png";
    QString fencePath = ":/imgs/barrelFence.png";
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    QTime initialTime(0, 4, 0);
    QString enemyPath = ":/imgs/moveEnemy4.gif";
    QString enemyAttack = ":/imgs/attackEnemy4.gif";
    QString enemyStill = ":/imgs/stillEnemy4.gif";

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                              bulletPath, bulletDamage, enemyPath,
                              enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                              builderHutPath, builderPath, builderHeal, initialTime, enemyAttack,
                              enemyStill, soundPath, speed);
    QObject::connect(scenes->scene, &myscene::displayFinal, this, &game::onDisplayFinal);
    this->view = scenes->renderScene();
    connect(scenes->castle, &Castle::gameOver, this, &game::onGameOver);
    connect(scenes->castle, &Castle::gameWon, this, &game::onGameWon);

    this->view->showFullScreen();
}

void game::displayFinal(){

    setGame( enemyHealth, enemyDamage, fenceHealth,
            builderHeal, bulletDamage, speed, defenseTowerPath,
            bulletPath, soundPath);
    int castleHealth = 100;
    enemyHealth += 12;
    enemyDamage += 12;
    fenceHealth -= 6;
    builderHeal -= 2;
    bulletDamage -= 2;
    QString designFilePath = ":/design/LVLFinal.txt";
    QString castlePath = ":imgs/castle.png";
    QString bgPath = ":/imgs/stone.png";
    QString fencePath = ":imgs/stoneFence.png";
    QString builderHutPath = ":imgs/builderHut.png";
    QString builderPath = ":imgs/builder.png";
    QTime initialTime(0, 1, 0);
    QString enemyPath = ":/imgs/moveEnemy4.gif";
    QString enemyAttack = ":/imgs/attackEnemy4.gif";
    QString enemyStill = ":/imgs/stillEnemy4.gif";

    this->scenes = new Scenes(designFilePath, castlePath, castleHealth, defenseTowerPath,
                              bulletPath, bulletDamage, enemyPath,
                              enemyHealth, enemyDamage, bgPath, fencePath, fenceHealth,
                              builderHutPath, builderPath, builderHeal, initialTime, enemyAttack,
                              enemyStill, soundPath, speed);
    //scenes->enemySpawner->timer->stop();
    this->view = scenes->renderScene();
    bossMagic::target = scenes->castlePosition;
    connect(scenes->castle, &Castle::gameOver, this, &game::onGameOver);
    connect(scenes->castle, &Castle::gameWon, this, &game::onGameWon);
    qDebug() << "Boss magic target: " << bossMagic::target;
    FinalBoss *finalBoss = new FinalBoss(nullptr, scenes->scene);
    scenes->scene->addItem(finalBoss);
    this->view->showFullScreen();
}

void game::onDisplayLVL1() {
    // if (this->view) {
    //     this->view->close();
    // }
    // QTimer::singleShot(2000, [=]() {
    //     if (this->scenes->scene) {
    //         delete this->scenes->scene;
    //     }
    // });

    WeaponSelectDialog weaponDialog;
    weaponDialog.show();
    int result = weaponDialog.exec();
    if (result == QDialog::Accepted) {
        displayLVL1();
    }

}


void game::onDisplayLVL2() {
    if (this->view) {
        this->view->close();
    }
    QList<QGraphicsItem*> items = this->scenes->scene->items();
    for (QGraphicsItem *item : items) {
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            this->scenes->scene->removeItem(item);
            delete item;

        }
    }
    QTimer::singleShot(2000, [=]() {
        if (this->scenes) {
            delete this->scenes;
        }
    });


    QString windowTitle = "Congratulations!";
    QString audioPath = "qrc:/sounds/themeMusic.mp3";
    qreal playBackRate = 0.8;
    QString bgPath = ":imgs/design.png";
    QString message = "Congratulations! You have passed lvl 1! Ready for level 2?";
    QString order = "Continue";
    CustomDialog winDialog(nullptr, windowTitle, audioPath, playBackRate, bgPath, message, order);
    int result = winDialog.exec();
    if (result == QDialog::Accepted) {
        if(winDialog.bgsound->isPlaying())
        {
            winDialog.bgsound->stop();
        }
        WeaponSelectDialog weaponDialog;
        weaponDialog.show();
        int result = weaponDialog.exec();
        if (result == QDialog::Accepted) {
            displayLVL2();

        }
    } else {
        exit(0);
    }
}


void game::onDisplayLVL3() {
    if (this->view) {
        this->view->close();
    }
    QList<QGraphicsItem*> items = this->scenes->scene->items();
    for (QGraphicsItem *item : items) {
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            this->scenes->scene->removeItem(item);
            delete item;

        }
    }
    QTimer::singleShot(2000, [=]() {
        if (this->scenes) {
            delete this->scenes;
        }
    });

    QString windowTitle = "Congratulations!";
    QString audioPath = "qrc:/sounds/themeMusic.mp3";
    qreal playBackRate = 0.8;
    QString bgPath = ":imgs/design.png";
    QString message = "Congratulations! You have passed lvl 2! Ready for level 3?";
    QString order = "Continue";
    CustomDialog winDialog(nullptr, windowTitle, audioPath, playBackRate, bgPath, message, order);
    int result = winDialog.exec();
    if (result == QDialog::Accepted) {
        if(winDialog.bgsound->isPlaying())
        {
            winDialog.bgsound->stop();
        }
        WeaponSelectDialog weaponDialog;
        weaponDialog.show();
        int result = weaponDialog.exec();
        if (result == QDialog::Accepted) {
            displayLVL3();
        }
    }
    else {
        exit(0);
    }
}

void game::onDisplayLVL4() {
    if (this->view) {
        this->view->close();
    }
    QList<QGraphicsItem*> items = this->scenes->scene->items();
    for (QGraphicsItem *item : items) {
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            this->scenes->scene->removeItem(item);
            delete item;

        }
    }
    QTimer::singleShot(2000, [=]() {
        if (this->scenes) {
            delete this->scenes;
        }
    });
    QString windowTitle = "Congratulations!";
    QString audioPath = "qrc:/sounds/themeMusic.mp3";
    qreal playBackRate = 0.8;
    QString bgPath = ":imgs/design.png";
    QString message = "Congratulations! You have passed lvl 3! Ready for level 4?";
    QString order = "Continue";
    CustomDialog winDialog(nullptr, windowTitle, audioPath, playBackRate, bgPath, message, order);
    int result = winDialog.exec();
    if (result == QDialog::Accepted) {
        if(winDialog.bgsound->isPlaying())
        {
            winDialog.bgsound->stop();
        }
        WeaponSelectDialog weaponDialog;
        weaponDialog.show();
        int result = weaponDialog.exec();
        if (result == QDialog::Accepted) {
            displayLVL4();
        }
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
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            this->scenes->scene->removeItem(item);
            delete item;

        }
    }
    QTimer::singleShot(2000, [=]() {
        if (this->scenes) {
            delete this->scenes;
        }
    });

    QString windowTitle = "Congratulations!";
    QString audioPath = "qrc:/sounds/themeMusic.mp3";
    qreal playBackRate = 0.8;
    QString bgPath = ":imgs/design.png";
    QString message = "Congratulations! You have passed lvl 4! Ready for level 5?";
    QString order = "Continue";
    CustomDialog winDialog(nullptr, windowTitle, audioPath, playBackRate, bgPath, message, order);
    int result = winDialog.exec();
    if (result == QDialog::Accepted) {
        if(winDialog.bgsound->isPlaying())
        {
            winDialog.bgsound->stop();
        }
        WeaponSelectDialog weaponDialog;
        weaponDialog.show();
        int result = weaponDialog.exec();
        if (result == QDialog::Accepted) {
            displayLVL5();
        }
    } else {
        exit(0);
    }
}

void game::onDisplayFinal() {
    //Close the view if it exists
    if (this->view) {
        this->view->close();
    }
    QList<QGraphicsItem*> items = this->scenes->scene->items();
    for (QGraphicsItem *item : items) {
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            this->scenes->scene->removeItem(item);
            delete item;

        }
    }
    QTimer::singleShot(2000, [=]() {
        if (this->scenes) {
            delete this->scenes;
        }
    });

        QStringList speech = {"Thank you so much! You have killed the devilish spirit!",
                              "You pitiful fool. You dare to think that you've bested me? "
                              "That feeble attempt barely even scratched the surface of my true power. "
                              "Now, prepare yourself, for what you are about to witness is the unleashing of CHAOS itself! " };
        QStringList bgs = {":/imgs/2.jpg", ":/imgs/final_boss.png"};
        QStringList voices = {"qrc:/sounds/15.wav", "qrc:/sounds/16.wav"};
        StoryDialog* story = new StoryDialog(nullptr, bgs, voices, speech);
        story->bossBattle = true;
        story->show();

}


void game::onGameOver() {
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
            QTimer::singleShot(2000, [=]() {
                delete item;
            });
        }
    }
    if (this->scenes) {
        QTimer::singleShot(2000, [=]() {
            delete this->scenes;
        });
    }

    QString windowTitle = "Game Over!";
    QString audioPath = "qrc:/sounds/gameOver.mp3";
    qreal playBackRate = 0.8;
    QString bgPath = ":imgs/design.png";
    QString message = "The enemies have invaded the caslte, you have lost!";
    QString order = "Try again?";
    CustomDialog loseDialog(nullptr, windowTitle, audioPath, playBackRate, bgPath, message, order);
    loseDialog.bgsound->setLoops(1);
    int result = loseDialog.exec();
    if (result == QDialog::Accepted) {
        if(loseDialog.bgsound->isPlaying())
        {
            loseDialog.bgsound->stop();
        }
        displayLVL1();
    } else {
        exit(0);
    }

}

void game::onGameWon()
{
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
            QTimer::singleShot(2000, [=]() {
                delete item;
            });
        }
    }
    if (this->scenes) {
        QTimer::singleShot(2000, [=]() {
            delete this->scenes;
        });
    }

    QStringList speech = {"Wow! You saved us! The castle is safe again, thanks to you!",
                        "Let's hope that the devilish spirit never returns again! Thank you for playing!"};

    QStringList bgs = {":/imgs/2.jpg", ":/imgs/2.jpg"};
    QStringList voices = {"qrc:/sounds/7.wav", "qrc:/sounds/8.wav"};
    StoryDialog* story = new StoryDialog(nullptr, bgs, voices, speech);
    story->gameOver = true;
    story->exec();
}

void game::setGame(int &enemyHealth, int &enemyDamage, int &fenceHealth, int &builderHeal, int &bulletDamage, float &speed, QString &defenseTowerPath, QString &bulletPath, QString &soundPath)
{
    if(game::difficulty == 0)
    {
        qDebug()<<"Difficulty is 0";
        enemyHealth = 30;
        enemyDamage = 10;
        fenceHealth = 50;
        builderHeal = 9;
        bossMagic::damage = 20;
    }
    else if(game::difficulty == 1)
    {
        qDebug()<<"Difficulty is 1";
        enemyHealth = 40;
        enemyDamage = 15;
        fenceHealth = 40;
        builderHeal = 11;
        bossMagic::damage = 30;
    }
    else
    {
        qDebug()<<"Difficulty is 2";
        enemyHealth = 50;
        enemyDamage = 20;
        fenceHealth = 30;
        builderHeal = 5;
        bossMagic::damage = 40;
    }

    if(weapon == 0)
    {
        qDebug()<<"Weapon is 0";
        bulletDamage = 40;
        speed = 10;
        defenseTowerPath = ":/imgs/canon.png";
        bulletPath = ":/imgs/cannonBullet.gif";
        soundPath = "qrc:/sounds/cannon.wav";
    }
    else if(weapon == 1)
    {
        qDebug()<<"Weapon is 1";
        bulletDamage = 10;
        speed = 30;
        defenseTowerPath = ":/imgs/archerTower.png";
        bulletPath = ":/imgs/arrow.png";
        soundPath = "qrc:/sounds/arrow.mp3";
    }
    else
    {
        qDebug()<<"Weapon is 2";
        bulletDamage = 25;
        speed = 20;
        defenseTowerPath = ":/imgs/wizardTower.png";
        bulletPath = ":/imgs/wizardBullet.gif";
        soundPath = "qrc:/sounds/magic.wav";
    }
}
