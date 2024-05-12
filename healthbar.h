#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QWidget>
#include <QPainter>
#include <QIcon>
#include <QLabel>
#include <QDialog>

class HealthBar : public QWidget
{
    Q_OBJECT
public:
    explicit HealthBar(QWidget *parent = nullptr);

    int value() const;
    int maxValue() const;
    void setValue(int value);
    void setMaxValue(int maxValue);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_value;
    int m_maxValue;
    QIcon m_healthIcon; // Icon to represent health
};


class ScoreWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreWidget(QWidget *parent = nullptr);

public slots:
    void updateScore();

private:
    QLabel *scoreLabel;
signals:
    void scoreUpdated(); // Signal emitted when the score is updated

};
class WeaponSelectDialog : public QDialog {
    Q_OBJECT
public:
    explicit WeaponSelectDialog(QWidget *parent = nullptr);

signals:
    void weaponSelected(int weaponIndex);

private:
    void setupUI();

private slots:
    void selectWeapon1();
    void selectWeapon2();
    void selectWeapon3();
};

#endif // HEALTHBAR_H
