#ifndef DIALOG_EX2_H
#define DIALOG_EX2_H

#include <QMainWindow>
#include "ui_ex2.h"

// Важно: тут QMainWindow, а не просто MainWindow
class DialogEx2 : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    DialogEx2(QWidget *parent = nullptr);

private slots:
    void onExitClicked();
};

#endif // DIALOG_EX2_H
