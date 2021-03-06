#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
using namespace std;
/************Vigenere加密法问题****************/

typedef struct CLinkList
{
	int data;
	struct CLinkList *next;
	struct CLinkList *pre;
}node;


int main()
{
	///建立循环链表
	char orig[] = {'y','o','u'};
	char password[] = { 'e','x','c' };
	int key[] = { 6,9,8};
	node *L, *r, *s;
	L = new node;
	r = L;
	int n = 26, i,j;
	for (i = 1;i <= n;i++)       //尾插法建立链表
	{
		s = new node;
		s->data = i;
		s->pre = r;
		r->next = s;
		r = s;
	}
	r->next = L->next;  
	L->next->pre = r;//让最后一个结点指向第一个有数据结点
	node *p;
	p = L->next;
	delete L;   //删除第一个空的结点
	
	node *q = p;
	for (int i = 0;i < 3;++i) {
		p = q;
		for (int k = 0;k < orig[i] - 'a';++k)
			p = p->next;
		for (int j = 0;j < key[i];++j) {
			p = p->next;
		}
		cout <<char(p->data+96)<<' ';
	}
	cout << endl;
	for (int i = 0;i < 3;++i) {
		p = q;
		for (int k = 0;k < password[i] - 'a';++k)
			p = p->next;
		for (int j = 0;j < key[i];++j) {
			p = p->pre;
		}
		cout << char(p->data + 96) << ' ';
	}
	return 0;
}
