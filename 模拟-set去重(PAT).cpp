#include <iostream> 
#include <set>
using namespace std;
set<int> num[55];
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n, m, x, k, n1, n2;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> m;
		for (int j = 0;j < m;j++) {
			cin >> x;
			num[i].insert(x);     //将元素x加入集合num[i]中
		}
	}
	cin >> k;                       //k个查询
	for (int i = 0;i < k;i++) {
		cin >> n1 >> n2;              //比较集合num[n1]和num[n2]
		int same = 0, sum = num[n2].size();   //same为相同元素个数,sum为不同元素个数
		for (set<int>::iterator it = num[n1].begin();it != num[n1].end();it++) { //遍历集合num[n1]
			if (num[n2].find(*it) != num[n2].end()) same++;   //若能在num[n2]中找到该元素
			else sum++;   //若在num[n2]中找不到该元素
		}
		printf("%.1f%%\n", same*100.0 / sum);
	}
	return 0;
}
