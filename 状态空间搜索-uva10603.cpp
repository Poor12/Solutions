#include <queue>
#define min(x,y) ((x<y)?(x):(y))
#define oo 0xfffffff
int aa, bb, cc, d, jug[3];//a,b,c为三个桶的容量，最终要使一个桶的的水量为d
int dp[201][201][201], res[201];//三个桶的水量为a，b，c时倒水总量的上限为dp[a][b][c];若最终有一个桶恰好有d升的水，则整个过程最少倒水res[d]
queue<int> qa, qb, qc, qtot;//存储三个桶的当前水量以及当前倒水总量
void pushnode(int a, int b, int c, int tot) {
	qa.push(a);
	qb.push(b);
	qc.push(c);
	qtot.push(tot);
}
void update(int a, int b, int c, int tot) {//模拟6种倒水情况，将其中满足条件的子状态送入队列
	if (tot >= res[d]) return;//若当前倒水总量不小于一个桶的水量为d时的倒水总量
	if (tot >= dp[a][b][c]) return;//若当前倒水总量不小于三个桶的水量为a，b，c时倒水总量的上限
	//定界
	dp[a][b][c] = tot;
	res[a] = min(res[a], tot);
	res[b] = min(res[b], tot);
	res[c] = min(res[c], tot);//不允许三个桶水量为a，b，c时的实际倒水量超过tot
	//如果桶1的水能够全部倒入桶2，则倒空桶1；否则桶1将桶2倒满；其他情况类似
	if (a < bb - b)
		pushnode(0, b + a, c, tot + a);
	else
		pushnode(a - (bb - b), bb, c, tot + bb - b);
	if (a < cc - c)
		pushnode(0, b , c+a, tot + a);
	else
		pushnode(a - (cc - c), b, cc, tot + cc - c);
	if (b < aa - a)
		pushnode(a+b, 0, c, tot + b);
	else
		pushnode(aa, b-(aa-a), c, tot + aa-a);
	if (b < cc - c)
		pushnode(a, 0, c+b, tot + b);
	else
		pushnode(a , b-(cc-c), cc, tot + cc-c);
	if (c < aa - a)
		pushnode(a+c, b , 0, tot + c);
	else
		pushnode(aa, b, c-(aa-a), tot + aa - a);
	if (c < bb - b)
		pushnode(a, b+c, 0, tot + c);
	else
		pushnode(a , bb, c-(bb-b), tot + bb - b);
}
void bfs(int a, int b, int c, int tot) {
	qa.push(a);
	qb.push(b);
	qc.push(c);
	qtot.push(tot);
	while (!qa.empty())
	{
		a = qa.front();qa.pop();
		b = qb.front();qb.pop();
		c = qc.front();qc.pop();
		tot = qtot.front();qtot.pop();
		update(a, b, c, tot);//模拟6种倒水情况
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int i, j, k;
		scanf("%d%d%d%d", &aa, &bb, &cc, &d);
		for (i = 0;i <= aa;++i)//初始化上限为∞
			for (j = 0;j <= bb;++j)
				for (k = 0;k <= cc;++k)
					dp[i][j][k] = oo;
		jug[0] = aa;jug[1] = bb;
		jug[2] = cc;//记下三个桶的容量
		for (i = 0;i <= d;++i) res[i] = oo;//倒水总量初始化
		bfs(0, 0, cc, 0);//从初始状态开始搜索
		while (res[d]==oo)
		{
			d--;
		}
		printf("%d%d\n", res[d], d);//输出至少要倒res[d]，才能使一个桶恰好有d升水
	}
}