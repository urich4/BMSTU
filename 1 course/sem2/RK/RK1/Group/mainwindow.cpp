#include "mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Учет дипломников");
    resize(600, 400);


    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    titleLabel = new QLabel("Список студентов-дипломников", this);
    listWidget = new QListWidget(this);
    addButton = new QPushButton("Добавить студента", this);
    searchButton = new QPushButton("Поиск по дате", this);

    addButton->setCursor(Qt::PointingHandCursor);
    searchButton->setCursor(Qt::PointingHandCursor);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);


    QHBoxLayout *contentLayout = new QHBoxLayout();

    QVBoxLayout *buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(searchButton);
    buttonLayout->addStretch();

    contentLayout->addWidget(listWidget);
    contentLayout->addSpacing(10);
    contentLayout->addLayout(buttonLayout);

    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(contentLayout);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onAddButtonClicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Ввод данных", "Введите ФИО:", QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;

    QString dateStr = QInputDialog::getText(this, "Ввод данных", "Дата защиты (ДД.ММ.ГГГГ):", QLineEdit::Normal, "", &ok);
    if (!ok || dateStr.isEmpty()) return;

    QDate date = QDate::fromString(dateStr, "dd.MM.yyyy");

    try {
        if (!date.isValid()) {
            throw std::invalid_argument("Неверный формат даты!");
        }

        group.addGroup(Diplom(name, date));
        listWidget->addItem(name + " (Защита: " + date.toString("dd.MM.yyyy") + ")");

    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Ошибка", e.what());
    }
}

void MainWindow::onSearchButtonClicked()
{
    bool ok;
    QString dateStr = QInputDialog::getText(this, "Поиск", "Введите дату (ДД.ММ.ГГГГ):", QLineEdit::Normal, "", &ok);
    if (!ok || dateStr.isEmpty()) return;

    QDate searchDate = QDate::fromString(dateStr, "dd.MM.yyyy");

    try {
        if (!searchDate.isValid()) {
            throw std::invalid_argument("Введена некорректная дата!");
        }

        QVector<Diplom> found = group.findByDate(searchDate);

        listWidget->clear();
        listWidget->addItem("Найдены студенты на " + searchDate.toString("dd.MM.yyyy") + ":");

        for (const auto& student : found) {
            listWidget->addItem( student.getName());
        }

    } catch (const std::exception& e) {
        QMessageBox::information(this, "Результат", e.what());
    }
}

void MainWindow::onResetButtonClicked()
{
    listWidget->clear();
    for (const auto& student : group.getAllStudents()) {
        listWidget->addItem(student.getName() + " (Защита: " + student.getDef().toString("dd.MM.yyyy") + ")");
    }
}
