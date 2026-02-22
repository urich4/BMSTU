#include <iostream>
using namespace std;

int main() {
	long n, k = 1;
	cin >> n;
	while (n > 0) {
		k *= n % 10;
		n /= 10;
	}
	cout << k;
	return 0;
}