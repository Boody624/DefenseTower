#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QAudioOutput>

class CustomDialog : public QDialog {
    Q_OBJECT
public:
    CustomDialog(QWidget *parent = nullptr, QString windowTitle = "", QString audioPath = "", qreal playbackRate = 1.0,
                 QString bgPath = "", QString message = "", QString order = "");
    QMediaPlayer* bgsound = new QMediaPlayer();
    QString windowTitle;
    QString audioPath;
    qreal playbackRate;
    QString bgPath;
    QString message;
    QString order;

private slots:
    //void continueClicked();

private:
    void setupUi();


};

#endif // CUSTOMDIALOG_H
