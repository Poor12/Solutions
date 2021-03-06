//多源最长路径 回溯
//状态：求解过程中每一步的状况为目前路径的尾节点i,路长l和各条边的访问标志a[][]
//搜索范围0<=j<=n-1
//约束条件a[i][j]=1
//邻接矩阵 a[i][j]=0 when i与j无边或(i,j)已被访问 a[i][j]=1 when (i,j)未被访问
#define DBG(x)
int a[32][32];
FILE *input;
int m, n,best;
int read_case() {
	int i, j;
	fscanf(input, "%d %d", &n, &m);//n节点数，m边数
	if (m == 0 & n == 0) return 0;
	for (i = 0;i < n;++i)
		for (j = 0;j < n;++j)
			a[i][j] = 0;
	while (m--)
	{
		fscanf(input, "%d %d", &i, &j);
		a[i][j] = a[j][i] = 1;
	}
	return 1;
}
void visit(int i, int l) {//i目前行至节点，路长为l
	if (l > best) best = l;
	for (int j = 0;j < n;++j) {
		if (a[i][j] == 1)
		{
			a[i][j] =a[j][i]=0;
			l++;
			visit(j, l);
			a[i][j] = a[j][i] = 1;
		}
	}
}
void show_case() {
	int i;
	 best = 0;
	for (i = 0;i < n;++i)
		visit(i, 0);
	printf("%d", best);
}
int main() {
	input = fopen("catan.in", "r");
	while (read_case())
	{
		show_case();
	}
	fclose(input);
	return 0;
}
