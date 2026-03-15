#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "addform.h"
#include "searchform.h"
#include "chartform.h"


struct dataStruct {
    int number=0;
    QString name=nullptr;
    int size=0;
    QString date=nullptr;
    int godnost=0;
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    void readData();
    void writeData();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool safe = 1;
    chartForm *graphWindow = nullptr;


protected:
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event);
    void updateTableSize();
    addForm *add;
    QMap<int, dataStruct> database;
    QString filePath;
    void updateTableData();
    void takeData(int number, QString name, int size,  QString date, int godnost);
    void takeDataToSearch(int number, QString name, int size,  QString date, int godnost);
    void closeEvent(QCloseEvent *event) override;
    void filterItemData();
    void filterItemSrok();
    void filterItemGodnost();
    void addTableItem(int key, const dataStruct &value);
    void drowGraphic();


private slots:
    void on_downloadBtn_clicked();
    void on_createBtn_clicked();
    void on_addBtn_clicked();
    void on_saveBtn_clicked();
    void on_delBtn_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void handleChartUpdate(QString productName);
};
#endif // MAINWINDOW_H
