#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sortBtn->setEnabled(false);
    numbers = new Queue;
    strings = new SortedQueue;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addBtn_clicked()
{
    QString text = ui->lineEdit->text();
    bool ok;
    int value = text.toInt(&ok);
    if (ui->comboBox->currentIndex() == 0){
        try{
        if (ok) numbers->addItem(new IntItem(value));
        else throw InvalidDataException();
        }
        catch (InvalidDataException& e){
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
        }
    }
    else{
        strings->addItem(new StrItem(text.toStdString()));
    }
    ui->lineEdit->clear();
    updateList();
}

void MainWindow::updateList(){
    ui->listWidget->clear();
    if (indexCB == 0){
        Node *first = numbers->getFirst();
        Node *current = first;
        while (current != nullptr){
            ui->listWidget->addItem(QString::fromStdString(current->item->toString()));
            current = current->next;
        }
    }
    else{
        Node *first = strings->getFirst();
        Node *current = first;
        while (current != nullptr){
            ui->listWidget->addItem(QString::fromStdString(current->item->toString()));
            current = current->next;
        }
    }

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    indexCB = index;
    if (indexCB) ui->sortBtn->setEnabled(true);
    else  ui->sortBtn->setEnabled(false);
    updateList();
}


void MainWindow::on_delBtn_clicked()
{
    try{
    if (indexCB == 0){
        numbers->delItem();
    }
    else
        strings->delItem();
    updateList();
    }
    catch (QueueEmptyException& e){
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
    }
}


void MainWindow::on_sortBtn_clicked()
{
    strings->sortQueue();
    updateList();
}

