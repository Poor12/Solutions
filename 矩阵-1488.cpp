//字符串存储
const char p[][5] = { "``","''" };//字符数组
int main() {
	int k = 0;
	char c;
	while ((c==getchar())!=EOF)
	{
		if (c == '"') {
			printf("%s", p[k]);
			k = !k;
		}
		else
			putchar(c);
	}
	return 0;
}