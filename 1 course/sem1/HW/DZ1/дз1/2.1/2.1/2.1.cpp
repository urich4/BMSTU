#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double x, y, w, max, a1, a2, a3;
	cout << "Введите x, y, w:" << endl;
	cin >> x >> y >> w;
	a1 = x + y + 2;
	a2 = x + 0.5;
	a3 = y + x * w;
	if (a1 >= a2 && a1 >= a3) {
		max = a1;
	}
	else{
		if (a2 >= a1 && a2 >= a3) max = a2;
		else max = a3;
	}
	
	cout << max * max + 1;
	return 0;
}