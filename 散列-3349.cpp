//散列表
//判断相同的条件是从任何一翼出发顺时针和逆时针得到的序列相同
#include <algorithm>
const int N = 1200010;//雪花数的上限
const int H = 1200007;//散列表的上限
struct node
{
	int num[6];
	int next;
};
node n[N];
int cur;//雪花指针
int hashtable[H];//将相同哈希值的节点串成链
void inithash() {//散列表为空
	cur = 0;
	for (int i = 0;i < H;++i)
		hashtable[i] = -1;
}
bool cmp(int *num1, int *num2) {
	for (int i = 0;i < 6;++i) {
		if (num1[i] != num2[i])
			return false;
	}
	return true;
}
unsigned int gethash(int *num) {//雪花长度和的散列
	unsigned int hash = 0;
	for (int i = 0;i < 6;++i) hash += num[i];
	return hash % H;
}
void inserthash(int *num, unsigned int h) {//将雪花num插入以hashtable[h]为首指针的散列链首部
	for (int i = 0;i < 6;++i) {
		n[cur].num[i] = num[i];
	}
	n[cur].next = hashtable[h];//h为gethash
	hashtable[h] = cur;
	++cur;
}
bool searchhash(int *num) {
	unsigned h = gethash(num);
	int next = hashtable[h];
	while (next!=-1)
	{
		if (cmp(num, n[next].num))
			return true;
		next = n[next].next;
	}
	inserthash(num, h);
	return false;
}

int main() {
	int num[2][12];//顺时针序列与逆时针序列
	int n;
	bool twin = false;
	inithash();
	scanf("%d", &n);
	while (n--)
	{
		for (int i = 0;i < 6;++i)//输入当前六翼的长度
		{
			scanf("%d", &num[0][i]);
			num[0][i + 6] = num[0][i];
		}
		if (twin) continue;
		for (int i = 0;i < 6;++i) {//逆时针
			num[1][i + 6] = num[1][i] = num[0][5 - i];
		}
		for (int i = 0;i < 6;++i) {
			if (searchhash(num[0] + i) || searchhash(num[1] + i))
			{
				twin = true;
				break;
			}
		}
	}
	if (twin) printf("Twin snowflakes found\n");
	else printf("no two snowflakes are alike\n");
	return 0;
}