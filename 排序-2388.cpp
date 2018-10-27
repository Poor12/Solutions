//线性表排序 使用sort函数，sort排序的对象是可以随机访问的元素，不能是依次访问的元素，如队列、链表
#include <string>
#include <algorithm>
const int maxn = 11000;
int a[maxn], n;
int main() {
	cin >> n;
	for (int i = 1;i <= n;++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << a[(n + 1) / 2] << endl;
	return 0;
}