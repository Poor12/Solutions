//数组-二维矩阵
typedef struct { int mults;int rows;int cols; } triple;//定义相乘数，矩阵行数rows，矩阵列数cols
int rows[256], cols[256];
char e[100];//字符数组
int p;//e的字符指针
char error;//出错标志
triple expression()//计算表达式e对应的乘积矩阵
{
	triple t;
	if (e[p] == '(') {
		triple t1, t2;
		p++;
		t1 = expression();
		t2 = expression();
		p++;//跳过）
		if (t1.cols != t2.rows) error = 1;
		t.rows = t1.rows;
		t.cols = t2.cols;
		t.mults = t1.mults + t2.mults + t1.rows*t1.cols*t2.cols;
	}
	else
	{
		t.rows = rows[e[p]];
		t.cols = cols[e[p]];
		t.mults = 0;
		p++;
	}
	return t;
}
int main() {
	FILE *input = fopen("matrix.in", "r");
	char c;
	int i, n, ro, co;
	triple t;
	fscanf(input, "%d%c", &n, &c);//读矩阵个数
	for (i = 0;i < n;++i) {//读矩阵
		fgets(e, 99, input);//读入一行送入缓冲
		sscanf(e, "%c%d %d", &c, &ro, &co);
		rows[c] = ro;
		cols[c] = co;
	}
	while (1)
	{
		fgets(e, 99, input);//只能读取98个字符，99个字符是换行符
		if (feof(input)) break;//若读至结束标志，退出循环
		p = error = 0;
		t = expression();
		if (error) puts("error");
		else printf("%d\n", t.mults);
	}
	fclose(input);
	return 0;
}