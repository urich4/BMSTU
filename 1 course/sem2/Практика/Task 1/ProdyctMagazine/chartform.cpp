#include "chartform.h"

chartForm::chartForm(const QString &productName, const QMap<QDate, int> &chartData) {
    productInput = new QLineEdit(productName);
    buildButton = new QPushButton("Показать график");
    connect(buildButton, &QPushButton::clicked, this, &chartForm::onButtonClicked);

    QHBoxLayout *topPanel = new QHBoxLayout();
    topPanel->addWidget(productInput);
    topPanel->addWidget(buildButton);

    QChart *chart = new QChart();
    chart->legend()->hide();
    QLineSeries *series = new QLineSeries();

    QMapIterator<QDate, int> j(chartData);
    while (j.hasNext()) {
        j.next();
        qreal x = j.key().startOfDay().toMSecsSinceEpoch();
        qreal y = j.value();
        series->append(x, y);
    }

    chart->addSeries(series);
    chart->setTitle("Динамика поступлений: " + productName);

    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setFormat("dd.MM.yyyy");
    axisX->setTitleText("Дата поставки");
    axisX->setTickCount(5);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Объем товара (шт)");
    axisY->setLabelFormat("%i");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    chartView = new QChartView(chart);


    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topPanel);
    mainLayout->addWidget(chartView);

    this->setWindowFlags(Qt::Window);
    this->resize(800, 600);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

void chartForm::onButtonClicked() {
    QString newProduct = productInput->text();
    emit requestNewData(newProduct);
}

void chartForm::updateChart(const QString &productName, const QMap<QDate, int> &chartData) {
    QChart *newChart = new QChart();
    newChart->legend()->hide();

    QLineSeries *series = new QLineSeries();
    QMapIterator<QDate, int> j(chartData);
    while (j.hasNext()) {
        j.next();
        qreal x = j.key().startOfDay().toMSecsSinceEpoch();
        qreal y = j.value();
        series->append(x, y);
    }

    newChart->addSeries(series);
    newChart->setTitle("Динамика поступлений: " + productName);

    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setFormat("dd.MM.yyyy");
    axisX->setTitleText("Дата поставки");
    axisX->setTickCount(5);
    newChart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Объем товара (шт)");
    axisY->setLabelFormat("%i");
    newChart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    chartView->setChart(newChart);
}
