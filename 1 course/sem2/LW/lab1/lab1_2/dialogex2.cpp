#include "dialogex2.h"
#include <QTextCodec>
#include <QMessageBox>


#define RUS(str) QString::fromUtf8(str)

DialogEx2::DialogEx2(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    connect(pushButton, SIGNAL(clicked()), this, SLOT(onExitClicked()));
}

void DialogEx2::onExitClicked()
{

    if (QMessageBox::question(this, QString(),
                              RUS("Завершить приложение?"),
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        exit(0);
    }
}
