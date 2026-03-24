#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>
#include <QRectF>

class Figura
{
protected:
    int x, y, h, w;
    virtual void draw(float alpha, QPainter*Painter)=0;

public:
    Figura(int X, int Y, int H, int W);
    float getH();
    float getW();
    void setX(float f);
    ~Figura();
};

class LetterO: public Figura{
public:
    void draw(float alpha, QPainter *Painter) override;
    LetterO(int X, int Y, int H, int W);

};

class LetterC: public Figura{
public:
    void draw(float alpha, QPainter *Painter) override;
    LetterC(int X, int Y, int H, int W);

};

class LetterF: public Figura{
public:
    void draw(float alpha, QPainter *Painter) override;
    LetterF(int X, int Y, int H, int W);

};






#endif // FIGURA_H
