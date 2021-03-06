//散列表 分离链接法
//等式系数是在区间[-50,50]范围内的整数，因此x1,x2,x3,x4,x5的可能值太大
//等价为a1x1^3+a2x2^3+a3x3^3=-(a4x4^3+a5x5^3)
//不妨使用散列存储左式的数和，通过检索数和为右式的元素个数来求解
//关键是如何计算数和num对应的散列值
//（1）将数和num转换成正整数（2）计算数和numm对应的散列值h
//h=(numm%maxn+numm%maxn)%maxn
#define mem(a) memset(a,0,sizeof(a))//数组变量清0
#define MAXN 2000007//散列值上限
#define maxn 1030302//散列表的链长
#define lf(a) a*a*a
int Hash[MAXN + 5], Next[maxn + 5], index, sum[maxn + 5];
void insert(int num) {
	int numm = num > 0 ? num : -num;
	int h = (numm%MAXN + numm % MAXN) % MAXN;
	sum[index] = num;
	Next[index] = Hash[h];//上一个index点的位置
	Hash[h] = index++;//最大的hash值为h的index值
}
int is_find(int num) {
	int number = 0;
	int numm = num > 0 ? num : -num;
	int h = (numm%MAXN + numm % MAXN) % MAXN;
	int u = Hash[h];
	while (u!=0)
	{
		if (sum[u] == num) ++number;
		u = Next[u];
	}
	return number;
}
int main() {
	int a[5];
	while (~scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4])) {
		mem(sum);
		mem(Hash);
		mem(Next);
		index = 1;
		int i, j, k, count = 0;
		for(int i=-50;i<=50;++i)
			if (i != 0) {
				for(j=-50;j<=50;++j)
					if (j != 0) {
						for(k=-50;k<=50;++k)
							if (k != 0) {
								insert(a[0] * lf(i) + a[1] * lf(j) + a[2] * lf(k));
							}
					}
			}
		for (int i = -50;i <= 50;++i) {
			if (i != 0) {
				for (int j = -50;j <= 50;++j) {
					if (j != 0) {
						count += is_find((-a[3])*lf(i) + (-a[4])*lf(j));
					}
				}
			}
		}
		printf("%d\n", count);
	}

	return 0;
}