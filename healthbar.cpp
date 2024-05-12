#include "healthbar.h"
#include <QPainterPath>
#include <QPainter>
#include <QVBoxLayout>
#include "bullet.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QPalette>
#include "game.h"

HealthBar::HealthBar(QWidget *parent)
    : QWidget(parent), m_value(100), m_maxValue(100)
{
}

int HealthBar::value() const
{
    return m_value;
}

int HealthBar::maxValue() const
{
    return m_maxValue;
}

void HealthBar::setValue(int value)
{
    if (value < 0)
        value = 0;
    else if (value > m_maxValue)
        value = m_maxValue;

    if (m_value != value) {
        m_value = value;
        update();
    }
}

void HealthBar::setMaxValue(int maxValue)
{
    m_maxValue = maxValue;
    update();
}

void HealthBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    setFixedHeight(20); // Adjust height as needed
    double percentage = static_cast<double>(m_value) / m_maxValue;

    // Background
    painter.setBrush(QColor("#E0E0E0")); // Light gray background color
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(0, 0, width(), height(), 10, 10); // Rounded rectangle shape

    // Health bar
    double fillWidth = percentage * width();
    QRectF healthBarRect(0, 0, fillWidth, height()); // Health bar rectangle
    QPainterPath healthBarPath;
    healthBarPath.addRoundedRect(healthBarRect, 10, 10); // Rounded rectangle shape
    painter.setBrush(Qt::green);
    if (percentage <= 0.35) {
        painter.setBrush(Qt::red);
    } else if (percentage <= 0.15) {
        painter.setBrush(Qt::darkRed);

    } else if (percentage <= 0.6) {
        painter.setBrush(Qt::yellow);
    }
    painter.drawPath(healthBarPath);

    // Add an icon (e.g., a heart) to the left of the health bar
    QPixmap iconPixmap(":/imgs/heartIcon.png"); // Assuming you have a heart icon
    QIcon icon(iconPixmap);
    QIcon::Mode mode = QIcon::Normal;
    QIcon::State state = QIcon::On;
    icon.paint(&painter, QRect(5, (height() - 20) / 2, 20, 20), Qt::AlignCenter, mode, state);

    // Display current health value
    QString text = QString("%1 / %2").arg(m_value).arg(m_maxValue);
    painter.setPen(Qt::black); // Black text color
    painter.setFont(QFont("Arial", 10)); // Adjust font and size as needed
    painter.drawText(rect(), Qt::AlignCenter, text);
}


ScoreWidget::ScoreWidget(QWidget *parent) : QWidget(parent)
{
    // Create and configure the QLabel to display the score
    scoreLabel = new QLabel(this);
    scoreLabel->setText("Score: " + QString::number(bullet::counter));
    scoreLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: white;");

    // Add an icon (e.g., a heart) to the left of the score text
    QPixmap iconPixmap(":/imgs/score.png"); // Assuming you have a heart icon
    QLabel *iconLabel = new QLabel(this);
    iconLabel->setPixmap(iconPixmap.scaled(24, 24)); // Adjust size as needed

    // Set the layout of the widget
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(iconLabel);
    layout->addWidget(scoreLabel);
    layout->setContentsMargins(10, 0, 10, 0); // Add margins to the layout
    layout->setSpacing(10); // Add spacing between icon and text
    setLayout(layout);

    // Set background color and rounded corners for the widget
    //setStyleSheet("background-color: rgba(0, 0, 0, 0.5); border-radius: 10px;");
}


void ScoreWidget::updateScore()
{
    // Update the score label with the new value
    scoreLabel->setText("Score: " + QString::number(bullet::counter));
    emit scoreUpdated(); // Emit the signal to notify other components

}

WeaponSelectDialog::WeaponSelectDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Weapon Selection");
    setupUI();
}
void WeaponSelectDialog::setupUI() {
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter); // Center align the content

    // Background texture
    // QPalette palette;
    // QPixmap bgTexture(":/imgs/texture.jpg");
    // palette.setBrush(QPalette::Background, bgTexture);
    // setAutoFillBackground(true);
    // setPalette(palette);

    // Horizontal layout for each weapon
    QHBoxLayout *weaponLayout = new QHBoxLayout;

    // Weapon 1
    QLabel *weapon1Label = new QLabel(this);
    QPixmap weapon1Pixmap(":/imgs/canon.png");
    weapon1Label->setPixmap(weapon1Pixmap.scaledToWidth(200));
    QLabel *weapon1InfoLabel = new QLabel("<font color='red'>Damage: 40<br>Speed: 10</font>", this);
    weapon1InfoLabel->setAlignment(Qt::AlignCenter); // Center align the text
    QPushButton *weapon1Button = new QPushButton("Select Canon", this);
    connect(weapon1Button, &QPushButton::clicked, this, &WeaponSelectDialog::selectWeapon1);

    // Weapon 2
    QLabel *weapon2Label = new QLabel(this);
    QPixmap weapon2Pixmap(":/imgs/archerTower.png");
    weapon2Label->setPixmap(weapon2Pixmap.scaledToWidth(200));
    QLabel *weapon2InfoLabel = new QLabel("<font color='red'>Damage: 10<br>Speed: 30</font>", this);
    weapon2InfoLabel->setAlignment(Qt::AlignCenter); // Center align the text
    QPushButton *weapon2Button = new QPushButton("Select Archer Tower", this);
    connect(weapon2Button, &QPushButton::clicked, this, &WeaponSelectDialog::selectWeapon2);

    // Weapon 3
    QLabel *weapon3Label = new QLabel(this);
    QPixmap weapon3Pixmap(":/imgs/wizardTower.png");
    weapon3Label->setPixmap(weapon3Pixmap.scaledToWidth(200));
    QLabel *weapon3InfoLabel = new QLabel("<font color='red'>Damage: 25<br>Speed: 20</font>", this);
    weapon3InfoLabel->setAlignment(Qt::AlignCenter); // Center align the text
    QPushButton *weapon3Button = new QPushButton("Select Wizard Tower", this);
    connect(weapon3Button, &QPushButton::clicked, this, &WeaponSelectDialog::selectWeapon3);

    // Add widgets to weapon layout
    weaponLayout->addWidget(weapon1Label);
    weaponLayout->addWidget(weapon1InfoLabel);
    weaponLayout->addWidget(weapon1Button);
    weaponLayout->addWidget(weapon2Label);
    weaponLayout->addWidget(weapon2InfoLabel);
    weaponLayout->addWidget(weapon2Button);
    weaponLayout->addWidget(weapon3Label);
    weaponLayout->addWidget(weapon3InfoLabel);

    weaponLayout->addWidget(weapon3Button);

    // Add weapon layout to main layout
    mainLayout->addLayout(weaponLayout);

    // Set spacing and margins
    mainLayout->setSpacing(20); // Add spacing between widgets
    mainLayout->setContentsMargins(20, 20, 20, 20); // Add margins to the layout

    // Set main layout
    setLayout(mainLayout);

    // Set dialog size
    setBaseSize(700, 400); // Set a fixed size for the dialog
    setWindowTitle("Select Weapon"); // Set dialog title
}



void WeaponSelectDialog::selectWeapon1() {
    game::weapon = 0;
    accept();
}

void WeaponSelectDialog::selectWeapon2() {
    game::weapon = 1;
    accept();

}
void WeaponSelectDialog::selectWeapon3() {
    game::weapon = 2;
    accept();

}
