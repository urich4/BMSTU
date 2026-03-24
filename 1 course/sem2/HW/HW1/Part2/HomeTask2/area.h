#ifndef AREA_H
#define AREA_H

#include <QWidget>
#include <QTimer>
#include <QTimerEvent>
#include "figura.h"

class Area: public QWidget
{
    int myTimer;
    float alpha;
    float speed;

public:
    Area(QWidget *parent = nullptr);
    ~Area();
    LetterO *LO;
    LetterC *LC;
    LetterF *LF;
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
    void resizeEvent(QResizeEvent *event);
};

#endif // AREA_H
