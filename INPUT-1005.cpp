#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define M_PI 3.1415926
/*
POJ1005-INPUT
*/

int main() {
	int n, z;
	double x, y,calc;
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> x >> y;
		calc = (x*x + y * y)*M_PI / 2 / 50;
		z = ceil(calc);
		printf("Property %d: This property will begin eroding in year %d\n", i, z);
	}
	printf("END 0F OUTPUT.");
	return 0;
}