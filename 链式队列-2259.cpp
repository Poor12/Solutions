//在数据元素变化较大且不存在队列满而溢出的情况时使用链式存储
const int maxp = 1000000;
const int maxt = 1000;
const int maxn = 200000;
struct node {
	int p;//下标
	int pre, next;
}r[maxn];
int pos[maxt];//团队最后一个元素的位置
int belong[maxp];//元素属于哪个团队
int used;//队列新节点的下标
int st, ed;//队首，队尾
int main() {
	int t,loop=0;
	cin >> t;
	while (t)
	{
		for (int i = 0;i < t;++i) {
			int m;
			cin >> m;
			for (int j = 0;j < m;++j) {
				int x;
				cin >> x;
				belong[x] = i;
			}
			pos[i] = -1;
		}
		used = 0;//队列下标
		st = ed = -1;//队空
		if (loop)
			cout << endl;
		cout << "Scenario #" << ++loop << endl;
		string s;
		cin >> s;
		while (s!="Stop")
		{
			if (s == "enqueue") {
				int x;
				cin >> x;
				r[used].p = x;
				int s = pos[belong[x]];
				if (s < 0) {//队列中没有这个团队，插在队尾
					r[used].pre = ed;
					r[used].next = -1;
					if (ed >= 0)
						r[ed].next = used;
					ed = used;
					if (st < 0)
						st = used;
				}
				else
				{
					r[used].pre = s;
					r[used].next = r[s].next;
					if (s == ed) {
						ed = used;
					}
					r[s].next = used;
					if(r[used].next>=0)
						r[r[s].next].pre = used;
				}
				pos[belong[x]] = used++;
			}
			else
			{
				cout << r[st].p << endl;//输出队首指针
				if (st == pos[belong[r[st].p]])
					pos[belong[r[st].p]] = -1;
				st = r[st].next;
			}
			cin >> s;
		}
		cin >> t;
	}
	return 0;
}
