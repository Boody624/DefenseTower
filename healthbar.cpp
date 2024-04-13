/*#include "healthbar.h"

HealthBar::HealthBar(QWidget *parent) : QWidget(parent), currentHealth(100) {}

void HealthBar::setHealth(int health) {
    currentHealth = health;
    update(); // Trigger repaint
}

void HealthBar::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Draw background
    painter.fillRect(rect(), Qt::black);

    // Calculate the width of the health bar based on current health
    int barWidth = static_cast<int>(width() * (currentHealth / 100.0));

    // Draw health bar
    painter.fillRect(0, 0, barWidth, height(), Qt::green);
}*/
