//贪心算法 局部最优
//存在问题：1.不能保证最后的解是最优的。2.不能用来求最大/最小解问题。3.只能用来求满足某些约束调节的可行解
//基本过程：从问题的某一初始解出发，while能向给定总目标前进一步，求出可行解的一个解元素，由所有解元素组成问题的一个可行解
//装箱问题：有编号分别为0...n-1的n种物品，体积分别为V0...Vn-1，将这些物品装到容量为V的若干箱子，约定这n种的体积均不超过V，给出使用最少箱子的装法
#define n 6
#define v 100
typedef struct box
{
	int no;
	int size;
	struct box* next;
}BOX;
void init_list(BOX** h)
{
	*h = (BOX*)malloc(sizeof(BOX));
	(*h)->no = 0;
	(*h)->size = 0;
	(*h)->next = NULL;
}
BOX* find_p(BOX* h, int volume, int vv)
{
	BOX* p = h->next;
	while (p!=NULL)
	{
		if (p->size + volume <= vv)
			break;
		p = p->next;
	}
	return p;
}
void add_list_tail(BOX* h, BOX* p)
{
	BOX* tmp = h->next;
	BOX* q = h;
	while (tmp!=NULL)
	{
		q = tmp;
		tmp = tmp->next;
	}
	q->next = p;
}
void print_list(BOX* h)
{
	BOX* p = h->next;
	while (p)
	{
		printf("%d:%d\n", p->no, p->size);
		p = p->next;
	}
}
int add_box(int volume[], int vv)
{
	int count = 0;
	int i;
	BOX* h = NULL;
	init_list(&h);
	for (i = 0;i < n;++i)
	{
		BOX* p = find_p(h, volume[i], vv);
		if (p == NULL)
		{
			count++;
			p = (BOX*)malloc(sizeof(BOX));
			p->no = count;
			p->size = volume[i];
			p->next = NULL;
			add_list_tail(h, p);
		}
		else
		{
			p->size += volume[i];
		}
	}
	print_list(h);
	return count;
}
int main()
{
	int ret;
	int volumes[] = { 60,45,35,20,20,20 };
	ret = add_box(volumes, v);
	printf("%d\n", ret);
	return 0;
}