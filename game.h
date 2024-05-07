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
    Scenes *scenes;
public slots:

    void onDisplayLVL2();
    void onDisplayLVL3();
    void onDisplayLVL4();
    void onDisplayLVL5();
    void onDisplayFinal();
signals:
    void clearLVL();

};

#endif // GAME_H
