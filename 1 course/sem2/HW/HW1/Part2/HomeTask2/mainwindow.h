#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "area.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Area *area;
    QPushButton *btn;
    QVBoxLayout *layout;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
