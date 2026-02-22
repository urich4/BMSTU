// лаба5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    int n[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> n[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == j) cout << n[i][j] << ' ';
            else {
                if (j == 4) cout << n[i][8 - i] << " ";
                else {
                    cout << "   ";
                }
            }

        }
        cout << endl;
    }
    return 0;
}

