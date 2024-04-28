#include "mainwindow.h"
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
#include "defence_unit.h"
#include "enemy.h"
#include "entry.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //entry e;
    //e.show();
    MainWindow w;
    w.show();

    // QGraphicsView view;
    // view.setFixedSize(800,800);
    // view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // QGraphicsScene* scene;
    // scene->setSceneRect(0,0,800,800);


    //Enemy* p1 = new Enemy(scene);

    // p1->setPos(0, 700);

    // p1->setFlag(QGraphicsItem::ItemIsFocusable);
    // p1->setFocus();
    // scene->addItem(p1);

    // view.setScene(scene);
    // view.show();

    return a.exec();
}
