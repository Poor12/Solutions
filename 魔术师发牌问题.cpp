#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
using namespace std;
/************魔术师发牌问题****************/

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
	int n = 13, i,j;
	int k = 3;
	for (i = 1;i <= n;i++)       //尾插法建立链表
	{
		s = new node;
		s->data = 0;
		r->next = s;
		r = s;
	}
	r->next = L->next;       //让最后一个结点指向第一个有数据结点
	node *p;
	p = L->next;
	//delete L;   //删除第一个空的结点
	
	p->data = 1;
	for (i = 2;i < 14;++i) {
		for (j = 0;j < i;++j) {
			p = p->next;
			if (p->data != 0)
				j--;
		}
		p->data = i;
	}
	p = L->next;
	for (int i = 0;i < 13;++i) {
		cout << p->data << "->";
		p = p->next;
	}
	//cout << p->data << endl;
	return 0;
}