#include "figura.h"

Figura::Figura(int X, int Y, int H, int W): x(X), y(Y), h(H), w(W) {}

float Figura::getH(){
    return h;
}

float Figura::getW(){
    return w;
}

void Figura::setX(float f){
    x = f;
}

LetterO::LetterO(int X, int Y, int H, int W): Figura(X, Y, H, W){}

void LetterO::draw(float alpha, QPainter *Painter){
    Painter->drawEllipse(x, y, h * alpha, w * alpha);
}

LetterC::LetterC(int X, int Y, int H, int W): Figura(X, Y, H, W){}

void LetterC::draw(float alpha, QPainter *Painter)
{
    QRectF rectangle(x, y, h*alpha, w*alpha);
    int startAngle = 50 * 16;
    int spanAngle = 260 * 16;

    Painter->drawArc(rectangle, startAngle, spanAngle);
}

LetterF::LetterF(int X, int Y, int H, int W): Figura(X, Y, H, W){}

void LetterF::draw(float alpha, QPainter *Painter)
{
    Painter->drawEllipse(x, y, w * alpha, h * alpha);
    Painter->drawLine((w / 2 ) * alpha + x, 0, (w / 2 ) * alpha + x, w * alpha);
}
