#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
int count_bit(int x)
{
	int count = 0;
	while (x )
	{
		x /= 10;
		count++;
	}
	return count;
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n, z, i;
	cin >> n;
	for (i = 0;i < n;++i)
	{
		cin >> z;
		int mid = count_bit(z) / 2;
		int t = pow(10, mid);
		if (z%t > 0 && z % ((z%t)*(z / t)) == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
