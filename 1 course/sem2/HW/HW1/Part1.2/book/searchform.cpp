#include "searchform.h"
#include "ui_searchform.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

SearchForm::SearchForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchForm)
{
    ui->setupUi(this);
}

SearchForm::~SearchForm()
{
    delete ui;
}

void SearchForm::on_pushButton_clicked()
{
    QString searchSurname = ui->lineEdit->text(), searchName = ui->lineEdit_2->text();
    QFile file("data.txt");
    ui->listWidget->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        bool found = false;
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            qDebug() << "Прочитана строка из файла:" << line;
            if (sravni(line, searchSurname, searchName)) {
                ui->listWidget->addItem(line);
                found = true;
            }
        }
        file.close();
        if (!found) {
            QMessageBox::information(this, "Результат", "По вашему запросу ничего не найдено.");
        }

    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл с данными");
    }
}

bool SearchForm::sravni(QString line, QString searchSurname, QString searchName) {
    int firstSpace = line.indexOf(' ');
    int secondSpace = line.indexOf(' ', firstSpace + 1);
    QString surnameFromFile = line.left(firstSpace);
    qDebug() << surnameFromFile;
    QString nameFromFile = line.mid(firstSpace + 1, secondSpace - firstSpace - 1);
    qDebug() << nameFromFile;
    if (searchName.isEmpty() && surnameFromFile == searchSurname) return true;
    if (searchSurname.isEmpty() && searchName == nameFromFile) return true;
    return (surnameFromFile == searchSurname && nameFromFile == searchName);
    }

void SearchForm::on_pushButton_3_clicked()
{
    QString selectedLine = ui->listWidget->currentItem()->text();
    QStringList lines;
    qDebug() << selectedLine;
    QFile file("data.txt");
    QFile fileTemp("temp.txt");
    if (file.open(QIODevice::ReadWrite) && fileTemp.open(QIODevice::ReadWrite)){
        QTextStream streamData(&file);
        QTextStream streamTemp(&file);
        while (!streamData.atEnd()){
            QString line = streamData.readLine();
            if (line != selectedLine) streamTemp << line << "\n";
        }
        file.resize(0);
        while (!streamTemp.atEnd()){
            streamData << streamTemp.readLine() << "\n";
        }
        file.close();
        fileTemp.close();
        on_pushButton_clicked();
    }
}


void SearchForm::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->listWidget->clear();
}

