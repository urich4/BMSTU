#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	double e, k = 1, s = 0, r1 = 1, r2 = 0;
	cout << "Введите погрешность:" << endl;
	cin >> e;
	while (fabs(s - 1) > e) {
		r1 = 1 / (k + 1) / k;
		s += r1;
		k += 1;
	}
	cout << k - 1 << " " << setprecision(20) << s;
	return 0;
}