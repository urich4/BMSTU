#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog *w = new Dialog();
    w->show();
    return app.exec();
}
