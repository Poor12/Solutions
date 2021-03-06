//优先队列问题,结构体的优先队列，heap存索引
const int maxn = 60000 + 10;
const int maxs = 100;
struct info {
	char name[maxs];
	int para;//参数
	int pri;//优先级
	int t;//顺序
}p[maxn];
int heap[maxn];//堆
int top, used;//堆长，缓冲区指针
int compare(int a, int b) {
	if (p[a].pri < p[b].pri)
		return -1;
	if (p[a].pri > p[b].pri)
		return 1;
	if (p[a].t < p[b].t)
		return -1;
	if (p[a].t > p[b].t)
		return 1;
	return 0;
}
int main() {
	used = 0;
	top = 0;
	int cnt = 0;
	char s[maxs];
	while (scanf("%s",s)!=EOF)
	{
		if (!strcmp(s, "GET"))//相等0 a>b1 a<b-1
		{
			if (top) {
				printf("%s %d\n", p[heap[1]].name, p[heap[1]].para);
				int k = 1;//堆尾节点调至堆首，堆长-1
				heap[k] = heap[top--];
				while (k * 2 <= top) {
					int t = k * 2;
					if (t < top&&compare(heap[t + 1], heap[t]) < 0)
						++t;
					if (compare(heap[t], heap[k]) < 0) {
						swap(heap[t], heap[k]);
						k = t;
					}
					else
						break;
				}
			}
			else
				printf("empty queue\n");
		}
		else {
			scanf("%s%d%d", p[used].name, &p[used].para, &p[used].pri);
			p[used].t = cnt++;
			int k = ++top;
			heap[k] = used++;
			while (k > 1) {
				int t = k / 2;
				if (compare(heap[t], heap[k]) > 0) {
					swap(heap[t], heap[k]);
					k = t;
				}
				else
					break;
			}
		}
	}
}
	for (int i = n / 2; i >= 1; i--) {
		int k = i;
		int j = 2 * i;
		while (j <= n) {
			if (j < n && A[j - 1] > A[j]) {
				j++;
			}
			if (A[k - 1] > A[j - 1]) {
				swap(A[k - 1], A[j - 1]);
				k = j;
				j = 2 * k;
			}
			else {
				break;
			}
		}
	}
}