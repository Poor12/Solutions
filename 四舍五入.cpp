#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
using namespace std;


int main()
{
	//freopen("D:\\data.txt", "r", stdin);

	int f, s;
	scanf("%d%d", &f, &s);
	int t = int((s - f) / 100.0 + 0.5);//四舍五入
	printf("%02d:%02d:%02d\n", t / 3600, t % 3600 / 60, t % 60);
	return 0;
	return 0;
}
