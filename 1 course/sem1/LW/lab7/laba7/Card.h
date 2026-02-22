#ifndef CARD_H
#define CARD_H
#include <iostream>

using namespace std;

class BonusCard{
    private:
        int number;
        int procent;
        float balance;

    public:
        BonusCard(int n, int pr, float bal);
        void show();
        void buying(int summa);
        void cancellation(int summa);
};
#endif