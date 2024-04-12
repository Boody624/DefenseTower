#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QWidget>
#include <QPainter>

class HealthBar : public QWidget {
public:
    explicit HealthBar(QWidget *parent = nullptr);

    // Set current health and update the health bar
    void setHealth(int health);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int currentHealth;
};

#endif // HEALTHBAR_H
