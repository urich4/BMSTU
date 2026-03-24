#include "area.h"

Area::Area(QWidget *parent): QWidget(parent) {
    speed = 0.1;
    alpha = 0;
    LO = new LetterO(1, 1, 50, 50);
    LC = new LetterC(width() / 3 , 1, 50, 50);
    LF = new LetterF(width() / 3 * 2 , 1, 30, 50);
}

void Area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 3));
    LO->draw(alpha, &painter);
    LC->draw(alpha, &painter);
    LF->draw(alpha, &painter);
}

void Area::showEvent(QShowEvent *event)
{
    myTimer = startTimer(50);
}

void Area::hideEvent(QHideEvent *event)
{
    killTimer(myTimer);
}

void Area::resizeEvent(QResizeEvent *event){
    LC->setX(width() / 3);
    LF->setX(width() / 3 * 2);
}

void Area::timerEvent(QTimerEvent *event){
    if (event->timerId() == myTimer){
        if (((LO->getH() * alpha) < 20 && speed < 0) ||
            ((LO->getH() * alpha) > this->height() && speed > 0) ||
            ((LO->getW() * alpha > (this->width() / 3)) && speed > 0)) speed *= -1;
        alpha += speed;
        update();
    }
    else QWidget::timerEvent(event);
}
Area::~Area() { }

