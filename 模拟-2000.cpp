int main() {
	int n,ans=0;
	cin >> n;
	for (int i = 0, j = 1;i <= n;j++) {//i为天数，j为时间段
		int k = j;
		while (k--&&++i<=n)
		{
			ans += j;
		}
	}
	cout << ans;
	return 0;
}

