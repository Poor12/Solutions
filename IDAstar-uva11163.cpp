#include <algorithm>
#include <string>
int g[45][45];//位置i与位置j间的最短路长为g[i][j]
int dx[4][4] = { {-3,-1,+4,+4},{+1,+3,+4,+4},{+1,-1,+4,-4},{+1,-1,+4,-4} };//豹王在k位置跳跃的第j个位置为k+dx[k%4][j]
int a[45], n;//最终队形中位置i的美洲豹排序后为位置a[i]，美洲豹数量为n
int mxdep, solved;//阈值mxdep，排序完成后豹王目前跳跃的最小步数
void build() {//floyd计算可达位置间的最短路长矩阵g
	int i, j, k;
	for (i = 1;i <= 40;++i) {//初始化
		for (j = 1;j <= 40;++j)
			g[i][j] = 0xfffffff;
		g[i][i] = 0;
	}
	for (int i = 1;i <= 40;++i)//顺序枚举每个位置i，跳转方式为i%4
	{
		for (int j = 0;j < 4;++j)//依次计算4个跳转位置
			if (i + dx[i % 4][j] > 0 && i + dx[i % 4][j] <= 40)//当前跳转方式的第j个跳后位置在界内，则位置i与位置i + dx[i % 4][j]的步数设为1
				g[i][i + dx[i % 4][j]] = 1;
	}
	for (k = 1;k <= 40;++k)//floyd
		for (i = 1;i <= 40;++i)
			for (j = 1;j <= 40;++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
int h() {//累计n-1个非豹王归位的最少步数
	int i, sum = 0;//跳跃总步数初始化
	for (i = 1;i <= n;++i) {//枚举最终队列中每个非豹王位置i，累计其归位到a[i]位置的步数
		if (a[i] == 1) continue;
		sum += g[i][a[i]];
	}
	return sum;
}
int singleh(int pos) {//返回位置pos的美洲豹归位的最少步数（跳至位置a[pos]）
	return g[pos][a[pos]];
}
//F[v]=G[v]+H[v]  F[v]为豹王经由位置v排序队形的步数估计值 G[v]为豹王由最终队形跳跃至位置v的步数 H[v]为豹王从位置v跳下去至队形排序成功的步数
int ida(int x, int prev, int dep, int hv) {//豹王位置x，跳前位置prev，豹王的跳跃次数dep，其余美洲豹跳至目标位置的剩余步数hv。从该状态出发，计算豹王跳跃的最少步数
	if (hv == 0)//若排序完成，返回豹王跳跃的最少步数
	{
		solved = dep;
		return dep;
	}
	if (dep + hv > mxdep)//若排序完成需豹王跳的最少步数超过阈值，则返回
		return dep + hv;
	int i, tx;
	int submxdep = 0xfffffff, shv, tmp;//目前豹王最少的跳跃次数初始化为∞
	for (int i = 0;i < 4;++i)//枚举豹王的4个跳转位置
	{
		tx = x + dx[x % 4][i];//计算豹王的第i个跳转位置tx
		if (tx == prev || tx <= 0 || tx > n)//若越界或跳回x的前驱位置，则枚举下一个位置
			continue;
		shv = hv;//计算剩余美洲豹归位需跳跃的步数（hv+g[x][a[tx]]-g[tx][a[tx]]）
		shv -= singleh(tx);
		swap(a[x], a[tx]);
		shv += singleh(x);
		tmp = ida(tx, x, dep + 1, shv);//豹王从tx继续跳下去，计算最少跳跃次数
		if (solved)//排序成功返回
			return solved;
		swap(a[x], a[tx]);//恢复递归前x的位置和tx位置的美洲豹
		submxdep = min(submxdep, tmp);//调整目前豹王最少的跳跃次数
	}
	return submxdep;//返回目前豹王最少的跳跃次数
}
int main() {
	int i, j, k, x;
	int cases = 0;
	build();
	while (scanf("%d",&n)==1&&n)
	{
		for (i = 1;i <= n;++i)
			scanf("%d", &a[i]);//输入美洲豹的最终队形
		printf("set %d:\n", ++cases);//输出测试用例
		int inith = h();//累计n-1个非豹王归位的最少步数
		if (inith == 0)//若初始队形即为最终队形，豹王无须跳跃
			puts("0");
		else
		{
			solved = 0;//最少次数初始化为0
			mxdep = inith;//阈值初始化为n-1个非豹王归位的最少步数
			for (i = 1;i <= n;++i)//计算最终阵形的位置x
				if (a[i] == 1)
					x = i;
			while (solved==0)//反复深搜
			{
				mxdep = ida(x, -1, 0, inith);
			}
			printf("%d\n", solved);//输出排序完成时豹王跳跃的最少次数
		}
	}
	return 0;
}