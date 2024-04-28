#ifndef TROOPS_H
#define TROOPS_H

class troops : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int health = 1;


public:
    troops();
};

#endif // TROOPS_H
