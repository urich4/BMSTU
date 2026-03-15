#include "addform.h"
#include "ui_addform.h"
#include <QString>

addForm::addForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addForm)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit->setCalendarPopup(true);
}

addForm::~addForm()
{
    delete ui;
}

void addForm::on_pushButton_clicked()
{
    int number = ui->lineEdit->text().toInt();
    QString name=ui->lineEdit_2->text();
    int size=ui->lineEdit_3->text().toInt();
    QString date=ui->dateEdit->text();
    int godnost=ui->lineEdit_6->text().toInt();

    emit sendData(number, name, size, date, godnost);

    ui->dateEdit->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_6->clear();
}

