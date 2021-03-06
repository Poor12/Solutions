//数组-高精度运算
/*数的表示
	int a[100]={0};
	int n;
	string s;
	cin>>s;
	n=s.length();
	for(i=0;i<n;++i){
		a[i]=s[n-i-1]-'0';

	数的基本运算
		加法考虑进位
		for(i=0;i<(n1>n2?n1:n2);++i){
			a[i]=a[i]+b[i];
			if(a[i]>9){
				a[i]=a[i]-10;
				a[i+1]++;
			}
		减法考虑借位(x>y)
		for(i=0;i<n;++i){
			if(a[i]>=b[i])
				a[i]=a[i]-b[i];
			else{
				a[i]=a[i]+10-b[i];
				a[i+1]--;
			}
		}
		乘法
		for(i=0;i<=la-1;++i)
			for(j=0;j<lb-1;j++)
				c[i+j]+=a[i]*b[j];
		for(i=0;i<la+lb;++i)
			if(c[i]>=10)
			{
				c[i+1]+=c[i]/10;
				c[i]%=10;
			}
对于求解高精度正整数a/b的商与余数，如果a<b，则商为0，余数为a；否则基于高精度正整数的减法开始整除。根据a和b的位数差d1看a能够减b*10^d1的次数a1，得到余数y1=a-a1*b*10^d1;然后计算y1的和b的位数差d2，.....以此类推y（k-1）够减的次数ak为止，最后得到余数y=y（k-1）-ak*b，a1（）a2...（）ak即为商
（）表示若di-d（i+1)>1,则a（i+1）前须补di-d（i+1）-1个0，2<=i<=k-1)
例如a=12345，b=12，位数之差d1=3，则12345-12000=345，a1=1，y1=345；345-120*2=105，a2=2，y2=105；105-12*8=9，a3=8，y2=9，余数为9，商为1028
*/
int num[3][1000];
void read(int ord) {
	int flag = 0;
	string tmp;
	cin >> tmp;
	for (int i = tmp.length() - 1;i >= 0;--i) {
		if (tmp[i] > '0')
			flag = 1;
		if (flag)
			num[ord][++num[ord][0]] = tmp[i] - '0';
	}
	for (int i = num[ord][0], j = 1;i >= j;i--, j++) {
		flag = num[ord][i];
		num[ord][i] = num[ord][j];
		num[ord][j] = flag;
	}
}
void add() {
	num[2][0] = max(num[0][0], num[1][0]);
	for (int i = 1;i <= num[2][0];++i) {
		num[2][i] = num[0][i] + num[1][i];
	}
	for (int i = 1;i <= num[2][0];++i) 
		if (num[2][i] > 9) {
			num[2][i] -= 10;
			num[2][i + 1]++;
	}
	//for (int i = 1;i <= num[2][0];++i)
	//{
	//	num[2][i + 1] += num[2][i] / 10;
	//	num[2][i] %= 10;
	//}
	if (num[2][num[2][0] + 1] > 0)
		num[2][0]++;
	int flag = 0;
	for (int i = 1;i <= num[2][0];++i) {
		if (num[2][i] != 0)
			flag = 1;
		if (flag)
			cout << num[2][i];
	}
	cout << "\n";
}
int main() {
	int N;
	cin >> N;
	for (N;N;N--) {
		memset(num, 0, sizeof(num));//tip
		read(0);
		read(1);
		add();
	}
	return 0;
}
