// storydialog.h
#ifndef STORYDIALOG_H
#define STORYDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
class StoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StoryDialog(QWidget *parent = nullptr, QStringList bgs = QStringList(),
                         QStringList voices = QStringList(), QStringList speech = QStringList());
    int currentIndex;
    void setCharacterSpeech(const QString &speech);
    QString currentSpeech;
    QLabel *backgroundLabel;
    QString bgPath1;
    QString bgPath2;
    QString bgPath3;
    QString bgPath4;
    QString bgPath5;
    QString bgPath6;
    QMediaPlayer* bgsound = new QMediaPlayer();
    bool gameOver = false;
    bool bossBattle = false;

public slots:
    void showNextCharacter();


private:
    QLabel *characterSpeechLabel;
    QPushButton *nextButton;
    QStringList speechList;
    QTimer *animationTimer;
    QStringList bgs;
    QStringList voices;

    void startSpeechAnimation();

private slots:
    void nextSpeech();
};

#endif // STORYDIALOG_H
