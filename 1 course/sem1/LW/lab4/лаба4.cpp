#include <iostream>
using namespace std;

int main() {
	int n[40];
	int x = 0, maxi = 0, b = 0;
	for (int i = 0; i < 40; ++i) {
		cin >> n[i];
	} 

	cout << "Исходный массив:" << endl;
	for (int i : n) {
		cout << i << ' ';
		x = 0;
		for (int j : n) {
			if (i == j) x += 1;
			if (x > maxi) {
				maxi = x; b = i;
			}
		}
	}
	cout << endl << "Самое частое число: " << b << endl;
	cout <<  "Кол-во повторений: " << maxi;
	
	return 0;
}