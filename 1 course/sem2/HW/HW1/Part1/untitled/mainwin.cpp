#include "mainwin.h"
#include "ui_mainwin.h"

mainwin::mainwin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainwin)
    , res (0.0)
    , oper('@')

{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    connect(ui->pushButton,SIGNAL(clicked(bool)),
            this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),
            this,SLOT(on_pushButton_2_clicked()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),
            this,SLOT(on_pushButton_2_clicked()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),
            this,SLOT(on_pushButton_2_clicked()));
    connect(ui->pushButton_5,SIGNAL(clicked(bool)),
            this,SLOT(on_pushButton_2_clicked()));
    connect(ui->pushButton_6,SIGNAL(clicked(bool)),
            this,SLOT(on_pushButton_2_clicked()));

}

mainwin::~mainwin()
{
    delete ui;
}

void mainwin::on_pushButton_2_clicked()
{
    double r = ui->lineEdit->text().toDouble();
    if (oper == '+') res += r;
    else
        if (oper == '-') res -=r;
    else
        if (oper == '*') res *= r;
    else
        if (oper == '/') res /= r;
    else res = r;


    QPushButton *buttonSender = qobject_cast<QPushButton*>(sender());
    oper = (buttonSender->text())[0];
    QString str;
    if (oper == '=') ui->lineEdit->setText(str.setNum(res));
    else ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}


void mainwin::on_pushButton_clicked()
{
    ui -> lineEdit -> clear();
    ui -> lineEdit -> setFocus();
    res = 0.0;    oper = '@';
}

