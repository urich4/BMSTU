#include "dialog.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>



Dialog::Dialog(QWidget *parent): QDialog(parent)
{
    LineEdit1 = new QLineEdit();
    LineEdit2 = new QTextEdit();
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QPushButton *btn = new QPushButton("Convert");

    QFont font = LineEdit2->font();
    font.setPointSize(16); // Размер шрифта 16
    LineEdit2->setFont(font);
    LineEdit2->setMinimumHeight(200);
    LineEdit1->setMinimumHeight(30);
    btn->setMinimumHeight(30);


    LineEdit2->setReadOnly(true);
    mainLayout->addWidget(LineEdit1);
    mainLayout->addWidget(btn);
    mainLayout->addWidget(LineEdit2);
    setLayout(mainLayout);

    connect(btn, SIGNAL(clicked()), this, SLOT(convert()));
    connect(LineEdit1, SIGNAL(editingFinished()), this, SLOT(input()));
}

void Dialog::convert(){
    static bool flag = 0;
    QString s = LineEdit1->text();
    if (flag) s = "ALL UPPER: " + s.toUpper();
    else s = "all lower: " + s.toLower();
    flag = !flag;
    LineEdit2->append(s);

}

void Dialog::input(){
    LineEdit2->setText("input: " + LineEdit1->text());
}
