//尼姆博弈的输赢规律(miserenim)
//（1）所有物品堆的数目都为1：显然有偶尔堆物品堆，先手必胜，否则必败
//（2）如果恰好只有一堆物品数目大于1.我们可以把这堆物品取完或者取得只剩下1，使得奇数堆数目为1的物品留给对方，必胜
//（3）如果至少两堆物品的数目大于1.考虑异或值，若异或值不为0，则按照nim走法取石必胜
int main() {
	int t, i, a, n;
	cin >> t;
	while (t--&&cin >> n) {
		int flag = 0,s = 0,j = 0;//组内石子数大于1的标志flag，异或结果s，空组数j
		for (int i = 0;i < n;++i) {
			cin >> a;
			s ^= a;
			if (a > 1) flag = 1;
			if (a == 0) j++;
		}
		
		if (flag == 0) {
			if ((n - j) % 2 == 0)
			{
				cout << "1\n";
			}
			else
				cout << "2\n";
		}		
		
		else if (s == 0)
			cout << "2\n";
		else
			cout << "1\n";
	}
}