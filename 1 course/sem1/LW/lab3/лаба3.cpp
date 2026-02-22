#include <iostream>
using namespace std;

int main() {
	long n, k=1;
	cin >> n;
	for (int i = 1; n > 0; ++i) {
		k *= n % 10;
		n /= 10;
	}
	cout << k;
	return 0;
}