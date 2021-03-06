#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
using namespace std;
/************约瑟夫问题****************/

typedef struct CLinkList
{
	int data;
	struct CLinkList *next;
}node;


int main()
{
	///建立循环链表
	node *L, *r, *s;
	L = new node;
	r = L;
	int n = 41, i;
	int k = 3;
	for (i = 1;i <= n;i++)       //尾插法建立链表
	{
		s = new node;
		s->data = i;
		r->next = s;
		r = s;
	}
	r->next = L->next;       //让最后一个结点指向第一个有数据结点
	node *p;
	p = L->next;
	delete L;   //删除第一个空的结点

///模拟解决约瑟夫问题
	while (p->next != p)                            //判断条件：因为最后肯定剩下一个人， 循环链表的最后一个数据的next还是他本身
	{
		for (i = 1;i < k - 1;i++)
		{
			p = p->next;                         //每k个数死一个人
		}
		cout << p->next->data << "->";
		p->next = p->next->next;                   //将该节点从链表上删除。
		p = p->next;
	}
	cout << p->data << endl;
	return 0;
}
/* 公式法
#include<iostream>

using namespace std;

///推导公式方法
int yuesefu(int n, int m) {
	if (n == 1) {
		return 0; //这里返回下标,从0开始，只有一个元素就是剩余的元素0
	}
	else {
		return (yuesefu(n - 1, m) + m) % n; //我们传入的n是总共多少个数
	}
}
int main(void) {

	int a = 41, b = 3;
	//递归求最后一个存活的编号
	//使用从正向思考
	cout << "最后一个人是" << yuesefu(a, b) + 1 << endl;

	//反向思考，从自杀的最后一人向前
	int result = 2;
	//第一个自杀的人3号
	cout << 3;
	//每次自杀的都是2号，但是不同的2号换算到最初序号所需的的次数是不同的
	//外循环是循环不同的换算次数
	for (int i = a; i >= 2; i--)
	{
		result = 2;
		//内循环是开始换算
		for (int j = i; j <= a; j++)
		{
			result = (result + b) % j;
		}
		cout << "->" << result + 1;//0开始变1开始，所以加1
	}
	return 0;
}

*/