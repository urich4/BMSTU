#ifndef ADDFORM_H
#define ADDFORM_H

#include <QWidget>

namespace Ui {
class addForm;
}

class addForm : public QWidget
{
    Q_OBJECT

public:
    explicit addForm(QWidget *parent = nullptr);
    ~addForm();


signals:
    void sendData(int number,
                  QString name,
                  int size,
                  QString date,
                  int godnost);

private slots:
    void on_pushButton_clicked();

private:
    Ui::addForm *ui;


};

#endif // ADDFORM_H
