#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;
typedef long long LL;
const int coeff[3] = { 2,3,5 };
//丑数是指不能被2，3，5以外的其他素数整除的数
int main()
{
	//freopen("D:\\data.txt", "r", stdin);
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	set<LL> s;
	pq.push(1);
	s.insert(1);
	for (int i = 1;;++i)
	{
		LL x = pq.top();
		pq.pop();
		if (i == 1500)
		{
			cout << "the 1500' th ugly number is " << x << ".\n";
			break;
		}
		for (int j = 0;j < 3;++j)
		{
			LL x2 = x * coeff[j];
			if (!s.count(x2))
			{
				s.insert(x2);
				pq.push(x2);
			}
		}
	}
	return 0;
}