#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include "student.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddButtonClicked();
    void onSearchButtonClicked();
    void onResetButtonClicked();

private:
    QWidget *centralWidget;
    QLabel *titleLabel;
    QListWidget *listWidget;
    QPushButton *addButton;
    QPushButton *searchButton;
    QPushButton *resetButton;
    Group group;
};
#endif // MAINWINDOW_H
