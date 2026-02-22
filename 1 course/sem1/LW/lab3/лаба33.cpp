#include <iostream>
using namespace std;

int main() {
	long n, k = 1;
	cin >> n;
	do {
		k *= n % 10;
		n /= 10;
	} while (n > 0);
	cout << k;
	return 0;
}