#include "addform.h"
#include "ui_addform.h"
#include <QFile>

AddForm::AddForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddForm)
{
    ui->setupUi(this);
}

AddForm::~AddForm()
{
    delete ui;
}

void AddForm::on_pushButton_2_clicked()
{
    QFile file("data.txt");
    if ((file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))){
        QString name = ui->lineEdit->text(), surname = ui->lineEdit_2->text(), mobile = ui->lineEdit_3->text(), address = ui->lineEdit_4->text();
        QTextStream out(&file);
        out << name << " " << surname << " " << mobile << " " << address << "\n";
        file.close();
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();

}

