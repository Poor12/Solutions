//线性表排序 冒泡排序
void Sort(int l, int r) {//归并算法 0到n，两边都取的到
	if (l == r)
		return;
	int mid = (l + r) / 2;
	Sort(l, mid);
	Sort(mid + 1, r);
	int i = 0, j = mid + 1, now = 0;//左右区间和合并区间指针初始化
	while (i <= mid && j <= r) {
		if (a[i] > a[j]) {
			ans += mid - i + 1;
			t[now++] = a[j++];
		}
		else
		{
			t[now++] = a[i++];
		}
	}
	while (i <= mid) t[now++] = a[i++];
	while (j <= r) t[now++] = a[j++];
	now = 0;
	for (int k = l;k <= r;++k) a[k] = t[now++];
}