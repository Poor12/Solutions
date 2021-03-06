//分型图
char map[731][731];
void dfs(int n, int x, int y) {
	int size;
	if (n == 1) {
		map[x][y] = 'X';
		return;
	}
	size = pow(3, n - 2);
	dfs(n - 1, x, y);
	dfs(n - 1, x, y + 2*size);
	dfs(n - 1, x + size, y+size);
	dfs(n - 1, x + 2 * size, y);
	dfs(n - 1, x + 2 * size, y + 2 * size);
}
int main() {
	int i, j, n, size;
	while (~scanf("%d",&n))
	{
		if (n == -1)
			break;
		size = pow(3, n - 1);
		for (i = 0;i < size;++i) {
			for (j = 0;j < size;++j)
				map[i][j] = ' ';
		}
		dfs(n, 0, 0);
		for (i = 0;i < size;++i) {
			for (j = 0;j < size;++j)
				printf("%c", map[i][j]);
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}