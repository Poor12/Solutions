//用加减乘除四个运算符和5个数字5进行运算，使运算结果为5
int main() {
	int j, i[5];//j表示循环变量，i表示运算符
	int sign;
	int result;//运算结果
	int count = 0;//计数器
	int num[6];//保存操作数
	float left, right;//保存中间结果
	char oper[5] = { ' ','+','-','*','/' };//运算符
	printf("输入5个数，之间用空格隔开: ");
	for (j = 1;j <= 5;++j)
	{
		scanf("%d", &num[j]);
	}
	printf("输入结果：");
	scanf("%d", &result);
	for (i[1] = 1;i[1] <= 4;i[1]++)
	{
		if (i[1] < 4 || num[2] != 0)
		{
			for (i[2] = 1;i[2] <= 4;i[2]++)
			{
				if (i[2] < 4 || num[3] != 0)
				{
					for (i[3] = 1;i[3] <= 4;i[3]++)
					{
						if (i[3] < 4 || num[4])
						{
							for (i[4] = 1;i[4] <= 4;i[4]++)
							{
								if (i[4] < 4 || num[5])
								{
									left = 0;
									right = num[1];
									sign = 1;
									for (j = 1;j <= 4;++j)
									{
										switch (oper[i[j]])
										{
										case '+':left = left + sign * right;sign = 1;right = num[j + 1];break;
										case '-':left = left + sign * right;sign = -1;right = num[j + 1];break;
										case '*':right = right * num[j + 1];break;
										case '/':right = right / num[j + 1];break;

										}
									}
									if (left + sign * right == result)
									{
										count++;
										printf("%3d: ", count);
										for (j = 1;j <= 4;++j)
											printf("%d%c", num[j], oper[i[j]]);
										printf("%d=%d\n", num[5], result);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (count == 0)
		printf("error\n");
	return 0;
}