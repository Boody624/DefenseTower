#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMediaPlayer* bgsound = new QMediaPlayer();


private slots:
    void on_Exit_clicked();

    void on_Start_clicked();

    void on_Options_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
