//运算符
const int maxn = 100 + 10;
int val[maxn], vtop;//数值栈
int op[maxn], otop;//运算符栈
void insert(int b) {//操作数压入数值值栈
	while (otop&&op[otop - 1] == 3) {//运算符栈顶为！单目
		b = !b;
		--otop;
	}
	val[vtop++] = b;
}
void calc() {//双目运算
	int b = val[--vtop];
	int a = val[--vtop];
	int opr = op[--otop];
	int c;
	if (opr == 2)
		c = (a&b);
	else
		c = (a | b);
	insert(c);
}
int main() {
	int loop = 0;
	char c;
	while ((c=getchar())!=EOF)
	{
		vtop = otop = 0;
		do {
			if (c == '(') {
				op[otop++] = 0;
			}
			else if (c == ')') {
				while (otop&&op[otop-1]!=0)
				{
					calc();
				}
				--otop;
				insert(val[--vtop]);//?
			}
			else if (c == '!') {
				op[otop++] = 3;
			}
			else if (c == '&') {
				while (otop&&op[otop-1]>=2)
				{
					calc();
				}
				op[otop++] = 2;
			}
			else if (c == '|') {
				while (otop&&op[otop-1]>=1)
				{
					calc();
				}
				op[otop++] = 1;
			}
			else if (c == 'V' || c == 'F') {
				insert(c == 'V' ? 1 : 0);
			}
		} while ((c=getchar())!='\n'&&c!=EOF);
		while (otop)
		{
			calc();
		}
		printf("Expression %d: %c\n", ++loop, (val[0] ? 'V' : 'F'));
	}
	return 0;
}