#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QTextCodec>
#include <QVBoxLayout>
// Преобразуем входную последовательность символов в кодировку UNICODE
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Создаем главное окно
    QWidget *hbox = new QWidget();
    hbox->setWindowTitle("Введите Ваш Возраст");
    QSpinBox *spinBox = new QSpinBox( hbox );
    QSlider *slider = new QSlider(Qt::Horizontal, hbox );
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);
    spinBox->setValue(35);
    QPushButton * btn = new QPushButton("Завершение", hbox );
    //***************************************************************************
    QVBoxLayout *layout = new QVBoxLayout; // выравнивание по горизонтали
    //QVBoxLayout *layout = new QVBoxLayout; // выравнивание по вертикали


    hbox->setLayout(layout); // связываем layout с hbox
    // устанавливаем порядок следования элементов
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    layout->addWidget(btn);
    //***************************************************************************
    // связываем сигнал изменения spinBox со слотом slider
    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                     slider, SLOT(setValue(int)));
    // связываем сигнал изменения slider со слотом spinBox
    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     spinBox, SLOT(setValue(int)));
    // связываем сигнал нажатия btn со слотом close главного окна
    QObject::connect(btn, SIGNAL(clicked(bool)),
                     hbox, SLOT(close()));
    hbox->show(); // отображаем окно
    return app.exec(); // запускаем цикл обработки сообщений
}
