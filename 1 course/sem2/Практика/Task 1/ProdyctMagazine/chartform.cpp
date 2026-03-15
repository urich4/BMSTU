#include "chartform.h"

chartForm::chartForm(const QString &productName, const QMap<QDate, int> &chartData) {
    // 1. Создаем строку ввода и кнопку
    productInput = new QLineEdit(productName); // Сразу вписываем имя текущего товара
    buildButton = new QPushButton("Показать график");
    connect(buildButton, &QPushButton::clicked, this, &chartForm::onButtonClicked);

    // 2. Создаем верхнюю горизонтальную панель и кладем туда наши виджеты
    QHBoxLayout *topPanel = new QHBoxLayout();
    topPanel->addWidget(productInput);
    topPanel->addWidget(buildButton);

    // 3. Строим сам график (это твой готовый код)
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

    // Оборачиваем готовый chart в QChartView
    chartView = new QChartView(chart);

    // 4. Создаем главный вертикальный Layout для всего окна
    QVBoxLayout *mainLayout = new QVBoxLayout(this); // this означает, что layout ставится прямо в наше окно
    mainLayout->addLayout(topPanel);    // Сначала ставим верхнюю панель
    mainLayout->addWidget(chartView);   // Под ней размещаем график

    // 5. Настройки самого окна
    this->setWindowFlags(Qt::Window);
    this->resize(800, 600);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

void chartForm::onButtonClicked() {
    // Берем текст из поля ввода и отправляем сигнал главному окну
    QString newProduct = productInput->text();
    emit requestNewData(newProduct);
}

void chartForm::updateChart(const QString &productName, const QMap<QDate, int> &chartData) {
    // Создаем абсолютно чистый холст
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

    // Подменяем старый график на новый. Старый удалится из памяти сам.
    chartView->setChart(newChart);
}
