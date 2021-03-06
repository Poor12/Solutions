//数组-二维矩阵
#define maxn 512
int n;
int a[maxn][maxn], row[maxn], col[maxn];
FILE *input;
int read_case() {
	int i, j;
	fscanf(input, "%d", &n);
	if (n == 0) return 0;
	for (int i = 0;i < n;++i)
		for (int j = 0;j < n;++j)
			fscanf(input, "%d", &a[i][j]);
	return 1;
}
void show_case() {
	int cc, cr, i, j, k;
	for (int i = 0;i < n;++i) {
		row[i] = col[i] = 0;
	}
	for(int i=0;i<n;++i)
		for (int j = 0;j < n;++j) {
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	cr = cc = 0;
	for (k = 0;k < n;++k) {
		if (row[k] & 1) {
			cr++;//计数
			i = k;
		}
		if (col[k] & 1) {
			cc++;
			j = k;
		}
	}
	if (cr == 0 && cc == 0)
		cout << "OK\n";
	else if (cc == 1 && cr == 1)
		cout << "Change bit (" << i + 1 << "," << j + 1 << ")\n";
	else
		cout << "Corrupt";
}
int main() {
	input = fopen("error.in", "r");
	while (read_case())
	{
		show_case();
	}
	fclose(input);
	return 0;
}
