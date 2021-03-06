//数组-多项式
//（1）数值数组。a[指数值]=底数值
//（2）结构数组。a的下标是项序数，a[i].coef系数，a[i].exp指数

const int n = 9;
inline int fabs(int k)
{
	return k < 0 ? -k : k;
}
int main() {
	int a[n];
	while (cin>>a[0])
	{
		for (int i = 1;i < n;++i)
			cin >> a[i];
		bool first = true;
		for (int i = 0;i < n;++i) {
			if (a[i] != 0) {
				if (first) {
					if (a[i] == -1 && i < n - 1)
						cout << '-';
					else if (a[i] != 1 || i == n - 1)
						cout << a[i];
					if (i == n - 2)
						cout << 'x';
					else if (i < n - 1)
						cout << "x^" << n - i - 1;
					first = false;
				}
				else
				{
					cout << ' ' << (a[i] < 0 ? '-' : '+');
					if (fabs(a[i]) != 1 || i == n - 1)
						cout << fabs(a[i]);
					if (i == n - 2)
						cout << "x";
					else if (i < n - 1)
						cout << "x^" << n - i - 1;
				}
			}
		}
		if (first)
			cout << 0;
		cout << endl;
	}
	return 0;
}
