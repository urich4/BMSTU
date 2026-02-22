#include <iostream>
using namespace std;

int main()
{
    int n, min1 = 0;
    float temp;
    cout << "Введите n" << endl;
    cin >> n;
    float r[n];
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < n ; i++){
        min1 = i;
        for (int j = i ; j < n; j++){
            if (r[j] < r[min1]){
                min1 = j;
                }
        }
        temp = r[i];
        r[i] = r[min1];
        r[min1] = temp;
    }
    for (float num : r) cout << num << " ";
    return 0;
}

