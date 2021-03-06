//数组-日期计算 贪心
const string Week[] = { "Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday" };
int days_of_year(int year) {
	if (year % 100 == 0)
		return year % 400==0 ? 366 : 365;
	return year % 4 ? 366 : 365;
}
int days_of_month(int month, int year) {
	if (month == 2)
		return days_of_year(year) == 366 ? 29 : 28;
	int d;
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		d = 31;
		break;
	default:
		d = 30;
		break;
	}
	return d;
}
int main()
{
	int n;
	cin >> n;
	while (n>=0)
	{
		int year, month, day, week;
		week = n % 7;
		year = 2000;
		month = 1;
		day = 1;
		while (n)
		{
			if (n >= days_of_year(year)) {
				n -= days_of_year(year);
				year++;
			}
			else if (n >= days_of_month(month, year)) {
				n -= days_of_month(month, year);
				month++;
			}
			else
			{
				//day++;
				//n--;
				day += n;
				n = 0;
			}
		}
		cout << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day << " " << Week[week] << endl;
		cin >> n;
	}
}