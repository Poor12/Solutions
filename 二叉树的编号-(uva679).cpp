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
using namespace std;
const int maxd = 20;
int s[1 << maxd];
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int D, I;
	while (scanf("%d%d", &D, &I) == 2)
	{
		memset(s, 0, sizeof(s));
		int k, n = (1 << D) - 1;//n是最大节点编号
		for (int i = 0;i < I;++i)
		{
			k = 1;
			for (;;)
			{
				s[k] = !s[k];
				k = s[k] ? k * 2 : k * 2 + 1;//根据开关情况选择下落方向
				if (k > n) break;//已经落出界了
			}
		}
		printf("%d\n", k / 2);
	}
	/*
	while(scanf("%d%d",&D,&I)==2)
	{
		int k=1;
		for(int i=0;i<D-1;++i)
		{
			if(I%2)
			{
				k=k*2;
				I=(I+1)/2;
			}
			else
			{
				k=k*2+1;
				I/=2;
			}
		}
		printf("%d\n",k);
	}
	
	*/
	return 0;
}
