//线性表排序 交换次数即为逆序对个数
#include <string>
#include <algorithm>
const int maxn = 1100;
int n, a[maxn],ans,t[maxn];//序列长度为n,输入序列为a,逆序对数为ans,排序数组为t
void Sort(int l, int r) {//归并算法
	if (l == r)
		return;
	int mid = (l + r) / 2;
	Sort(l, mid);
	Sort(mid + 1, r);
	int i = 1, j = mid + 1, now = 0;//左右区间和合并区间指针初始化
	while (i <= mid && j <= r) {
		if (a[i] > a[j]) {
			ans += mid - i + 1;
			t[++now] = a[j++];
		}
		else
		{
			t[++now] = a[i++];
		}
	}
	while (i <= mid) t[++now] = a[i++];
	while (j <= r) t[++now] = a[j++];
	now = 0;
	for (int k = l;k <= r;++k) a[k] = t[++now];
}
int main() {
	cin >> n;
	while (n)
	{
		for (int i = 1;i <= n;++i)
			cin >> a[i];
		ans = 0;
		Sort(1, n);
		cout << ans << endl;
		cin >> n;
	}
	return 0;
}