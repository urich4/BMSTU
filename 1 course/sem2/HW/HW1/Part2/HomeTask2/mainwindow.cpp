#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Перерисовка");
    resize(QSize(800,400));
    area = new Area();
    btn = new QPushButton("Закрыть");
    layout = new QVBoxLayout();
    QWidget *mainWidget = new QWidget();

    layout->addWidget(area);
    layout->addWidget(btn);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);

    connect(btn, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow() {}
