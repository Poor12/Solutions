//数组-高精度运算
const int maxlen = 500;
const int maxs = 5;//底数串s的容量
class bigNum {
private:
	int a[maxlen];
	int len;
public:
	bigNum() {
		memset(a, 0, sizeof(a));
		len = 1;
	}
	int length() {
		return len;
	}
	int at(int k) {
		if (0 <= k && k < len) return a[k];
		return -1;
	}
	void setnum(const char s[]) {
		len = 0;
		for (int i = strlen(s) - 1;i >= 0;--i)
			a[len++] = int(s[i] - '0');
	}
	bool isZero() {
		return len == 1 && a[0] == 0;
	}
	void add(bigNum &x) {
		for (int i = 0;i < x.len;++i) {
			a[i] += x.a[i];
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		int k = x.len;
		while (a[k])
		{
			a[k + 1] += a[k] / 10;
			a[k++] %= 10;
		}
		len = len > k ? len : k;
	}
	void multi(bigNum &x) {
		if (x.isZero())
			setnum("0");
		int product[maxlen];
		memset(product, 0, sizeof(product));
		for (int i = 0;i < len;++i)
			for (int j = 0;j < x.length();++j)
				product[i + j] += a[i] * x.at(j);
		int k = 0;
		while (k<len+x.length()-1)
		{
			product[k + 1] += product[k] / 10;
			product[k++] %= 10;
		}
		while (product[k])
		{
			product[k + 1] += product[k] / 10;
			product[k++] %= 10;
		}
		len = k;
		memcpy(a, product, sizeof(product));
		
	}
};
int main() {
	int n;
	char s[maxs];
	while (~scanf("%d%s",&n,s))
	{
		bigNum a, ap;
		a.setnum(s);
		ap.setnum("1");
		bigNum sum;
		for (int i = 1;i <= n;++i) {
			bigNum num;
			sprintf(s, "%d", i);
			num.setnum(s);
			ap.multi(a);
			num.multi(ap);
			sum.add(num);
		}
		for (int i = sum.length() - 1;i >= 0;--i)
			printf("%d", sum.at(i));
		putchar('\n');
	}
	return 0;
}
