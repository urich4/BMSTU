#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class mainwin;
}
QT_END_NAMESPACE

class mainwin : public QWidget
{
    Q_OBJECT
    double res;
    QChar oper;
public:
    mainwin(QWidget *parent = nullptr);
    ~mainwin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::mainwin *ui;
};
#endif // MAINWIN_H
