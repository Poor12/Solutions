int main() {
	int min, max;
	cin >> min>>max;
	int ans = 0,j,m;
	for (int i = min;i <= max;++i) {
		for (j = 1, m = i;m > 1;++j) {
			if (m % 2 == 0)
				m /= 2;
			else
			{
				m = 3 * m + 1;
			}
		}
		if (j > ans)
			ans = j;
	}
	cout << ans;
	return 0;
}