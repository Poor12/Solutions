//约瑟夫环
//任意指定起点元素，规定报数方向，限定出列元素数，变换步长值，或者两个方向同时报数
#define maxn 10000
int main() {
	int n;
	cin >> n;
	string name[maxn];
	for (int i = 0;i < n;++i)
		cin >> name[i];
	int p[maxn];//记下每个位置的小孩序号
	for (int i = 0;i < n;++i)
		p[i] = i;
	int w, s;
	char c;
	cin >> w >> s;
	w = (w - 1 + n) % n;
	do {
		w = (w + s - 1) % n;
		cout << name[p[w]] << endl;
		for (int i = w;i < n - 1;++i)
			p[i] = p[i + 1];
	} while (--n);
	return 0;
}