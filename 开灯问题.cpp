#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <iterator>
#include <queue>
using namespace std;
#define maxn 1010
int a[maxn];//比较大的数组应尽量声明在main函数外，否则程序可能无法运行
//如果要从数组a复制k个元素到数组b，memcpy(b,a,sizeof(int)*k),memcpy(b,a,sizeof(a))
//开灯问题，有n盏灯，编号为1-n，第1个人把所有灯打开，第2个人按下所有编号为2的倍数的开关，依次类推，一共k个人
int main()
{
	int n, k, first = 1;
	memset(a, 0, sizeof(a));
	scanf("%d%d", &n, &k);
	for(int i=1;i<=k;++i)
		for (int j = 1;j <= n;++j)
		{
			if (j%i == 0)
				a[j] = !a[j];
		}
	for(int i=1;i<=n;++i)
		if (a[i])
		{
			if (first)
				first = 0;
			else
				printf(" ");
			printf("%d", i);
		}
	printf("\n");
	return 0;
}
