#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int main() {
	freopen("D:\\data.txt", "r", stdin);
	scanf("%d", &n);
	int *a=new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != i) {//如果元素没有放对位置
			while (a[i] != i) {//直到找到该位置对应元素
				swap(a[i], a[a[i]]);
				num += 1;
			}
			if (i != 0) num += 2;//第0位有0参与，其他位均多两次交换
		}
	}
	cout << num << endl;
}