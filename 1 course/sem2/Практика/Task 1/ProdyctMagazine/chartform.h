#ifndef CHARTFORM_H
#define CHARTFORM_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMap>
#include <QDate>
#include <QString>



class chartForm : public QWidget {
    Q_OBJECT

public:
    chartForm(const QString &productName, const QMap<QDate, int> &chartData);

    void updateChart(const QString &productName, const QMap<QDate, int> &chartData);

signals:
    void requestNewData(QString productName);

private slots:
    void onButtonClicked();

private:
    QLineEdit *productInput;
    QPushButton *buildButton;
    QChartView *chartView;
};

#endif // CHARTFORM_H
