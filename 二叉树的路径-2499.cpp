//计算二叉树路径，即根至树中任意一点的一条路，一般情况下需要置节点的父节点。
//如果二叉树为一棵节点数为n的完全二叉树（从0开始标号），则任意分支节点i的双亲为节点（i-1）/2，若节点i有左儿子（2i+1<=n-1），则左儿子为2i+1;若节点有右儿子（2i+2<=n-1）则右儿子为节点2i+2
//如果节点i为偶数且i！=0，则节点i的左兄弟为i-1；如果节点i为奇数，且i！=n-1，则节点i的右兄弟为i+1
//节点i所在的层次为log(i+1),则路径长度也为此
//本题容易根据两数的大小判断它是左孩子还是右孩子，可以采用贪心策略，若a>b,则左走(a-1)/b步，每走一步左参数-b，同理右走
int main() {
	int sc;
	cin >> sc;
	for (int s = 1;s <= sc;++s) {
		cout << "scenario #" << s << ":" << endl;
		int a, b;
		cin >> a >> b;
		int left = 0, right = 0;
		while (a>1||b>1)
		{
			if (a > b) {
				int up = (a - 1) / b;
				left += up;
				a -= up * b;
			}
			else
			{
				int up = (b - 1) / a;
				right += up;
				b -= up * a;
			}
		}
		cout << left << " " << right << endl;
	}
}