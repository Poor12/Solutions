#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
//汉诺塔问题

#define numofDisks 10
void move(int n, char x, char y) {
	cout << "move " << n << " from " << x << " to " << y << endl;
}
void Hannoi(int n, char a, char b, char c) {
	if (n == 1)
		move(1, a, c);
	else
	{
		Hannoi(n - 1, a, c, b);
		move(n, a, c);
		Hannoi(n - 1, b, a, c);
	}
}
int main()
{
	Hannoi(numofDisks, 'a', 'b', 'c');
	return 0;
}