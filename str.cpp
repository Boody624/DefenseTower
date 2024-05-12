#include "str.h"
#include "enemy.h"
#include <QDebug>
#include <queue>
#include <vector>
#include <QMap>
bool operator<(const QPoint& lhs, const QPoint& rhs) {
    if (lhs.x() < rhs.x()) {
        return true;
    } else if (lhs.x() > rhs.x()) {
        return false;
    }
    // if x-coordinates are equal, compare y-coordinates
    return lhs.y() < rhs.y();
}
str::str(QPointF startt, QPointF endd, QVector<QPointF> obstacless) {
    start = startt;
    end = endd;
    obstacles = obstacless;
}


QVector<QPoint> str::findPath(QVector<QVector<int>> graph) {
    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> openList;
    QMap<QPoint, Node*> nodeMap;

    Node* startNode = new Node{start.x(), start.y(), 0, 0, 0, nullptr};
    openList.push(startNode);
    nodeMap.insert(QPoint(start.x(), start.y()), startNode);

    while (!openList.empty()) {
        Node* currentNode = openList.top();
        openList.pop();

        if (currentNode->x == end.x() && currentNode->y == end.y()) {
            QVector<QPoint> path;
            while (currentNode != nullptr) {
                path.prepend(QPoint(currentNode->x, currentNode->y));
                currentNode = currentNode->parent;
            }
            return path;
        }

        QVector<Node*> neighbors;
        QVector<int> dx = {0, 1, 0, -1};
        QVector<int> dy = {-1, 0, 1, 0};

        for (int i = 0; i < dx.size(); ++i) {
            qreal neighborX = currentNode->x + dx[i];
            qreal neighborY = currentNode->y + dy[i];

            if (neighborX >= 0 && neighborX < graph.at(0).size() && neighborY >= 0 && neighborY < graph.size()) {
                QPoint neighborPoint(neighborX, neighborY);
                if (!obstacles.contains(neighborPoint)) {
                    Node* neighborNode = new Node{neighborX, neighborY, 0, 0, 0, currentNode};
                    neighbors.append(neighborNode);
                }
            }
        }

        for (Node* neighbor : neighbors) {
            QPoint neighborPoint(neighbor->x, neighbor->y);
            int weight = graph[neighbor->y][neighbor->x];
            int newG = currentNode->g + weight;

            auto it = nodeMap.find(neighborPoint);
            if (it != nodeMap.end()) {
                Node* neighborNode = it.value();
                if (newG < neighborNode->g) {
                    neighborNode->g = newG;
                    neighborNode->f = newG + neighborNode->h;
                    neighborNode->parent = currentNode;
                    openList.push(neighborNode);
                }
            } else {
                neighbor->g = newG;
                qreal h = qAbs(neighbor->x - end.x()) + qAbs(neighbor->y - end.y());
                neighbor->h = h;
                neighbor->f = newG + h;
                openList.push(neighbor);
                nodeMap.insert(neighborPoint, neighbor);
            }
        }
    }

    return QVector<QPoint>(); // handle when no path found
}
