#ifndef ENTRY_H
#define ENTRY_H

#include <QDialog>
#include <QFile>
#include <QIODevice>
#include <QIODeviceBase>
#include <QTextStream>
#include <QDebug>
#include <QUrl>
#include <QString>
#include <QVector>
namespace Ui {
class entry;
}

class entry : public QDialog
{
    Q_OBJECT

public:
    explicit entry(QWidget *parent = nullptr);
    ~entry();
    QVector<QString> usernames ={"admin"};
    QVector<QString> passwords ={"admin"};

private slots:
    void on_logbutton_clicked();

    void on_signbutton_clicked();

private:
    Ui::entry *ui;
};

#endif // ENTRY_H
