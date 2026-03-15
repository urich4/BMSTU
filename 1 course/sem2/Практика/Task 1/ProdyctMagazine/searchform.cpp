#include "searchform.h"
#include "ui_searchform.h"

searchForm::searchForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchForm)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate().addDays(1));
    ui->dateEdit->setCalendarPopup(true);
}

searchForm::~searchForm()
{
    delete ui;
}


void searchForm::updateTableSize(){
    int tableWidth = ui->tableWidget->viewport()->width() ;
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setColumnWidth(0, tableWidth * 0.15);
    ui->tableWidget->setColumnWidth(1, tableWidth * 0.25);
    ui->tableWidget->setColumnWidth(2, tableWidth * 0.2);
    ui->tableWidget->setColumnWidth(3, tableWidth * 0.18);
    ui->tableWidget->setColumnWidth(4, tableWidth * 0.22);
}


void searchForm::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    updateTableSize();
}


void searchForm::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    updateTableSize();
}

void searchForm::on_pushButton_clicked()
{

}

