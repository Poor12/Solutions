int main()
{
    int i = 0, sum = 0, a[100];
    char str[10015], pinyin[10][6] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
    scanf("%s", str);
    while (str[i])
    {
        sum += str[i] - '0';
        i++;
    }
    i = 0;
    while (sum > 0)
    {
        a[i] = sum % 10;
        sum /= 10;
        i++;
    }
    for (int j = i - 1;j > 0;j--)
    {
        printf("%s ", pinyin[a[j]]);
    }
    printf("%s", pinyin[a[0]]);
    return 0;
}