#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QResizeEvent>
#include <QHeaderView>
#include <QMap>
#include <QHash>
#include <QString>
#include <QFileDialog>
#include <QDir>
#include "addform.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QCloseEvent>
#include <QInputDialog>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QHBoxLayout>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    add = new addForm();
    connect(add, &addForm::sendData, this, &MainWindow::takeData);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTableSize(){
    int tableWidth = ui->tableWidget->viewport()->width() ;
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setColumnWidth(0, tableWidth * 0.15);
    ui->tableWidget->setColumnWidth(1, tableWidth * 0.25);
    ui->tableWidget->setColumnWidth(2, tableWidth * 0.2);
    ui->tableWidget->setColumnWidth(3, tableWidth * 0.18);
    ui->tableWidget->setColumnWidth(4, tableWidth * 0.22);
}


void MainWindow::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    updateTableSize();
}


void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    updateTableSize();
}




void MainWindow::on_downloadBtn_clicked()
{
    filePath = QFileDialog::getOpenFileName(
        this,
        "Выберите файл для загрузки",
        "C:/Users/user/Documents/BMSTUC/1 course/sem2/Практика/Task 1/ProdyctMagazine/data",
        "Текстовые файлы (*.txt);;Все файлы (*.*)"
        );
    if (filePath.isEmpty()) return;
    readData();
}


void MainWindow::on_createBtn_clicked()
{
    filePath = QFileDialog::getSaveFileName(
        this,
        "Создать и сохранить файл",
        "C:/Users/user/Documents/BMSTUC/1 course/sem2/Практика/Task 1/ProdyctMagazine/data",
        "Текстовые файлы (*.txt);;Все файлы (*.*)"
        );

    if (filePath.isEmpty()) {
        return;
    }

    QFile newFile(filePath);
    if (newFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        newFile.close();
    }
    readData();
}

void MainWindow::readData(){
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) qDebug() << "Ошибка";

    QTextStream out(&file);
    database.clear();
    while (!out.atEnd()) {
        QString line = out.readLine();
        QStringList parts = line.split(";");
        qDebug() << parts.size();
        if (parts.size() == 5) {
            int id = parts[0].toInt();
            dataStruct dataTemp;
            dataTemp.number = id;
            dataTemp.name = parts[1];
            dataTemp.size = parts[2].toInt();
            dataTemp.date = parts[3];
            dataTemp.godnost = parts[4].toInt();
            database.insert(id, dataTemp);
            qDebug() << "Запись";
        }
    }
    updateTableData();
    file.close();
}


void MainWindow::writeData(){
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) qDebug() << "Ошибка";
    QTextStream out(&file);
    QMapIterator<int, dataStruct> i(database);
    while (i.hasNext()) {
        i.next();
        int id = i.key();
        dataStruct dataTemp = i.value();
        out << id << ";"
            << dataTemp.name << ";"
            << dataTemp.size << ";"
            << dataTemp.date << ";"
            << dataTemp.godnost << "\n";
    }
    file.close();
}


void MainWindow::updateTableData(){
    ui->tableWidget->setRowCount(0);
    safe = 0;
    QMapIterator<int, dataStruct> i(database);

    while (i.hasNext()){
        i.next();
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        QTableWidgetItem *itemId = new QTableWidgetItem(QString::number(i.key()));
        QTableWidgetItem *itemName = new QTableWidgetItem(i.value().name);
        QTableWidgetItem *itemSize = new QTableWidgetItem(QString::number(i.value().size));
        QTableWidgetItem *itemDate = new QTableWidgetItem(i.value().date);
        QTableWidgetItem *itemGodnost = new QTableWidgetItem(QString::number(i.value().godnost));

        ui->tableWidget->setItem(row, 0, itemId);
        ui->tableWidget->setItem(row, 1, itemName);
        ui->tableWidget->setItem(row, 2, itemSize);
        ui->tableWidget->setItem(row, 3, itemDate);
        ui->tableWidget->setItem(row, 4, itemGodnost);
    }
}


void MainWindow::takeData(int number, QString name, int size,  QString date, int godnost){
    dataStruct dataTemp;
    dataTemp.number = number;
    dataTemp.name = name;
    dataTemp.size = size;
    dataTemp.date = date;
    dataTemp.godnost = godnost;

    database.insert(number, dataTemp);
    updateTableData();
}

void MainWindow::on_addBtn_clicked()
{
    if (filePath.isEmpty()) {QMessageBox::warning(this, "Внимание", "Файл не выбран.");
        return;}
    add->show();
}


void MainWindow::on_saveBtn_clicked()
{
    if (!filePath.isEmpty()){
        QMessageBox::information(this, "Информация", "Данные сохранены.");
    writeData();}
    else{
        QMessageBox::warning(this, "Внимание", "Файл не выбран.");
    }
    safe = 1;
}


void MainWindow::on_delBtn_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0){
        QMessageBox::warning(this, "Внимание", "Строка не выбрана.");
        return;
    }
    QTableWidgetItem *item = ui->tableWidget->item(row, 0);
    int id = item->text().toInt();
    database.remove(id);
    updateTableData();
}

void MainWindow::closeEvent(QCloseEvent *event){
    if (safe) event->accept();
    else {
        auto reply = QMessageBox::question(this, "Подтверждение выхода",
                                      "Вы уверены, что хотите закрыть программу?\nВсе несохраненные изменения будут потеряны.",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            event->accept();
        } else {
            event->ignore();
        }}
}


void MainWindow::on_pushButton_4_clicked()
{
    int text = ui->comboBox->currentIndex();
    qDebug() << text;
    switch (text){
        case 0:
            filterItemData();
            break;
        case 1:
            filterItemSrok();
            break;
        case 2:
            filterItemGodnost();
            break;
        case 3:
            drowGraphic();
            break;
        }
}

void MainWindow::filterItemGodnost(){
    int min = database.first().godnost;
    ui->tableWidget->setRowCount(0);
    QMapIterator<int, dataStruct> i(database);
    while (i.hasNext()){
        i.next();
        if (min > i.value().godnost) min =i.value().godnost;
    }
    i.toFront();
    while (i.hasNext()){
        i.next();
        if (i.value().godnost == min){
            addTableItem(i.key(), i.value());
        }
    }
}



void MainWindow::filterItemSrok() {
    ui->tableWidget->setRowCount(0);
    QMapIterator<int, dataStruct> i(database);
    while (i.hasNext()){
        i.next();

        if (QDate::fromString(i.value().date, "dd.MM.yyyy").addDays(i.value().godnost) == QDate::currentDate()){
            addTableItem(i.key(), i.value());
        }
    }
}


void MainWindow::filterItemData(){
    bool ok;
    QDate date;
    QString text = QInputDialog::getText(nullptr, "Ввод даты",
                                         "Введите дату в формате ДД.ММ.ГГГГ:",
                                         QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        date = QDate::fromString(text, "dd.MM.yyyy");

        if (date.isValid()) {
            qDebug() << "Пользователь ввел правильную дату:" << date;
        } else {
            QMessageBox::warning(nullptr, "Ошибка", "Неверный формат даты!");
    }
}

    ui->tableWidget->setRowCount(0);
    QMapIterator<int, dataStruct> i(database);
    while (i.hasNext()){
        i.next();

        if (QDate::fromString(i.value().date, "dd.MM.yyyy") > date){
            addTableItem(i.key(), i.value());
    }
}
}


void MainWindow::addTableItem(int key, const dataStruct &value){
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    QTableWidgetItem *itemId = new QTableWidgetItem(QString::number(key));
    QTableWidgetItem *itemName = new QTableWidgetItem(value.name);
    QTableWidgetItem *itemSize = new QTableWidgetItem(QString::number(value.size));
    QTableWidgetItem *itemDate = new QTableWidgetItem(value.date);
    QTableWidgetItem *itemGodnost = new QTableWidgetItem(QString::number(value.godnost));

    ui->tableWidget->setItem(row, 0, itemId);
    ui->tableWidget->setItem(row, 1, itemName);
    ui->tableWidget->setItem(row, 2, itemSize);
    ui->tableWidget->setItem(row, 3, itemDate);
    ui->tableWidget->setItem(row, 4, itemGodnost);
}


void MainWindow::drowGraphic(){
    QString targetProduct = QInputDialog::getText(this, "Построение графика", "Введите наименование товара:");

    if (targetProduct.isEmpty()) return;

    QMap<QDate, int> chartData;

    QMapIterator<int, dataStruct> i(database);
    while (i.hasNext()) {
        i.next();

        if (i.value().name == targetProduct) {
            QDate d = QDate::fromString(i.value().date, "dd.MM.yyyy");
            chartData[d] += i.value().size;
        }
    }

    if (chartData.isEmpty()) {
        QMessageBox::warning(this, "Пусто", "Такого товара нет в базе или поставок не было!");
        return;
    }

    QLineSeries *series = new QLineSeries();
    QMapIterator<QDate, int> j(chartData);
    while (j.hasNext()) {
        j.next();
        qreal x = j.key().startOfDay().toMSecsSinceEpoch();
        qreal y = j.value();
        series->append(x, y);
    }

    if (graphWindow == nullptr) {
        graphWindow = new chartForm(targetProduct, chartData);
        connect(graphWindow, &chartForm::requestNewData, this, &MainWindow::handleChartUpdate);
        connect(graphWindow, &QObject::destroyed, this, [this]() {
            graphWindow = nullptr;
        });
        graphWindow->show();
    } else {
        graphWindow->updateChart(targetProduct, chartData);
        graphWindow->activateWindow();
    }
}

void MainWindow::handleChartUpdate(QString productName) {
    QMap<QDate, int> chartData;
    QMapIterator<int, dataStruct> i(database);
    while (i.hasNext()) {
        i.next();
        if (i.value().name == productName) {
            QDate d = QDate::fromString(i.value().date, "dd.MM.yyyy");
            chartData[d] += i.value().size;
        }
    }
    if (chartData.isEmpty()) {
        QMessageBox::warning(this, "Пусто", "Такого товара нет в базе!");
        return;
    }
    if (graphWindow != nullptr) {
        graphWindow->updateChart(productName, chartData);
    }
}



void MainWindow::on_pushButton_clicked()
{
    updateTableData();
}

