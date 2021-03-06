//本题描述：（1)找出所有满足长度要求的子串，并统计各子串出现的频率（2）把所有子串按要求排序输出
//解法（1）二叉树（2）矩阵结构
//一般可以用二维数组表示矩阵结构，它有x、y两个方向，常用表示方法为x表示数据元素，y表示元素的各种状态条件。数组的元素值表示数据元素在当前状态条件下的变化情况，用数值表示
//因此a[x,y]存储数值为x（01串对应的十进制数），长度为y（01串的长度）的01串频率
#include <math.h>
#include <algorithm>
#include <string>
#include <cstdio>
const int max = 11000;
const int inf = 1000000000;
int cnt[13][1 << 12];//x为长度，y为值
char s[2200000];//01串
struct pp {//子串表的节点类型
	int len, v, cnt;//长度、值、频率
}p[13*(1<<12)];//子串表
bool cmp(pp a, pp b) {//按照关键字排序
	if (a.cnt != b.cnt)
		return a.cnt > b.cnt;
	else if (a.len != b.len)
		return a.len > b.len;
	return a.v > b.v;
}
void out(int len, int v) {//输出长度为len，值为v的二进制数
	int bit[13] = { 0 }, i;
	for (i = 0;i < len&&v;i++) {//v转化为长为len的整数数组
		bit[i] = v & 1;
		v >> 1;
	}
	putchar(' ');
	for (i = len - 1;i >= 0;i--) {//输出bit
		putchar('0' + bit[i]);
	}
}
int main() {
	int i, A, B, n;
	int j;
	while (~scanf("%d",&A))
	{
		scanf("%d%d", &B, &n);
		getchar();
		gets_s(s);
		int len = strlen(s) - 1;
		for (i = A;i <= B;++i) {//频率数组清零
			for (j = 0;j < (1 << i);j++) {
				cnt[i][j] = 0;
			}
		}
		int tmp = 0;
		for (i = A;i <= B && i <= len;++i) {
			tmp = 0;//由右向左取出s中长度为i的值tmp，计算频率
			for (j = 0;j < i;++j) {
				tmp = (tmp << 1) | s[j] - '0';
			}
			cnt[i][tmp]++;
			for (;j < len;++j) {
				tmp = (tmp << 1) | (s[j] - '0');
				tmp &= ((1 << i) - 1);
				cnt[i][tmp]++;
			}
		}
		int m = 0;//p的长度初始化
		for (i = A;i <= B;++i) {//枚举范围内的每个长度
			for (j = 0;j < (1 << i);j++) {//枚举长度i的所有可能值
				if (cnt[i][j] > 0) {//若存在
					p[m].cnt = cnt[i][j];
					p[m].v = j;
					p[m].len = i;
					m++;
				}
			}
		}
		sort(p, p + m, cmp);
		for (i = 0;i < m&&n>0;++i, n--) {
			for (j = i;j < m&&p[j].cnt == p[i].cnt;++j);//p[i]p[j]的频率一样大
			printf("%d", p[i].cnt);//输出第i大的频率
			for (;i < j;++i) {
				out(p[i].len, p[i].v);
			}
			puts("");
			i--;
		}
	}
}