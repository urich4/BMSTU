#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addform.h"
#include "searchform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AddForm *add = new AddForm();
    SearchForm search;

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    add.show();
}



void MainWindow::on_pushButton_2_clicked()
{
    search.show();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}
void MainWindow::closeEvent(QCloseEvent *event) {
    QApplication::quit();
    event->accept();
}
