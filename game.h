#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QMessageBox>
#include <QDialog>
#include "scenes.h"
class game : public QObject
{
    Q_OBJECT
public:
    game();
    void displayLVL1();
    void displayLVL2();
    void displayLVL3();
    void displayLVL4();
    void displayLVL5();
    void displayFinal();
    QGraphicsView* view;
    static int difficulty;
    static int weapon;
    Scenes *scenes;
    int enemyHealth;
    int enemyDamage;
    int fenceHealth;
    int builderHeal;
    int bulletDamage;
    float speed;
    QString defenseTowerPath;
    QString bulletPath;
    QString soundPath;

public slots:
    void onDisplayLVL1();
    void onDisplayLVL2();
    void onDisplayLVL3();
    void onDisplayLVL4();
    void onDisplayLVL5();
    void onDisplayFinal();
    void onGameOver();
    void onGameWon();
    void setGame(int &enemyHealth, int &enemyDamage, int &fenceHealth, int &builderHeal,
                 int & bulletDamage,  float &speed, QString & defensePath, QString & bulletPath, QString& soundPath);
signals:
    void clearLVL();

};

#endif // GAME_H
