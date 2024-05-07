#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QDialog>

class CustomDialog : public QDialog {
    Q_OBJECT
public:
    CustomDialog(QWidget *parent = nullptr);

private slots:
    //void continueClicked();

private:
    void setupUi();


};

#endif // CUSTOMDIALOG_H
