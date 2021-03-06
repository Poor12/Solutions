//对于不需要由主程序传入初始值的参数，列为递归程序的局部变量。
//对于需要由主程序传入初始值的参数，按存储量分类：
//（1）存储量小的参数，列为递归子程序的值参。由编译系统自动实现递归与回溯的状态转换。
//（2）存储量大的参数，如数组，设为全局变量，避免系统堆栈溢出。但需要在递归语句后加入恢复到递归前状态的语句。
int sticks[65];//给出的n根木条长度
int used[65];//n根木条是否被切下的标志
int n, len;//木条数n，木棒长度len
bool dfs(int i, int l, int t)//序号i，当前木棒的剩余长度l，剩余木棒的长度和t
{
	if (l == 0) {//从一根木棒上完整切下木条
		t -= len;
		if (t == 0) return true;
		for (i = 0;used[i];++i);
		used[i] = 1;//切下木条i
		if (dfs(i + 1, len - sticks[i], t)) return true;//若能切下剩余的木条，则成功返回
		used[i] = 0;t += len;//恢复递归前的状态
	}
	else
	{
		for (int j = i;j < n;++j) {//按长度递减顺序枚举木条
			if (j > 0 && (sticks[j] == sticks[j - 1] && !used[j - 1])) continue;
			if (!used[j] && l >= sticks[j])//若木条未切下且长度小于l时，则切下木条
			{
				l -= sticks[j];used[j] = 1;
				if (dfs(j, l, t)) return true;
				l += sticks[j];used[j] = 0;
				//if (sticks[j] == 1) break;若木棒最后切出木条j后，余下木条无法完成切割木条的任务 贪心
			}
		}
	}
	return false;
}
bool cmp(const int a, const int b) {
	return a > b;
}
//将木条递减排序，假设木条的最小可能长度为len。所以len是sum的一个因子，如果至少有两根木棒，则sticks[0]<=len<=sum/2。如果这个区间未能找到，那么木棒只有一根，len=sum。
int main() {
	while (cin>>n&&n)
	{
		int sum = 0;
		for (int i = 0;i < n;++i)
		{
			cin >> sticks[i];sum += sticks[i];
			used[i] = 0;
		}
		sort(sticks, sticks + n, cmp);
		bool flag = false;
		for (len = sticks[0];len <= sum / 2;len++) {
			if (sum%len == 0) {
				if (dfs(0, len, sum))//怎样判断len是否为原来木棒的长度
				{
					flag = true;
					cout << len << endl;
					break;
				}
			}
		}
		if (!flag) cout << sum << endl;
	}
	return 0;
}
