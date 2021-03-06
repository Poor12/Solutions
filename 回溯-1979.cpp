/*回溯
一般流程:
void run(当前状态):
{
	if(当前状态为边界)
	{
		if(当前状态为最佳目标状态)
			记下最优结果;
		return;
	}
	for(int i=算符最小值;i<=算符最大值;++i)
	{
		算符作用于当前状态，扩展出一个子状态;
		if(子状态满足约束条件)&&(子状态满足最优性要求)
			run(子状态);
	}
}
		
*/
const int maxn = 25, maxm = 25;
int m, n, ans;
string map[maxn];
bool visited[maxn][maxm];
void search(int row, int col) {
	if (row < 0 || row >= n || col < 0 || col >= m || map[row][col] == '#' || visited[row][col]) return;
	ans++;
	visited[row][col] = 1;
	search(row - 1, col);
	search(row + 1, col);
	search(row, col + 1);
	search(row, col - 1);
}
int main() {
	cin >> m >> n;
	while (n || m) {
		int row, col;
		for (int i = 0;i < n;++i) {
			cin >> map[i];
			for (int j = 0;j < m;++j)
				if (map[i][j] == '@') {
					row = i;col = j;
				}
		}
		memset(visited, false, sizeof(visited));
		ans = 0;
		cout << ans << endl;
		cin >> m >> n;
	}
	return 0;
}


