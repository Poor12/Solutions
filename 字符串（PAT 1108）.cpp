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

int main() {
	freopen("D:\\data.txt", "r", stdin);
	char a[50], b[50];
	int n;
	cin >> n;
	bool flag;
	double temp, average = 0.0;
	int cnt = 0;
	for (int i = 0;i < n;++i)
	{
		flag = 1;
		scanf("%s", a);
		sscanf(a, "%lf", &temp);
		sprintf(b, "%.2lf", temp);
		cout << a << endl << temp << endl<<b<<endl;
		for (int j = 0;j < strlen(a);++j)
		{
			if (a[j] != b[j])
				flag = 0;
		}
		if (flag&&temp >= -1000 && temp <= 1000)
		{
			average += temp;
			cnt++;
		}
		else
		{
			printf("ERROR: %s is not a legal number\n", a);
		}
	}
	if (cnt == 0)
		printf("The average of 0 number is Undefined");
	else
		average /= cnt;
	if (cnt == 1)
		printf("The average of %d number is %.2lf", cnt, average);
	if (cnt > 1)
		printf("The average of %d numbers is %.2lf", cnt, average);

	return 0;
	
}