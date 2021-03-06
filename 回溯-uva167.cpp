const int maxn = 8, maxm = 8;

int num[maxn][maxm];
int P[1000][9];
int tmp[8];
int n = 0;
bool col[8]={0},left[15]={0},right[15]={0}；//所有列和左右对角线未被选中
int isValid(int n) {	//判断第n个皇后放上去之后是否合法，即是否无冲突
	for (int i = 0;i < n;++i) {
		if (tmp[i] == tmp[n])
			return 0;
		if (abs(tmp[i] - tmp[n]) == (n - i))
			return 0;
	}
	return 1;
}
void func(int r)
{
	if (r == 8) {
		for (int i = 0;i < 8;++i)
			P[n][i] = tmp[i];
		++n;
		return;
	}
	//for (int c = 0;c < 8;++c) {
	//	tmp[r] = c;
	//	if (isValid(r))
	//		func(r + 1);
	//}
	for(int c=0;c<8;++c）{
		int ld=(c-r)+7;//左对角线序号
		int rd=c+r; //右对角线序号
		if(!col[c]&&!left[ld]&&!right[rd]){
			col[c]=1;
			left[ld]=1;right[rd]=1;
			tmp[r]=c;
			func(r+1);
			col[c]=0;left[ld]=0;right[rd]=0;
		}
	}
}
int main() {
	func(0);
	int Case;
	scanf("%d", &Case);
	while (Case--)
	{
		for (int i = 0;i < 8;++i) {
			for (int j = 0;j < 8;++j) {
				scanf("%d", &num[i][j]);
				
			}
		}
		int ans = 0;
		for (int i = 0;i < n;++i) {
			int sum = 0;
			for (int j = 0;j < 8;++j)
				sum += num[j][P[i][j]];
			if (sum > ans) ans = sum;
		}
		printf("%d\n", ans);
	}
	return 0;
}




