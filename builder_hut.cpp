#include "builder_hut.h"

builder_hut::builder_hut(QGraphicsScene* thescene) : QObject(), QGraphicsPixmapItem(), thescene(thescene) {
    thescene->addItem(this);

    // setting the image
    QString path = ":/imgs/builderHut.png";
    QPixmap img3 = (path);
    setPixmap(img3.scaled(50, 50));
    spawnBuilder();
    // QObject::connect(&timer, &QTimer::timeout, this, &builder_hut::goToDamagedFence);
    // timer.start(2000); // Adjust the interval as needed for enemy spawn rate
}

builder_hut::~builder_hut() {
    // Disconnect timer when object is destroyed
    //QObject::disconnect(&timer, &QTimer::timeout, this, &builder_hut::goToDamagedFence);
}

void builder_hut::spawnBuilder() {
    // Create an Builder object
    Builder *builder = new Builder();
    //make the builder's position the same as the builder hut
    builder->setPos(x(), y());
    thescene->addItem(builder);
}

