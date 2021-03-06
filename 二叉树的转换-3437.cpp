//树的度为子树个数，叶子节点的度为0，一个度为k的有序树存在n(k-1)+1个空链域，转化为二叉树后空链域减少为n+1
//普通有序树转换为二叉树，要求转换前后节点数与序号不变，且转换前后先序和后序遍历序列相同
//转换规则：
//（1）T与T’节点对应序号与值不变
//（2）T中某节点v的第一个儿子节点为v1，则T'中v1为对应v的左儿子
//（3）T中节点v的儿子序列，在T’中被依次链接成一条开始于v1的右链。
//因此一棵有序树转化为二叉树的根节点是没有右子树的，并且除保留每个节点的最左分支外，其他分支应去掉，然后从最左儿子开始沿右儿子方向链接该节点的全部儿子，即为左子女右兄弟表示法
//该方法可以将森林转化为二叉树，先将每棵有序树转化为二叉树，然后从第一棵树的根出发，沿右儿子方向依次链接各棵树的根
//二叉树还原为森林略
//本题的求解关键在于求每个节点的层数，对于转换后的树，level2(x)=level2(y)+在数转换前作为孩子的序号
#include <string>
string s;//先根遍历的字符串
int i, height1, height2, n = 0;//i为字符指针
void work(int level1,int level2) {//转换前的树高，转换后的树高
	int tempson = 0;//当前节点儿子数
	while (s[i] == 'd') {
		i++;
		tempson++;//字符为d，增加一个儿子+
		work(level1 + 1, level2 + tempson);
	}
	height1 = level1 > height1 ? level1 : height1;
	height2 = level2 > height2 ? level2 : height2;
	i++;
}
int main() {
	while (cin>>s&&s!="#")
	{
		i = height1 = height2 = 0;
		work(0, 0);
		cout << "Tree " << ++n << ": " << height1 << " => " << height2 << endl;
	}
}