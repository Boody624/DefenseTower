#ifndef STR_H
#define STR_H
#include <QVector>
#include <QMap>
#include <QPoint>
#include <QList>
struct Node {
    qreal x;
    qreal y;
    int   g;
    int   h;
    qreal   f;
    Node* parent;
};
struct NodeComparator {
    bool operator()(const Node* lhs, const Node* rhs) const {
        // Compare nodes based on their f values
        return lhs->f > rhs->f;
    }
};

class str
{
public:
    str(QPointF startt, QPointF endd,QVector<QPointF> obstacless);
    QVector<QPoint> findPath(QVector<QVector<int>> graph);
    QVector<QPointF> obstacles;
    QPointF start;
    QPointF end;

};


#endif // STR_H
