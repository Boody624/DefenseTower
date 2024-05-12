// optionsdialog.h
#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPushButton>
#include <QComboBox>

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(QWidget *parent = nullptr);

    void setVolume(int volume);
    void setDifficulty(int difficulty);
    float currentVolume = 1.0;

signals:
    void volumeChanged(int volume);
    void difficultyChanged(int difficulty);

private slots:
    void onVolumeChanged(int volume);
    void onDifficultyChanged();
    void toggleAboutText();

private:
    QSlider *volumeSlider;
    QComboBox *difficultyComboBox;
    QLabel *aboutTextLabel;
    QPushButton *aboutButton;
};

#endif // OPTIONSDIALOG_H
