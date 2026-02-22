#include "Card.h"
#include <iostream>

using namespace std;


BonusCard::BonusCard(int n, int pr, float bal){
    number = n;
    procent = pr;
    balance = bal;
}

void BonusCard::show(){
    cout << "Номер карты: " << number << endl;
    cout << "Процент начисления бонусов за покупку: " << procent << "%" << endl;
    cout << "Текущий баланс: " << balance << endl;
    cout << "------------------------" << endl;
}

void BonusCard::buying(int summa){
    balance += summa * ((float)procent / 100.);
}

void BonusCard:: cancellation(int summa){
    balance -= summa;
}


