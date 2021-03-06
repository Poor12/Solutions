//链与数组的选择
//记录一个n*n的矩阵，非零元素为m个，则随机访问矩阵中任意元素，数组O(1),链表O(m),所有数据遍历，数组O(n^2),链表O(m)
//约瑟夫环的数组表示,已知长度和最后剩下节点的序号，求步长
/*初解
#include <string>
int nextt[150];//后继节点
bool cut[150];//出列节点
int main() {
	int n, m, i;//元素数n，报数间隔m
	while (~scanf("%d", &n) && n) {
		for (i = 1;i <= n - 1;i++)
			nextt[i] = i + 1;
		nextt[n] = 1;
		m = 1;//步长初始化
		bool find = false;//标记是否找到符合条件的m
		while (!find) {
			m++;
			memset(cut, 1, sizeof(cut));
			int from = 1;cut[1] = 0;
			int num = n - 1;//计算剩余元素数
			int nextcut, jump;
			while (num > 1) {
				nextcut = from;
				jump = 0;
				while (jump < m) {
					nextcut = nextt[nextcut];
					if (cut[nextcut]) jump++;
				}
				cut[nextcut] = false;
				from = nextcut;
				num--;
				if (from == 2 && num != 1) break;
			}
			if (num == 1 && cut[2]) find = true;
		}
		printf("%d\n", m);
	}
	return 0;
}
*/
/*
	n个人，从0开始报数，报到m-1的出列，剩下的n-1人继续从0开始报数，求出列者的编号
	第一个人出列后（m%n-1）剩下的人组成约瑟夫环：k,k+1,k+1...n-2,n-1,0,1,2..k-2  (k=m%n)
	编号转换就变成n-1个人的报数子问题，k->0,k+1->1...k-1->n-1
	假设我们已知x是最终的解，根据上表将x变回，x'=(x+k)%n;
	n个人报数的问题解是一个递推式，设f[i]表示i个人玩游戏报m退出最后出列者的编号：
	f[1]=0;
	f[i]=(f[i-1]+m)%i;
*/
int main() {
	int n;
	while (cin >> n && n != 0) {
		int i;
		int ans;
		for (i = 2;i <= 32767;++i) {
			ans = 0;
			int j;
			for (j = 2;j < n;++j) {
				ans = (ans + i) % j;
			}
			if (ans == 0) {//注意这个条件的理解
				cout << i << endl;break;
			}
		}
	}
}