#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
/// Класс, реализующий калькулятор
class Dialog: public QDialog
{
    Q_OBJECT
public:
    Dialog( QWidget * parent = 0);
    virtual ~Dialog(){};
protected:
    QLineEdit *LineEdit1;
    QTextEdit *LineEdit2;

private slots:
    void convert();
    void input();
};
#endif
