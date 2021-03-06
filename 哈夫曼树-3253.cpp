//哈夫曼树 在具有n个带权叶节点的二叉树中，第k个叶节点的权值为wk,其至根的路径长度为pk，则wk*pk为第k个叶节点的带权路径长度，使所有叶节点的带权路径最小的二叉树称为哈夫曼树
//怎样构造哈夫曼树：
//（1）在节点集合F中选取根节点的权值最小的两颗二叉树作为左右子树，构造一棵新的二叉树，并设置二叉树的根节点的权值为其左右子树根节点的权值之和
//（2）F中删除这两棵二叉树，并将新的二叉树加入F中
//（3）重复12，直到F只含有一棵二叉树
//哈夫曼树属于完全二叉树，若叶节点为n,节点总数为2n-1，构造采用贪心算法，采用小根堆存储
const int maxn = 20000 + 10;//堆容量
long n, len;//目标木板数，堆长
long long p[maxn];//堆
void heap_insert(long long k) {
	long t = ++len;
	p[t] = k;
	while (t > 1) {
		if (p[t / 2] > p[t]) {
			swap(p[t / 2], p[t]);
			t /= 2;
		}
		else
			break;
	}
}
void heap_pop() {
	long t = 1;
	p[t] = p[len--];//堆尾移至队首
	while (t * 2 <= len) {
		long k = t * 2;
		if (k<len&&p[k]>p[k + 1])//存在右子树，且左子树大
		{
			++k;
		}
		if (p[t] > p[k]) {
			swap(p[t], p[k]);
			t = k;
		}
		else
		{
			break;
		}
	}
}
int main() {
	cin >> n;
	for (long i = 1;i <= n;++i) {
		cin >> p[i];
	}
	len = 0;
	for (long i = 1;i <= n;++i) {
		heap_insert(p[i]);
	}
	long long ans = 0;
	while (len > 1) {//构造哈夫曼树
		long long a, b;
		a = p[1];//取堆首指针
		heap_pop();
		b = p[1];
		heap_pop();
		ans += a * b;
		heap_insert(a + b);
	}
	cout << ans << endl;
}