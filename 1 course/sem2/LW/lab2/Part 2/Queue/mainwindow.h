#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.cpp"
#include <string>
#include <QMessageBox>
#include "queueexception.h"

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
    void updateList();
    ~MainWindow();

private slots:
    void on_addBtn_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_delBtn_clicked();

    void on_sortBtn_clicked();

private:
    Ui::MainWindow *ui;
    Queue<int> *numbers;
    SortedQueue *strings;
    int indexCB = 0;
};
#endif // MAINWINDOW_H
