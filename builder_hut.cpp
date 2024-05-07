#include "builder_hut.h"

builder_hut::builder_hut(QGraphicsScene* thescene, QVector<Fence*> fences, QString builderHutPath, QString builderPath, int builderHeal) : QObject(), QGraphicsPixmapItem(), thescene(thescene) {
    thescene->addItem(this);
    this->builderHutPath = builderHutPath;
    this->builderPath = builderPath;
    this->builderHeal = builderHeal;
    // setting the image
    QString path = builderHutPath;
    QPixmap img3 = (path);
    this->fences = fences;
    setPixmap(img3.scaled(50, 50));
}

builder_hut::~builder_hut() {
    // Disconnect timer when object is destroyed
    //QObject::disconnect(&timer, &QTimer::timeout, this, &builder_hut::goToDamagedFence);
}

void builder_hut::spawnBuilder() {
    // Create an Builder object
    Builder *builder = new Builder(origin, builderPath, builderHeal);
    //make the builder's position the same as the builder hut
    builder->setPos(this->x(), this->y());
    thescene->addItem(builder);
}





