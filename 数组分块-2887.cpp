//数组的增删元素或者计算制定子区间的最值
/*数组分块技术
	将长度为n的数组等分成若干块，以块为单位进行块间检索，由于块容量L取决与原数组长度n和插入操作的次数p，n和p越大，则L越大
	一般来说，数组可分为m=根号（n+p）块，每块长度L=m+1
	我们可在输入数组的同时直接构造块数组，下标x的数组元素x/L个块的第x%L个位置。如果求区间的最值，则需要同时计算每块的最值。构造块数组的时间复杂度为O（n）
	每次插入或删除一个元素，先找到对应的块，再用O（1）时间在该块中进行插入或删除，每块采用动态数组，实际块长可随增删而变化。
	如果求下标区间[x,y]的最值，则直接计算下标x和y的块（时间复杂度为O（1））；若[x,y]同属一块，则需要通过逐一比较计算[x,y]的最值；若下标x和下标y分属不同的块，则需要逐一比较以x为左端的块内元素，计算首块内属于区间元素的最值；逐一比较以y为右端的块内元素,计算尾块内属于区间元素的最值，至于中间跨越的块，直接取出这些块的最值，直接比较这些最值即可，时间复杂度为O（L）。

*/
#include <stdio.h>
#define ll long long
int maxn, N;
int sum[1005];//前i块的总长度为sum[i]
struct BlockList
{
	int size;//块长
	char dat[2005];//块内字符串dat[]
	int at(int pos) {//返回对应位置的字符
		return dat[pos];
	}
	void insert(int pos, char c) {//将字符c插入pos的位置
		for (int i = ++size;i > pos;--i)
		{
			dat[i] = dat[i - 1];
		}
		dat[pos] = c;
	}
	void push_back(char c) {//插入串尾
		dat[++size] = c;
	}
};
BlockList block[1005];
char query(int s, int p) {//返回s块中第p个字符
	return block[s].at(p);
}
void insert(int s, int p, char c) {//将字符c插入s块的p位置前
	p = min(p, block[s].size + 1);
	block[s].insert(p, c);
}
void maintain() {
	for (int i = 1;i <= maxn;++i)
		sum[i] = sum[i - 1] + block[i].size;
}
void myinsert(int pos, char c) {
	int p = lower_bound(sum + 1, sum + 1 + maxn, pos) - (sum);//返回在[sum+1，sum+1+maxn)的大于等于pos的索引
	insert(p, pos - sum[p - 1], c);
	maintain();
}
int myquery(int pos) {
	int p = lower_bound(sum + 1, sum + 1 + maxn, pos) - (sum);
	return query(p, pos - sum[p - 1]);
}
char str[1000005];
void init() {
	int len = strlen(str) + N;
	maxn = sqrt(len*1.0) +1;//计算块数，块长(块数等于块长）
	for (int i = 0;str[i];++i)
		block[i / maxn + 1].push_back(str[i]);
	maintain();
}
int main() {
	scanf("%s", str);
	int pos;
	char p[3], s[3];
	scanf("%d", &N);
	init();
	while (N--)
	{
		scanf("%s", p);
		if (p[0] == 'I') {
			scanf("%s%d", s, &pos);
			myinsert(pos, s[0]);
		}
		else
		{
			scanf("%d", &pos);
			printf("%c\n", myquery(pos));
		}
	}
	return 0;
}