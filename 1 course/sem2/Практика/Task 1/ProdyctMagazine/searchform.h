#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QWidget>

namespace Ui {
class searchForm;
}

class searchForm : public QWidget
{
    Q_OBJECT

public:
    explicit searchForm(QWidget *parent = nullptr);

    ~searchForm();

private slots:
    void on_pushButton_clicked();

signals:
    void sendData(int number,
                  QString name,
                  int size,
                  QString date,
                  int godnost);

private:
    Ui::searchForm *ui;
    void updateTableSize();
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event);
};

#endif // SEARCHFORM_H
